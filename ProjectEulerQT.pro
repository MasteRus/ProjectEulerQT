# -------------------------------------------------
# Project created by QtCreator 2012-09-13T21:52:14
# -------------------------------------------------

DEPENDPATH += .
INCLUDEPATH += .

QT -= gui
TARGET = ProjectEulerQT
CONFIG += console
#CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    Additional/SomeMathFunc.cpp \
    Additional/Bigint.cpp \
    Proj/ProjEuler200_210.cpp \
    Proj/ProjEuler100_110.cpp \
    Proj/ProjEuler090_099.cpp \
    Proj/ProjEuler080_089.cpp \
    Proj/ProjEuler070_079.cpp \
    Proj/ProjEuler060_069.cpp \
    Proj/ProjEuler050_059.cpp \
    Proj/ProjEuler040_049.cpp \
    Proj/ProjEuler030_039.cpp \
    Proj/ProjEuler020_029.cpp \
    Proj/ProjEuler010_019.cpp \
    Proj/ProjEuler001_009.cpp
OTHER_FILES += Resources/107b.txt \
    Resources/107.txt \
    Resources/102.txt \
    Resources/99.txt \
    Resources/96a.txt \
    Resources/96.txt \
    Resources/81b.txt \
    Resources/81a.txt \
    Resources/79.txt \
    Resources/67.txt \
    Resources/42.txt \
    Resources/22.txt \
    Resources/18.txt \
    Resources/13.txt \
    Resources/11.txt \
    Resources/8.txt
HEADERS += stdafx.h \
    PE.h \
    Additional/SomeMathFunc.h \
    Additional/Bigint.h
