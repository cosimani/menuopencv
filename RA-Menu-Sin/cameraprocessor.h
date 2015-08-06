#ifndef CAMERAPROCESSOR_H
#define CAMERAPROCESSOR_H

#include <QTimer>

#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

class CameraProcessor : public QObject
{
    Q_OBJECT

private:

    VideoCapture *videoCapture;
    QTimer *sceneTimer;
    Mat cameraTexture;
    int rows, cols;

    CascadeClassifier frontalFaceClassifier;
    CascadeClassifier smileClassifier;

    Rect actualFace;
    Rect calibration;

public:

    CameraProcessor( int rows = 1, int cols = 1, QObject *parent = 0 ) :
                                                 QObject( parent ),
                                                 videoCapture ( new cv::VideoCapture( 0 ) ),
                                                 sceneTimer ( new QTimer( this ) ),
                                                 rows( rows ),
                                                 cols( cols )
    {
        frontalFaceClassifier.load( "../Classifiers/FrontalFace.xml" );
        smileClassifier.load( "../Classifiers/Smile.xml" );

        sceneTimer->start( 10 );
        connect( sceneTimer, SIGNAL( timeout() ), SLOT( slot_process() ) );
    }

    void calibrate()
    {
        calibration.x = actualFace.x + actualFace.width / 4;
        calibration.y = actualFace.y + actualFace.height / 4;
        calibration.width = actualFace.width / 2;
        calibration.height = actualFace.height / 2;

        return;
    }

private slots:

    void slot_process()
    {
        videoCapture->operator >>( cameraTexture );
        flip( cameraTexture, cameraTexture, 1 );

        vector< Rect > detectedFaces;
        detectedFaces.clear();

        frontalFaceClassifier.detectMultiScale( cameraTexture, detectedFaces,
                                         1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size( 150, 150 ) );


        if( detectedFaces.size() > 0 )
            actualFace = detectedFaces.at( 0 );

        if( detectedFaces.size() > 0 && rows != 0 && cols != 0 )
        {
            int xFaceCenter = detectedFaces.at( 0 ).x + detectedFaces.at( 0 ).width / 2;
            int yFaceCenter = detectedFaces.at( 0 ).y + detectedFaces.at( 0 ).height / 2;

            if( xFaceCenter < calibration.x ||
                xFaceCenter > calibration.x + calibration.width ||
                yFaceCenter < calibration.y ||
                yFaceCenter > calibration.y + calibration.height ) return;

            int xIndex = ( xFaceCenter - calibration.x ) / ( calibration.width / cols );
            int yIndex = ( yFaceCenter - calibration.y ) / ( calibration.height / rows );

            emit positionDetected( xIndex, yIndex );

            vector< Rect > detectedSmiles;
            detectedSmiles.clear();

            detectedFaces.operator []( 0 ).width -= detectedFaces.operator []( 0 ).width % 3;

            Mat face( cameraTexture, detectedFaces.at( 0 ) );

            smileClassifier.detectMultiScale( face, detectedSmiles,
                                              1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size( 50, 50 ) );

//            if( detectedSmiles.size() > 0 )
//            {
//                emit smile();
//            }
//            else
//            {
//                emit notSmile();
//            }
        }
    }

signals:

    void positionDetected( int x, int y );
    void smile();
    void notSmile();
};

#endif // CAMERAPROCESSOR_H
