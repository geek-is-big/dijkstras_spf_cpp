TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        graph.cpp \
        graph_utils.cpp \
        main.cpp \
        shortest_path.cpp

HEADERS += \
    graph.h \
    graph_utils.h \
    shortest_path.h
    