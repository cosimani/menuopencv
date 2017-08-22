#ifndef CONTAINER_H
#define CONTAINER_H

#include <QVector>

#include "block.h"
#include "cameraprocessor.h"

class Container : public QWidget
{
    Q_OBJECT

private:

    QGridLayout *layout;
    QVector< QVector < Block * > *> *blocks;

    CameraProcessor *cameraProcessor;
    int activatedBlockX, activatedBlockY;

public:

    Container( int rows = 1, int cols = 1, QWidget *parent = 0 ) :
                                           QWidget( parent ),
                                           layout( new QGridLayout( this ) ),
                                           blocks( new QVector< QVector< Block * > * >( rows ) ),
                                           cameraProcessor( new CameraProcessor( rows, cols ) ),
                                           activatedBlockX( -1 ),
                                           activatedBlockY( -1 )
    {
        for( int i = 0; i < rows; i++ )
            blocks->operator []( i ) = new QVector< Block * >( cols );

        layout->setSpacing( 10 );
        this->setLayout( layout );

        connect( cameraProcessor, SIGNAL( positionDetected( int, int ) ), SLOT( slot_activateCell( int, int ) ) );
        connect( cameraProcessor, SIGNAL( smile() ), SLOT( slot_clickCell() ) );
        connect( cameraProcessor, SIGNAL( notSmile() ), SLOT( slot_releaseCell() ) );
    }

    void setBlock( int row, int col, Block *block )
    {
        blocks->operator []( row )->operator []( col ) = block;
        layout->addWidget( block, row, col );
    }

    void calibrate()
    {
        cameraProcessor->calibrate();
    }

private slots:

    void slot_activateCell( int row, int col )
    {
        if( row < 0 || row >= blocks->at( 0 )->size() ||
            col < 0 || col >= blocks->size() ) return;

        if( row == activatedBlockY && col == activatedBlockX )
        {
            return;
        }
        else
        {
            if( activatedBlockX != -1 && activatedBlockY != -1 )
                blocks->at( activatedBlockX )->at( activatedBlockY )->deactivate();

            blocks->at( col )->at( row )->activate();

            activatedBlockX = col;
            activatedBlockY = row;
        }
    }

    void slot_clickCell()
    {
        blocks->at( activatedBlockX )->at( activatedBlockY )->click();
    }

    void slot_releaseCell()
    {
        blocks->at( activatedBlockX )->at( activatedBlockY )->release();
    }
};

#endif // CONTAINER_H
