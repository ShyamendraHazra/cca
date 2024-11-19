cmake_minimum_required(VERSION 3.20.0)

set(PROJECT_NAME "CCA")

project(${PROJECT_NAME} LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

get_filename_component(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)



set(SOURCE_DIR "${PROJECT_ROOT}/Source Files/")
set(HEADER_DIR "${PROJECT_ROOT}/Header Files/")
set(CMAKE_BINARY_OUTPUT_DIR "${PROJECT_ROOT}/bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/exec/${CMAKE_SYSTEM_NAME}/")

file(GLOB_RECURSE SOURCES "${SOURCE_DIR}*.cc")

# Assemblly generation

# Create the assembly output directory
# Define assembly output directory at the start if not defined yet
set(ASSEMBLY_DIR "${CMAKE_BINARY_OUTPUT_DIR}/asm")

file(MAKE_DIRECTORY ${ASSEMBLY_DIR})

# Loop over each source file to generate its corresponding .s file
foreach(SOURCE_FILE IN LISTS SOURCES)
    # Get the filename without directory and extension
    get_filename_component(FILENAME ${SOURCE_FILE} NAME_WE)

    # Define the output .s file path inside ASSEMBLY_DIR
    set(ASSEMBLY_FILE "${ASSEMBLY_DIR}/${FILENAME}.s")
    
    # Add to assembly file list
    list(APPEND ASSEMBLY_FILES ${ASSEMBLY_FILE})

    # Custom command to generate the .s file from the .cc file with include paths
    add_custom_command(
        OUTPUT ${ASSEMBLY_FILE}
        COMMAND ${CMAKE_CXX_COMPILER} -S ${SOURCE_FILE} -o ${ASSEMBLY_FILE}
                -I${HEADER_DIR} # Add more -I paths as necessary
        DEPENDS ${SOURCE_FILE}
        COMMENT "Generating assembly for ${SOURCE_FILE} -> ${ASSEMBLY_FILE}"
    )
endforeach()


# Add a custom target that depends on all generated .s files
add_custom_target(assembly ALL DEPENDS ${ASSEMBLY_FILES})

# Assemblly generation


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