//
//  Cell.cpp
//  Minesweeper
//
//  Created by Robert Berry on 24/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "Cell.h"

Cell::Cell(bool mine): mMine(mine), mHidden(true) {
}

void Cell::setHidden(bool hidden) {
    mHidden = hidden;
}

bool Cell::getHidden() {
    return mHidden;
}

bool Cell::getIsMine() {
    return mMine;
}

void Cell::setIsMine(bool isMine) {
    mMine = isMine;
}

bool Cell::getFlagged() {
    return mFlagged;
}

void Cell::setFlagged(bool flagged) {
    mFlagged = flagged;
}

bool Cell::getExploded() {
    return mExploded;
}

void Cell::setExploded(bool exploded) {
    mExploded = exploded;
}