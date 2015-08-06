#-------------------------------------------------
#
# Detector de Rostros con Rotacion
#
#-------------------------------------------------

QT += opengl widgets

unix:INCLUDEPATH += "/usr/include/GL/"                          # OpenGL
unix:LIBS += "/usr/lib/x86_64-linux-gnu/libglut.so"               # OpenGL

unix:LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_core.so"        # OpenCV
unix:LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_highgui.so"     # OpenCV
unix:LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_imgproc.so"     # OpenCV
unix:LIBS += "/usr/lib/x86_64-linux-gnu/libopencv_objdetect.so"   # OpenCV

SOURCES += main.cpp

HEADERS += \
    block.h \
    container.h \
    cameraprocessor.h \
    window.h
