cmake_minimum_required(VERSION 3.10)

project(Speedy 
		VERSION 		1.0
		DESCRIPTION		"a header only linear algebra library"
		HOMEPAGE_URL 	"https://github.com/roshanyohannan/brain-corp")

add_library(Speedy INTERFACE)
target_include_directories(
	Speedy 
	INTERFACE 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

set(CMAKE_CXX_STANDARD          11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS_RELEASE     "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG       "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

enable_testing()

add_subdirectory(test)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION "${CMAKE_PROJECT_NAME}")