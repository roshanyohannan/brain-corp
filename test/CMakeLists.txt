cmake_minimum_required(VERSION 3.10)

project(SpeedyTest VERSION 1.0)

include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY 	https://github.com/google/googletest.git
	GIT_TAG			release-1.11.0
	)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(SpeedyTest matrix.cpp)

target_include_directories(SpeedyTest PUBLIC "${PROJECT_SOURCE_DIR}/../include")

target_link_libraries(SpeedyTest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(SpeedyTest)
