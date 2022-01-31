cmake_minimum_required(VERSION 3.16.3)

PROJECT(trail VERSION 1.0)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cxx)
file(GLOB INCLUDE_FILES ${PROJECT_SOURCE_DIR}/include/*.hpp)


add_executable(${PROJECT_NAME} main.cxx ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

install(
    TARGETS ${PROJECT_NAME}
    DESTINATION ${PROJECT_SOURCE_DIR}
    )
