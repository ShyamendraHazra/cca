cmake_minimum_required(VERSION 3.20.0)

set(PROJECT_NAME "CCA")

project(${PROJECT_NAME} LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

get_filename_component(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)



set(SOURCE_DIR "${PROJECT_ROOT}/Source Files/")
set(HEADER_DIR "${PROJECT_ROOT}/Header Files/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_ROOT}/Executables/${CMAKE_SYSTEM_NAME}/")

file(GLOB_RECURSE SOURCES "${SOURCE_DIR}*.cc")



add_executable(${PROJECT_NAME} "${SOURCES}")


if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")

    set(CMAKE_FIND_LIBRARY_SUFFIXES ".dll")

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            /usr/x86_64-w64-mingw32/bin/libssp-0.dll
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            /usr/x86_64-w64-mingw32/bin/libstdc++-6.dll
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
        
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            /usr/x86_64-w64-mingw32/bin/libgcc_s_seh-1.dll
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
        
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            /usr/x86_64-w64-mingw32/bin/libwinpthread-1.dll
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    )
 

else()

    set(CMAKE_CXX_COMPILER /usr/bin/g++)
    target_include_directories(${PROJECT_NAME} PRIVATE "${HEADER_DIR}" "/usr/include/")
    target_link_directories(${PROJECT_NAME} PRIVATE "/usr/bin/")

endif()