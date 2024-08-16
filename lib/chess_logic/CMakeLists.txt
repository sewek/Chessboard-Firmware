project(chess_logic LANGUAGES CXX)

if (POLICY CMP0025)
   cmake_policy(SET CMP0025 NEW)
endif ()

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(SOURCES
   src/chess_logic.cpp
   src/chess_board.cpp
   src/chess_position.cpp
   src/chess_events.cpp
   src/chess_game.cpp
)

include_directories(include)
add_library(chess_logic_lib ${SOURCES})

# Tests
set(TESTS
   test/board.cpp
   test/game.cpp
   test/events.cpp
   test/position.cpp
)

Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.7.0
)
FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

add_executable(tests ${TESTS} ${SOURCES})

target_link_libraries(tests PRIVATE chess_logic_lib Catch2::Catch2WithMain)
include(CTest)
include(Catch)
catch_discover_tests(tests)

# Coverage
include(../../cmake/CodeCoverage.cmake)
APPEND_COVERAGE_COMPILER_FLAGS()
setup_target_for_coverage_gcovr_xml(
   NAME coverage
   EXECUTABLE tests
   DEPENDENCIES tests chess_logic_lib
)
