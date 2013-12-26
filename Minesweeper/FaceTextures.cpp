//
//  FaceTextures.cpp
//  Minesweeper
//
//  Created by Robert Berry on 26/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "FaceTextures.h"

FaceTextures::FaceTextures() {
    appendTexture("lose-face.png");
    appendTexture("play-face.png");
    appendTexture("win-face.png");
}

sf::Texture *FaceTextures::getLose() {
    return get(0);
}

sf::Texture *FaceTextures::getPlaying() {
    return get(1);
}

sf::Texture *FaceTextures::getWin() {
    return get(2);
}