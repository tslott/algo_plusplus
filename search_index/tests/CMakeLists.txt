########################################
# DEPENDENCIES
########################################

add_subdirectory(googletest)

set(GTEST_INCLUDE_DIRS
  ${gtest_SOURCE_DIR}/include
  ${gtest_SOURCE_DIR})

########################################
# INCLUDES
########################################

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../include)

########################################
# SOURCES
########################################

file(GLOB TEST_SOURCES ./*.cpp)
file(GLOB SOURCES ../src/*.cpp)

########################################
# TARGET
########################################

add_executable(search-index-test.out ${TEST_SOURCES} ${SOURCES})

target_link_libraries(search-index-test.out gtest gtest_main)

add_test(
  NAME search-index-test.out
  COMMAND search-index-test.out
)
