// (C) Máté Gergely - gerymate@gmail.com
#include "texturemanager.h"

#include <iostream>

namespace View {

TextureManager::TextureManager()
{
    // load pieces!
    pieces.resize(2);
    pieces[0].resize(7);
    pieces[1].resize(7);
    std::vector<std::vector<std::string> > fileNames {
	{"white-king.png", "white-queen.png", "white-rook.png", "white-bishop.png", "white-knight.png", "white-unicorn.png", "white-pawn.png"},
	{"black-king.png", "black-queen.png", "black-rook.png", "black-bishop.png", "black-knight.png", "black-unicorn.png", "black-pawn.png"},
    };

	bool fatalError = false;

    for (int i = 0; i != 2; ++i)
    {
	for (int j = 0; j != 7; ++j)
	{
	    if (! (pieces[i][j]).loadFromFile(fileNames[i][j]))
	    {
			std::cerr << "Error loading " << fileNames[i][j] << std::endl;
			fatalError = true;
	    }
	}
    }
    

    if (fatalError)
    {
	exit(1);
    }

}

TextureManager::~TextureManager()
{

}

const sf::Texture* TextureManager::getPieceFor(int owner, int figure) const
{
    return &pieces[owner - 1][figure - 1];
}


}