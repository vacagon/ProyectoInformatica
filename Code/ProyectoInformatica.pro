TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Address.cpp \
        Administrator.cpp \
        Order.cpp \
        PaymentMethod.cpp \
        PrivateUserData.cpp \
        PublicUserData.cpp \
        User.cpp \
        main.cpp

HEADERS += \
        Address.hpp \
        Administrator.hpp \
        Order.hpp \
        PaymentMethod.hpp \
        PrivateUserData.hpp \
        PublicUserData.hpp \
        User.hpp
