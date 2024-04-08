QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apple.cpp \
    body.cpp \
    customscene.cpp \
    data/scripts/components/musicmanager.cpp \
    data/scripts/components/updater.cpp \
    data/scripts/widgets/button.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    shop.cpp \
    snake.cpp \
    start.cpp \
    tutorial.cpp

HEADERS += \
    apple.h \
    body.h \
    customscene.h \
    data/scripts/components/musicmanager.h \
    data/scripts/components/updater.h \
    data/scripts/widgets/button.h \
    mainmenu.h \
    mainwindow.h \
    shop.h \
    snake.h \
    start.h \
    tutorial.h

FORMS += \
    mainmenu.ui \
    mainwindow.ui \
    shop.ui \
    start.ui \
    tutorial.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    data/assets.qrc
