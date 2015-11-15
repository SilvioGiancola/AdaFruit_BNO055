#-------------------------------------------------
#
# Project created by QtCreator 2015-11-12T21:33:02
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AdaFruit_BNO055
TEMPLATE = app


SOURCES +=  mainwindow.cpp

HEADERS  += mainwindow.h \
    adafruit_uart.h

FORMS    += mainwindow.ui



#################
# LIB PCL
#################
# find lib of PCL 1.8 for release
win32:CONFIG(release, debug|release): LIBS += -L"C://Program Files//PCL//lib//" \
-lpcl_common_release -lpcl_features_release -lpcl_filters_release -lpcl_io_release -lpcl_io_ply_release -lpcl_kdtree_release -lpcl_keypoints_release \
-lpcl_ml_release -lpcl_octree_release -lpcl_outofcore_release -lpcl_people_release -lpcl_recognition_release -lpcl_registration_release \
-lpcl_sample_consensus_release -lpcl_search_release -lpcl_segmentation_release -lpcl_stereo_release -lpcl_surface_release -lpcl_tracking_release \
-lpcl_visualization_release
# and for debug
else:win32:CONFIG(debug, debug|release): LIBS += -L"C://Program Files//PCL//lib//" \
-lpcl_common_debug -lpcl_features_debug -lpcl_filters_debug -lpcl_io_debug -lpcl_io_ply_debug -lpcl_kdtree_debug -lpcl_keypoints_debug -lpcl_ml_debug \
-lpcl_octree_debug -lpcl_outofcore_debug -lpcl_people_debug -lpcl_recognition_debug -lpcl_registration_debug -lpcl_sample_consensus_debug \
-lpcl_search_debug -lpcl_segmentation_debug -lpcl_stereo_debug -lpcl_surface_debug -lpcl_tracking_debug -lpcl_visualization_debug
#for linux
else:unix: LIBS += -L/usr/local/lib/ \
-lpcl_common -lpcl_features -lpcl_filters -lpcl_io -lpcl_io_ply -lpcl_kdtree -lpcl_keypoints -lpcl_ml \
-lpcl_octree -lpcl_outofcore -lpcl_people -lpcl_recognition -lpcl_registration -lpcl_sample_consensus \
-lpcl_search -lpcl_segmentation -lpcl_stereo -lpcl_surface -lpcl_tracking -lpcl_visualization \
-lpcl_gpu_containers -lpcl_gpu_features -lpcl_gpu_utils -lpcl_cuda_features -lpcl_gpu_octree -lpcl_gpu_segmentation #\
#-lpcl_gpu_surface -lpcl_gpu_tracking -lpcl_gpu_kinfu -lpcl_gpu_kinfu_large_scale -lpcl_cuda_io

# path dei file header (.h) di PCL
win32:INCLUDEPATH += "C://Program Files//PCL//include//pcl-1.8"
else:unix:INCLUDEPATH += /usr/local/include/pcl-1.8

win32:DEPENDPATH += "C://Program Files//PCL//include//pcl-1.8"
else:unix:INCLUDEPATH += /usr/local/include/pcl-1.8





#################
# LIB Eigen
#################
# Eigen è una libreria "header only" cioè non ci sono .lib, tutto è scritto nel file header
# path dei file header (.h) di Eigen
win32:INCLUDEPATH += "C://Program Files (x86)//Eigen//include"
else:unix:INCLUDEPATH += /usr/include/eigen3
win32:DEPENDPATH += "C://Program Files (x86)//Eigen//include"
else:unix:DEPENDPATH += /usr/include/eigen3



#################
# LIB FLANN
#################
LIBS += -L/usr/lib/ -lflann_cpp
INCLUDEPATH += /usr/include/flann
DEPENDPATH += /usr/include/flann





#################
# LIB Boost
#################
# find lib of Boost 1.56 for release
win32:CONFIG(release, debug|release): LIBS += -L"C://Program Files//Boost//lib//" -llibboost_timer-vc120-mt-1_56 -llibboost_system-vc120-mt-1_56
# and for debug
else:win32:CONFIG(debug, debug|release): LIBS += -L"C://Program Files//Boost//lib//" -llibboost_timer-vc120-mt-gd-1_56 -llibboost_system-vc120-mt-gd-1_56
# for linux
else:unix: LIBS += -L/usr/lib/ -lboost_thread -lboost_system

# path dei file header (.h) di Boost
win32:INCLUDEPATH += "C://Program Files//Boost//include"
else:unix:INCLUDEPATH += /usr/include/boost
win32:DEPENDPATH += "C://Program Files//Boost//include"
else:unix:DEPENDPATH += /usr/include/boost








#################
# LIB VTK
#################
# find lib of VTK 6.1 for release AND debug
win32:LIBS += -L"C://Program Files//VTK//lib//" \
-lvtkChartsCore-6.1 \
-lvtkCommonColor-6.1 \
-lvtkCommonComputationalGeometry-6.1 \
-lvtkCommonCore-6.1 \
-lvtkCommonDataModel-6.1 \
-lvtkCommonExecutionModel-6.1 \
-lvtkCommonMath-6.1 \
-lvtkCommonMisc-6.1 \
-lvtkCommonSystem-6.1 \
-lvtkCommonTransforms-6.1 \
-lvtkDICOMParser-6.1 \
-lvtkDomainsChemistry-6.1 \
-lvtkFiltersAMR-6.1 \
-lvtkFiltersCore-6.1 \
-lvtkFiltersExtraction-6.1 \
-lvtkFiltersFlowPaths-6.1 \
-lvtkFiltersGeneral-6.1 \
-lvtkFiltersGeneric-6.1 \
-lvtkFiltersGeometry-6.1 \
-lvtkFiltersHybrid-6.1 \
-lvtkFiltersHyperTree-6.1 \
-lvtkFiltersImaging-6.1 \
-lvtkFiltersModeling-6.1 \
-lvtkFiltersParallel-6.1 \
-lvtkFiltersParallelImaging-6.1 \
-lvtkFiltersProgrammable-6.1 \
-lvtkFiltersSMP-6.1 \
-lvtkFiltersSelection-6.1 \
-lvtkFiltersSources-6.1 \
-lvtkFiltersStatistics-6.1 \
-lvtkFiltersTexture-6.1 \
-lvtkFiltersVerdict-6.1 \
-lvtkGUISupportQt-6.1 \
-lvtkGUISupportQtOpenGL-6.1 \
-lvtkGUISupportQtSQL-6.1 \
-lvtkGUISupportQtWebkit-6.1 \
-lvtkGeovisCore-6.1 \
-lvtkIOAMR-6.1 \
-lvtkIOCore-6.1 \
-lvtkIOEnSight-6.1 \
-lvtkIOExodus-6.1 \
-lvtkIOExport-6.1 \
-lvtkIOGeometry-6.1 \
-lvtkIOImage-6.1 \
-lvtkIOImport-6.1 \
-lvtkIOInfovis-6.1 \
-lvtkIOLSDyna-6.1 \
-lvtkIOLegacy-6.1 \
-lvtkIOMINC-6.1 \
-lvtkIOMovie-6.1 \
-lvtkIONetCDF-6.1 \
-lvtkIOPLY-6.1 \
-lvtkIOParallel-6.1 \
-lvtkIOSQL-6.1 \
-lvtkIOVideo-6.1 \
-lvtkIOXML-6.1 \
-lvtkIOXMLParser-6.1 \
-lvtkImagingColor-6.1 \
-lvtkImagingCore-6.1 \
-lvtkImagingFourier-6.1 \
-lvtkImagingGeneral-6.1 \
-lvtkImagingHybrid-6.1 \
-lvtkImagingMath-6.1 \
-lvtkImagingMorphological-6.1 \
-lvtkImagingSources-6.1 \
-lvtkImagingStatistics-6.1 \
-lvtkImagingStencil-6.1 \
-lvtkInfovisCore-6.1 \
-lvtkInfovisLayout-6.1 \
-lvtkInteractionImage-6.1 \
-lvtkInteractionStyle-6.1 \
-lvtkInteractionWidgets-6.1 \
-lvtkLocalExample-6.1 \
-lvtkNetCDF-6.1 \
-lvtkNetCDF_cxx-6.1 \
-lvtkParallelCore-6.1 \
-lvtkRenderingAnnotation-6.1 \
-lvtkRenderingContext2D-6.1 \
-lvtkRenderingCore-6.1 \
-lvtkRenderingFreeType-6.1 \
-lvtkRenderingFreeTypeOpenGL-6.1 \
-lvtkRenderingGL2PS-6.1 \
-lvtkRenderingImage-6.1 \
-lvtkRenderingLIC-6.1 \
-lvtkRenderingLOD-6.1 \
-lvtkRenderingLabel-6.1 \
-lvtkRenderingOpenGL-6.1 \
-lvtkRenderingQt-6.1 \
-lvtkRenderingVolume-6.1 \
-lvtkRenderingVolumeAMR-6.1 \
-lvtkRenderingVolumeOpenGL-6.1 \
-lvtkTestingRendering-6.1 \
-lvtkViewsContext2D-6.1 \
-lvtkViewsCore-6.1 \
-lvtkViewsGeovis-6.1 \
-lvtkViewsInfovis-6.1 \
-lvtkViewsQt-6.1 \
-lvtkalglib-6.1 \
-lvtkexoIIc-6.1 \
-lvtkexpat-6.1 \
-lvtkfreetype-6.1 \
-lvtkftgl-6.1 \
-lvtkgl2ps-6.1 \
-lvtkhdf5-6.1 \
-lvtkhdf5_hl-6.1 \
-lvtkjpeg-6.1 \
-lvtkjsoncpp-6.1 \
-lvtklibxml2-6.1 \
-lvtkmetaio-6.1 \
-lvtkoggtheora-6.1 \
-lvtkpng-6.1 \
-lvtkproj4-6.1 \
-lvtksqlite-6.1 \
-lvtksys-6.1 \
-lvtktiff-6.1 \
-lvtkverdict-6.1 \
-lvtkzlib-6.1
else:unix: LIBS += -L/usr/lib/ \
-lvtkCommonDataModel-6.3 \
-lvtkCommonMath-6.3 \
-lvtkCommonCore-6.3 \
-lvtkGUISupportQt-6.3 \
-lvtkRenderingCore-6.3 \
-lvtkRenderingLOD-6.3

# path dei file header (.h) di VTK
win32:INCLUDEPATH += "C://Program Files//VTK//include//vtk-6.1"
win32:DEPENDPATH += "C://Program Files//VTK//include//vtk-6.1"
else:unix:INCLUDEPATH += /usr/local/include/vtk-6.3
else:unix:DEPENDPATH += /usr/local/include/vtk-6.3


