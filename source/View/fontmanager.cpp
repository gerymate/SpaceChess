// (C) Máté Gergely - gerymate@gmail.com
#include "fontmanager.h"

#include <iostream>

namespace View {


FontManager::FontManager()
{
    bool fatalError {false};
    
    // load font
    if (! font.loadFromFile("sansation.ttf"))
    {
	std::cerr << "Error loading sansation.ttf" << std::endl;
	fatalError = true;
    }

    if (fatalError)
    {
	    exit(1);
    }

}

FontManager::~FontManager()
{

}


}