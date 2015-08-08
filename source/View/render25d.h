// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#ifndef RENDER25D_H
#define RENDER25D_H

#include "irenderer.h"
#include "common.h"
#include <SFML/Graphics.hpp>
#include "Model/igameinfo.h"
#include "boardpainter.h"
#include "panelpainter.h"

namespace View {

class Render25D : public IRenderer
{
    sf::RenderWindow* window;
    Model::IGameInfo* game;
    EventQueue* eventQueue;
    TextureManager textureManager;
    FontManager fontManager;
    StyleSheet style;
    BoardPainter boardPainter;
    PanelPainter panelPainter;
    Model::Position cursor;
    std::string message;
public:
    Render25D(sf::RenderWindow* theWindow, Model::IGameInfo* theGame, 
	     EventQueue* theEventQueue);
    ~Render25D();
    void update() override;
    void setLocalPlayers(Model::Player theLocalPlayers) override;
    void handleClick(sf::Vector2f &mousePosition) override;
    void zoomIn() override;
    void zoomOut() override;
    Model::Position setAndGetBoardCursorFromScreenPosition(sf::Vector2f position) override;
    void setSelectedField(Model::Position theSelectedField) override;
    void clearSelectedField() override;
    void setHighlightedFields(Model::PointerToPositionList thePositions) override;
    void clearHighlightedFields() override;
    void setMessage(const std::string& theMessage) override;
    sf::Window* getWindow() override;
};

}

#endif
