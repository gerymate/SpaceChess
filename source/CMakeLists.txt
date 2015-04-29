# The name of our project is "SPACECHESS". CMakeLists files in this project can
# refer to the root source directory of the project as ${SPACECHESS_SOURCE_DIR} and
# to the root binary directory of the project as ${SPACECHESS_BINARY_DIR}.
cmake_minimum_required (VERSION 2.6)
project (spacechess)

enable_testing()

# Enable C++11
set (CMAKE_CXX_FLAGS    "-Wall -std=c++11")

#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../whole)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../whole)

set(SFML_ROOT ${PROJECT_BINARY_DIR}/../SFML-2.2)
find_package(SFML COMPONENTS graphics window system REQUIRED)

# Include the directory itself as a path to include directories
# set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCES app.cpp main.cpp)

set (INCLUDE_DIRECTORIES . 
    Model Model/Pieces Model/GameEvents 
    View 
    Controller
    Tests
	${SFML_INCLUCE_DIR}
	)
include_directories(${INCLUDE_DIRECTORIES})

add_executable(SpaceChess ${SOURCES})
target_link_libraries(SpaceChess ${SFML_LIBRARIES})

# Example:
# include_directories (${SPACECHESS_SOURCE_DIR}/lib/glfw/include)
# include_directories (${SPACECHESS_SOURCE_DIR}/lib/glm)

# Make sure the linker can find the Hello library once it is built.
#link_directories (${SPACECHESS_BINARY_DIR}/Hello)

target_link_libraries(SpaceChess SpaceChessModel SpaceChessView2D SpaceChessControllers )

add_subdirectory(Model)
add_subdirectory(View)
add_subdirectory(Controller)

add_subdirectory(Tests)