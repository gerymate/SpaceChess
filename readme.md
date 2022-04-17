## SpaceChess

a cross platform, playable implementation of Raumschach invented by Ferdinand Maack

currently builds only on GNU/Linux and Windows, MacOS support in planned state

Requirements:
- use Bazel to build: https://bazel.build
The following will be automatically installed:
- to run the unit tests: Catch - https://github.com/catchorg/Catch2
- to link with: SFML - https://www.sfml-dev.org/
  - I found it easy to install SFML on a Mac with homebrew: brew install sfml

To build the game: bazel build SpaceChess
To run the tests: bazel test //...

Run the game from the resources/pieces directory - it's still buggy, but at least runs now...
Click on pieces to select, click on highlighted field to move a piece there. 
Use the mousewheel to change layer (zoom in/out)

This was my BSc thesis work at Eötvös Loránd University in 2015. Transition to modern C++ technics started in 2022.

If you want to contribute, the current license for all code in this repository ((except where otherwise stated, ie. svg, font and image files)) can be found here:
https://www.gnu.org/licenses/gpl-3.0.en.html

