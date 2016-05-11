#! [0]
TEMPLATE      = lib
CONFIG       += plugin
QT           += widgets
INCLUDEPATH  += ../..
HEADERS       = factory3.h \
    factory3.h \
    producta3.h \
    productb3.h
SOURCES       = factory3.cpp \
    factory3.cpp \
    producta3.cpp \
    productb3.cpp
TARGET        = $$qtLibraryTarget(factory3)
DESTDIR       = ../../abstractFactoryExample/plugins
#! [0]

message(Qt version: $$[QT_VERSION])
message(Includepath: $$INCLUDEPATH)
message(Destdir: $$DESTDIR)

# install
target.path = C:/Temp/abstractFactoryExample/plugins

INSTALLS += target
