TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Address.cpp \
        Administrator.cpp \
        CreditCard.cpp \
        Manager.cpp \
        Order.cpp \
        PaymentMethod.cpp \
        Paypal.cpp \
        PrivateUserData.cpp \
        Product.cpp \
        PublicUserData.cpp \
        Review.cpp \
        User.cpp \
        main.cpp

HEADERS += \
    Address.hpp \
    Administrator.hpp \
    CreditCard.hpp \
    Manager.hpp \
    Order.hpp \
    PaymentMethod.hpp \
    Paypal.hpp \
    PrivateUserData.hpp \
    Product.hpp \
    PublicUserData.hpp \
    Review.hpp \
    User.hpp
