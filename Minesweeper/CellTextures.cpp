//
//  CellTextures.cpp
//  Minesweeper
//
//  Created by Robert Berry on 25/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "CellTextures.h"
#include "TextureKey.h"
#include <SFML/Graphics.hpp>

CellTextures::CellTextures() : TextureVector() {
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
        return get(FLAG);
    } else if (cell.getHidden()) {
        return get(HIDDEN);
    } else if (cell.getExploded()) {
        return get(EXPLODED_MINE);
    } else if (cell.getIsMine()) {
        return get(REVEALED_MINE);
    } else {
        return get(neighbours);
    }
}