//
//  FaceTextures.h
//  Minesweeper
//
//  Created by Robert Berry on 26/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Minesweeper__FaceTextures__
#define __Minesweeper__FaceTextures__

#include "TextureVector.h"
#include <SFML/Graphics.hpp>

class FaceTextures : public TextureVector {
public:
    FaceTextures();
    
    sf::Texture *getLose();
    sf::Texture *getWin();
    sf::Texture *getPlaying();
};

#endif /* defined(__Minesweeper__FaceTextures__) */
