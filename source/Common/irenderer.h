// (C) Máté Gergely - gerymate@gmail.com
#ifndef IRENDERER_H
#define IRENDERER_H

#include "common.h"
#include <SFML/Graphics.hpp>
#include "Model/igameinfo.h"

namespace View {

class IRenderer
{
public:
    virtual void update() = 0;
    virtual void setLocalPlayers(Model::Player theLocalPlayers) = 0;
    virtual void handleClick(sf::Vector2f &mousePosition) = 0;
    virtual void zoomIn() = 0;
    virtual void zoomOut() = 0;
    virtual Model::Position setAndGetBoardCursorFromScreenPosition(sf::Vector2f position) = 0;
    virtual void setSelectedField(Model::Position theSelectedField) = 0;
    virtual void clearSelectedField() = 0;
    virtual void setHighlightedFields(Model::PointerToPositionList thePositions) = 0;
    virtual void clearHighlightedFields() = 0;
    virtual void setMessage(const std::string& theMessage) = 0;
    virtual sf::Window* getWindow() = 0;
};

}

#endif
