TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    myclass.cpp \
    settings.cpp

RESOURCES += qml.qrc \
    traduction.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
 include(deployment.pri)

# Setting the application icon
win32: RC_ICONS = icons/gameIcon.ico # On Windows
macx: ICON = # icons/gameIcon.ico # On Mac OSX

HEADERS += \
    myclass.h \
    settings.h

DISTFILES += \
    icons/gameIcon.ico

TRANSLATIONS =    ts/fr_FR.ts

CODECFORSRC   = UTF-8
