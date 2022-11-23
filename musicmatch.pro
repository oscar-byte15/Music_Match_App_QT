QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    amigos.cpp \
    login.cpp \
    main.cpp \
    matchusers.cpp \
    musicmatch.cpp \
    newcomentario.cpp \
    newpublicacion.cpp \
    registro.cpp

HEADERS += \
    Avl.h \
    Follower.h \
    Lista_Usuario.h \
    Node_Persona.h \
    Pila_Usuario.h \
    Pila_contenido.h \
    amigos.h \
    comentario.h \
    interaction.h \
    login.h \
    matchusers.h \
    musicmatch.h \
    newcomentario.h \
    newpublicacion.h \
    publicacion.h \
    registro.h

FORMS += \
    amigos.ui \
    login.ui \
    matchusers.ui \
    musicmatch.ui \
    newcomentario.ui \
    newpublicacion.ui \
    registro.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    logo.qrc \
    password.qrc \
    usuario.qrc

DISTFILES +=
