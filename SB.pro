QT       += core gui xml widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SBFilter.cpp \
    SBScreen/SBInputScreen.cpp \
    SBScreen/SBResultScreen.cpp \
    SBScreen/SBStartScreen.cpp \
    SBTable.cpp \
    SBXMLStreamReader.cpp \
    SearchBug.cpp \
    main.cpp \
    SBGraphic/SBGraphicElement.cpp \
    SBGraphic/SBGraphicFormat.cpp


HEADERS += \
    SBFilter.h \
    SBScreen/SBInputScreen.h \
    SBScreen/SBPallete.h \
    SBScreen/SBResultScreen.h \
    SBScreen/SBGUIState.h \
    SBScreen/SBStartScreen.h \
    SBTable.h \
    SBGraphic/SBGraphicElement.h \
    SBGraphic/SBGraphicFormat.h \
    SBXMLStreamReader.h \
    SearchBug.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resource/Screen1.qrc \
    resource/Screen2.qrc \
    resource/Screen3.qrc
