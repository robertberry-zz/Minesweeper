//
//  CellTextures.h
//  Minesweeper
//
//  Created by Robert Berry on 25/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Minesweeper__CellTextures__
#define __Minesweeper__CellTextures__

#include "TextureKey.h"
#include "TextureVector.h"
#include <SFML/Graphics.hpp>
#include "Cell.h"

class CellTextures : public TextureVector {
public:
    CellTextures();
    
    sf::Texture *getCellTexture(Cell cell, int neighbours);
};

#endif /* defined(__Minesweeper__CellTextures__) */
