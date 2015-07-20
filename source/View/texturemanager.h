// (C) Máté Gergely - GERYMATE@GMAIL.COM
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>

namespace View {

class TextureManager
{
    std::vector<std::vector<sf::Texture> > pieces;
  
public:
    TextureManager();
    ~TextureManager();
    const sf::Texture* getPieceFor(int owner, int figure) const;
};

}

#endif 