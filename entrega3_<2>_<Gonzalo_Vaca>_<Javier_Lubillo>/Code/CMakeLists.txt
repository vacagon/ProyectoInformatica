cmake_minimum_required(VERSION 3.5)

project(CompuGlobalHyperMegaComponents LANGUAGES CXX)

# Add debug info
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#====================== GOOGLE_TEST STUFF =========================

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# GENERATE PROGRAM EXECUTABLE WITH CMAKE

add_library(CompuGlobalHyperMegaComponentsLib
    User.hpp User.cpp PublicUserData.hpp PublicUserData.cpp PrivateUserData.hpp PrivateUserData.cpp
    Administrator.hpp Administrator.cpp Address.hpp Address.cpp PaymentMethod.hpp PaymentMethod.cpp
    Order.hpp Order.cpp Manager.hpp Manager.cpp CreditCard.hpp CreditCard.cpp Paypal.hpp Paypal.cpp
    Product.hpp Product.cpp Review.hpp Review.cpp)

add_subdirectory(tests)

add_executable(CompuGlobalHyperMegaComponents Interface.hpp Interface.cpp ShoppingCart.cpp ShoppingCart.hpp main.cpp)

target_link_libraries(CompuGlobalHyperMegaComponents CompuGlobalHyperMegaComponentsLib)
