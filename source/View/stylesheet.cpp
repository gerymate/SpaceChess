// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#include "stylesheet.h"

#include <iostream>

namespace View {


StyleSheet::StyleSheet(TextureManager* theTextureManager, FontManager* theFontManager) 
    : textureManager{ theTextureManager }, fontManager{ theFontManager }
{
}

StyleSheet::~StyleSheet()
{

}


}