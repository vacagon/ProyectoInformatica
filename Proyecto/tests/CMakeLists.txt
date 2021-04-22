add_executable(test_basic test_basic.cpp)
target_link_libraries(test_basic gtest_main CompuGlobalHyperMegaComponentsLib)
add_test(NAME test_basic COMMAND test_basic)

# Comenta este bloque para ignorar este test
add_executable(test_orders test_orders.cpp)
target_link_libraries(test_orders gtest_main CompuGlobalHyperMegaComponentsLib)
add_test(NAME test_orders COMMAND test_orders)

# Comenta este bloque para ignorar este test
#add_executable(test_files test_files.cpp)
#target_link_libraries(test_files gtest_main CompuGlobalHyperMegaComponentsLib)
#add_test(NAME test_files COMMAND test_files)
