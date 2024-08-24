cmake_minimum_required(VERSION 3.25)
project(yacw VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(CTest)
enable_testing()

set(YACW_LIBRARY_NAME yacw)
set(YACW_LIBRARY_TARGETS yacw_targets)
set(INCLUDE_DIRNAME include)

include_directories(${INCLUDE_DIRNAME})

set(SOURCE_FILES
    src/yacw.cpp
)
add_library(${YACW_LIBRARY_NAME} STATIC ${SOURCE_FILES})
target_include_directories(${YACW_LIBRARY_NAME} PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

set(CURSES_NEED_WIDE TRUE)
find_package(Curses REQUIRED)
target_include_directories(${YACW_LIBRARY_NAME} INTERFACE ${Curses_INCLUDE_DIRS})
target_link_libraries(${YACW_LIBRARY_NAME} PRIVATE ${Curses_LIBRARIES})


install(TARGETS ${YACW_LIBRARY_NAME}
    EXPORT ${YACW_LIBRARY_TARGETS}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT ${YACW_LIBRARY_TARGETS}
    FILE yacwConfig.cmake
    NAMESPACE yacw::
    DESTINATION lib/cmake/yacw
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/yacwConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/yacwConfigVersion.cmake"
    DESTINATION lib/cmake/yacw
)

# Testing
option(BUILD_TESTS "Build Tests" ON)

if(BUILD_TESTS)
	message(STATUS "Testing is enabled. To run tests, please use CTest executable.")
	add_subdirectory(tests)
else()
	message(STATUS "Testing is disabled.")
endif()
