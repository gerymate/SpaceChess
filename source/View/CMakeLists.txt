# Include the directory itself as a path to include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Create a variable called helloworld_SOURCES containing all .cpp files:
set(SOURCES render2d.cpp 
	    stylesheet.cpp 
	    boardpainter.cpp field.cpp 
	    panelpainter.cpp widget.cpp cursorinfo.cpp nextplayerinfo.cpp messagewidget.cpp)

# For a large number of source files you can create it in a simpler way
# using file() function:
# file(GLOB hellworld_SOURCES *.cpp)

add_library(SpaceChessView2D ${SOURCES})

# Make sure the compiler can find include files from our glfw library.
# Example:
# include_directories (${SPACECHESS_SOURCE_DIR}/lib/glfw/include)
# include_directories (${SPACECHESS_SOURCE_DIR}/lib/glm)

# Make sure the linker can find the Hello library once it is built.
#link_directories (${SPACECHESS_BINARY_DIR}/Hello)

# Link with the required SFML modules
target_link_libraries(SpaceChessView2D sfml-graphics sfml-window sfml-system)
