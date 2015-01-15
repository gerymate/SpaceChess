# The name of our project is "SPACECHESS". CMakeLists files in this project can
# refer to the root source directory of the project as ${SPACECHESS_SOURCE_DIR} and
# to the root binary directory of the project as ${SPACECHESS_BINARY_DIR}.
cmake_minimum_required (VERSION 2.6)
project (spacechess)

# Enable C++11
set (CMAKE_CXX_FLAGS    "-Wall -std=c++11")

#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../whole)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../whole)

# Include the directory itself as a path to include directories
# set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCES main.cpp)

set (INCLUDE_DIRECTORIES Model View)
include_directories(${INCLUDE_DIRECTORIES})

# Create an executable file called helloworld from sources:
add_executable(SpaceChess ${SOURCES})

# Example:
# include_directories (${SPACECHESS_SOURCE_DIR}/lib/glfw/include)
# include_directories (${SPACECHESS_SOURCE_DIR}/lib/glm)

# Make sure the linker can find the Hello library once it is built.
#link_directories (${SPACECHESS_BINARY_DIR}/Hello)

target_link_libraries(SpaceChess SpaceChessModel SpaceChessView2D)

add_subdirectory(Model)
add_subdirectory(View)
