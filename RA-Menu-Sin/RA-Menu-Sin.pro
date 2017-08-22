#-------------------------------------------------
#
# Detector de Rostros con Rotacion
#
#-------------------------------------------------

QT += opengl widgets

unix:DIR_OPENCV_LIBS = /usr/local/lib

unix:INCLUDEPATH += "/usr/include/GL/"                             # OpenGL
unix:LIBS += "/usr/lib/x86_64-linux-gnu/libglut.so"                # OpenGL

unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_core.so         # OpenCV
unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_highgui.so      # OpenCV
unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_imgproc.so      # OpenCV
unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_objdetect.so    # OpenCV
unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_calib3d.so      # OpenCV
unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_ml.so           # OpenCV
#unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_contrib.so     # OpenCV

unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_video.so
unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_features2d.so

unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_flann.so
#unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_gpu.so
#unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_legacy.so
unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_ml.so
#unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_ocl.so
unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_photo.so
unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_stitching.so
unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_superres.so
#unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_ts.so
unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_video.so
unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_videostab.so
unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_imgcodecs.so
unix:LIBS += $$DIR_OPENCV_LIBS/libopencv_videoio.so

unix:LIBS += "/usr/lib/x86_64-linux-gnu/lib3ds.so"                 # Modelos 3D


SOURCES += main.cpp

HEADERS += \
    block.h \
    container.h \
    cameraprocessor.h \
    window.h
