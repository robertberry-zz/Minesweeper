//
//  TextureVector.cpp
//  Minesweeper
//
//  Created by Robert Berry on 26/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "TextureVector.h"
#include "ResourcePath.hpp"

void TextureVector::appendTexture(std::string filename) {
    sf::Texture texture;
    if (texture.loadFromFile(resourcePath() + filename)) {
        mTextures.push_back(texture);
    }
}

sf::Texture *TextureVector::get(int index) {
    return &mTextures[index];
}