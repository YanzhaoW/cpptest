cmake_minimum_required(VERSION 3.13.4)

project(trail VERSION 1.0)
# add_compile_options(-fsanitize=address -g) add_link_options(-fsanitize=address
# -g)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # used by clang-tidy
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)
# message(STATUS "${CMAKE_CXX_CLANG_TIDY}")
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cxx)
file(GLOB INCLUDE_FILES ${PROJECT_SOURCE_DIR}/src/*.hpp)

set(CTEST_USE_LAUNCHERS YES)
# find_package(ROOT REQUIRED)

# include_directories(${ROOT_INCLUDE_DIRS})

add_library(mylib ${SRC_FILES})
target_include_directories(mylib PUBLIC ${PROJECT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} main.cxx)
target_link_libraries(${PROJECT_NAME} mylib ${ROOT_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)

execute_process(COMMAND sh "${PROJECT_SOURCE_DIR}/test.sh")


include(ctest)
# testing:
# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   GIT_REPOSITORY https://github.com/google/googletest.git
#   GIT_TAG release-1.12.1)
# FetchContent_MakeAvailable(googletest)
find_package(GTest)

enable_testing()
add_executable(mytest mytest.cxx)
target_link_libraries(mytest mylib GTest::gtest_main GTest::gmock_main)

if(NOT TARGET GTest::gmock_main)
    message("no gtest_main")
else()
    message("have gtest_main")
endif()

include(GoogleTest)
gtest_discover_tests(mytest)

message(STATUS "testing")
# FetchContent_GetProperties(googletest)
# if(NOT googletest_POPULATED)
#   message(STATUS "google test not populated.")
# else()
#   message(STATUS "google test populated.")
# endif()
