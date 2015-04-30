# Include the directory itself as a path to include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Create a variable called helloworld_SOURCES containing all .cpp files:
set(SOURCES 
    gamecontroller.cpp event.cpp)

# For a large number of source files you can create it in a simpler way
# using file() function:
# file(GLOB hellworld_SOURCES *.cpp)

# Create an executable file called helloworld from sources:
add_library(SpaceChessControllers ${SOURCES})


# Make sure the compiler can find include files from our glfw library.
# Example:
# include_directories (${SPACECHESS_SOURCE_DIR}/lib/glfw/include)
# include_directories (${SPACECHESS_SOURCE_DIR}/lib/glm)

# Make sure the linker can find the Hello library once it is built.
#link_directories (${SPACECHESS_BINARY_DIR}/Hello)


# Example:
# Link the executable to the glfw library.
target_link_libraries(SpaceChessControllers SpaceChessModel SpaceChessView2D)
