//
//  CellTextures.cpp
//  Minesweeper
//
//  Created by Robert Berry on 25/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "CellTextures.h"
#include "TextureKey.h"
#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>

void CellTextures::appendTexture(std::string filename) {
    sf::Texture texture;
    if (texture.loadFromFile(resourcePath() + filename)) {
        textures.push_back(texture);
    }
}

CellTextures::CellTextures() {
    appendTexture("empty.png");
    appendTexture("one.png");
    appendTexture("two.png");
    appendTexture("three.png");
    appendTexture("four.png");
    appendTexture("five.png");
    appendTexture("six.png");
    appendTexture("seven.png");
    appendTexture("eight.png");
    appendTexture("flag.png");
    appendTexture("hidden.png");
    appendTexture("mine.png");
    appendTexture("blown-mine.png");
}

sf::Texture *CellTextures::getCellTexture(Cell cell, int neighbours) {
    if (cell.getFlagged()) {
        return &textures[FLAG];
    } else if (cell.getHidden()) {
        return &textures[HIDDEN];
    } else if (cell.getExploded()) {
        return &textures[EXPLODED_MINE];
    } else if (cell.getIsMine()) {
        return &textures[REVEALED_MINE];
    } else {
        return &textures[neighbours];
    }
}