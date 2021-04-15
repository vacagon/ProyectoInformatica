
if(NOT "/home/javier/ProyectoInformatica/build-Proyecto-Desktop_Qt_5_15_2_GCC_64bit-Debug/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitinfo.txt" IS_NEWER_THAN "/home/javier/ProyectoInformatica/build-Proyecto-Desktop_Qt_5_15_2_GCC_64bit-Debug/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/home/javier/ProyectoInformatica/build-Proyecto-Desktop_Qt_5_15_2_GCC_64bit-Debug/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/home/javier/ProyectoInformatica/build-Proyecto-Desktop_Qt_5_15_2_GCC_64bit-Debug/googletest-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/javier/ProyectoInformatica/build-Proyecto-Desktop_Qt_5_15_2_GCC_64bit-Debug/googletest-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout "https://github.com/google/googletest.git" "googletest-src"
    WORKING_DIRECTORY "/home/javier/ProyectoInformatica/build-Proyecto-Desktop_Qt_5_15_2_GCC_64bit-Debug"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/google/googletest.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout master --
  WORKING_DIRECTORY "/home/javier/ProyectoInformatica/build-Proyecto-Desktop_Qt_5_15_2_GCC_64bit-Debug/googletest-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'master'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/home/javier/ProyectoInformatica/build-Proyecto-Desktop_Qt_5_15_2_GCC_64bit-Debug/googletest-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/javier/ProyectoInformatica/build-Proyecto-Desktop_Qt_5_15_2_GCC_64bit-Debug/googletest-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/home/javier/ProyectoInformatica/build-Proyecto-Desktop_Qt_5_15_2_GCC_64bit-Debug/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitinfo.txt"
    "/home/javier/ProyectoInformatica/build-Proyecto-Desktop_Qt_5_15_2_GCC_64bit-Debug/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/javier/ProyectoInformatica/build-Proyecto-Desktop_Qt_5_15_2_GCC_64bit-Debug/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitclone-lastrun.txt'")
endif()

