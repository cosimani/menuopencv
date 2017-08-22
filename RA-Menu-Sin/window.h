#ifndef WINDOW_H
#define WINDOW_H

#include <QPushButton>
#include <QGridLayout>
#include "container.h"

class Window : public QWidget
{
    Q_OBJECT

public:

    QImage backgroundImage;
    Container *container;
    QPushButton *calibrateButton;
    QGridLayout *layout;

    Window( int containerRows = 1,
            int containerCols = 1,
            QWidget *parent = 0 ) : QWidget( parent ),
                                    container( new Container( containerRows, containerCols, this ) ),
                                    calibrateButton( new QPushButton( "Calibrar", this ) ),
                                    layout( new QGridLayout( this ) )
    {
        backgroundImage.load( "../Images/Background.jpg" );
        layout->addWidget( container, 0, 0, 1, 1, Qt::AlignCenter );
        layout->addWidget( calibrateButton, 1, 0, 1, 1, Qt::AlignCenter );
        this->setLayout( layout );

        connect( calibrateButton, SIGNAL( clicked() ), SLOT( slot_calibrate() ) );
    }

protected:

    void paintEvent( QPaintEvent * )
    {
        QPainter painter( this );
        if( !backgroundImage.isNull() )
            painter.drawImage( this->width() / 2 - backgroundImage.width() / 2,
                               this->height() / 2 - backgroundImage.height() / 2,
                               backgroundImage );
    }

private slots:

    void slot_calibrate()
    {
        this->container->calibrate();
    }
};

#endif // WINDOW_H
