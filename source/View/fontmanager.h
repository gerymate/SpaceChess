// (C) Máté Gergely - gerymate@gmail.com
#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <SFML/Graphics.hpp>

namespace View {

struct FontManager
{
    sf::Font font;
public:
    FontManager();
    ~FontManager();
};

}

#endif 