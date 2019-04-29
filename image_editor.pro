#-------------------------------------------------
#
# Project created by QtCreator 2018-04-29T14:06:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = image_editor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES *= $$PWD/*.cpp
SOURCES *= $$PWD/src/*.cpp

HEADERS *= $$PWD/src/*.h
HEADERS *= $$PWD/src/*.hpp
HEADERS *= $$PWD/*.h


FORMS += \
    hellowindow.ui \
    developwindow.ui

DISTFILES += \
    res/images/building.JPG \
    res/images/picture-of-kitten.jpg \
    res/images/wency2.jpg

HEADERS *= $$PWD/lib/3.4.1_2/include/opencv/*.h
HEADERS *= $$PWD/lib/3.4.1_2/include/opencv/*.hpp
HEADERS *= $$PWD/lib/3.4.1_2/include/opencv2/*.h
HEADERS *= $$PWD/lib/3.4.1_2/include/opencv2/*.hpp

INCLUDEPATH *= $$PWD/src/

INCLUDEPATH *= $$PWD/
INCLUDEPATH *= $$PWD/lib/3.4.1_2/
INCLUDEPATH *= $$PWD/lib/3.4.1_2/include/
INCLUDEPATH *= $$PWD/lib/3.4.1_2/include/opencv/
INCLUDEPATH *= $$PWD/lib/3.4.1_2/include/opencv2/
INCLUDEPATH *= $$PWD/lib/3.4.1_2/include/opencv2/*/

INCLUDEPATH += /usr/local/include
INCLUDEPATH += /usr/local/include/opencv
INCLUDEPATH += /usr/local/include/opencv2

macx{

#INCLUDEPATH *= C:/opencv-build/install/x86/mingw/bin/
LIBS += -L/usr/local/lib \
     -lopencv_core \
     -lopencv_highgui \
     -lopencv_imgproc \
     -lopencv_imgcodecs \

}

win32{
LIBS += -L C:/opencv-build/install/x86/mingw/bin \
     -lopencv_calib3d341 \
     -lopencv_core341 \
     -lopencv_dnn341 \
     -lopencv_features2d341 \
     -lopencv_flann341 \
     -lopencv_highgui341 \
     -lopencv_imgcodecs341 \
     -lopencv_imgproc341 \
     -lopencv_ml341 \
     -lopencv_objdetect341 \
     -lopencv_photo341 \
     -lopencv_shape341 \
     -lopencv_stitching341 \
     -lopencv_superres341 \
     -lopencv_video341 \
     -lopencv_videoio341 \
     -lopencv_videostab341 \
     -lopencv_aruco \
     -lopencv_bgsegm \
     -lopencv_bioinspired \
     -lopencv_ccalib \
     -lopencv_datasets \
     -lopencv_dnn_objdetect \
     -lopencv_dpm \
     -lopencv_face \
     -lopencv_fuzzy \
     -lopencv_hfs \
     -lopencv_img_hash\
     -lopencv_imgcodecs \
     -lopencv_imgproc\
     -lopencv_line_descriptor \
     -lopencv_optflow \
     -lopencv_phase_unwrapping \
     -lopencv_reg \
     -lopencv_rgbd \
     -lopencv_saliency \
     -lopencv_stereo \
     -lopencv_structured_light \
     -lopencv_surface_matching \
     -lopencv_text \
     -lopencv_tracking \
     -lopencv_xfeatures2d \
     -lopencv_ximgproc \
     -lopencv_xobjdetect \
     -lopencv_xphoto \
     -lopencv_plot \
}
RESOURCES += \
    bgimage.qrc

