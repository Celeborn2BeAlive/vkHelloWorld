cmake_minimum_required(VERSION 3.8)

project(vkHelloWorld)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(Vulkan)

set(EXECUTABLE_NAME vkHelloWorld)

add_executable(
    ${EXECUTABLE_NAME}
    main.cpp
)

target_include_directories(
    ${EXECUTABLE_NAME}
    PUBLIC
    ${Vulkan_INCLUDE_DIR}
)

target_link_libraries(
    ${EXECUTABLE_NAME}
    ${Vulkan_LIBRARY}
)