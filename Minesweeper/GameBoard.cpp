//
//  GameBoard.cpp
//  Minesweeper
//
//  Created by Robert Berry on 24/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "GameBoard.h"
#include <Vector>
#include <stdlib.h>

GameBoard::GameBoard(int rows, int columns) : mRows(rows), mColumns(columns), mGameOver(false) {
    mCells = std::vector< std::vector<Cell> >();
    
    for (int i = 0; i < rows; i++) {
        mCells.push_back(std::vector<Cell>());
        for (int j = 0; j < columns; j++) {
            mCells[i].push_back(Cell(false));
        }
    }
}

int GameBoard::getNeighbouringMines(int x, int y) {
    int neighbours = 0;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (!(i == x && y == j) &&       /* Don't count the cell itself */
                  validCoordinate(i, j) &&
                  mCells[i][j].getIsMine()) {
                neighbours++;
            }
        }
    }
    
    return neighbours;
}

Cell GameBoard::getCell(int x, int y) {
    return mCells[x][y];
}

void GameBoard::setCell(int x, int y, Cell cell) {
    mCells[x][y] = cell;
}

int GameBoard::getRows() {
    return mRows;
}

int GameBoard::getColumns() {
    return mColumns;
}

void GameBoard::onClick(int x, int y) {
    if (!mGameOver && getCell(x, y).getHidden()) {
        reveal(x, y);
    }
}

void GameBoard::onRightClick(int x, int y) {
    if (!mGameOver) {
        Cell c = getCell(x, y);
        
        if (c.getHidden()) {
            c.setFlagged(true);
            setCell(x, y, c);
        }
    }
}

void GameBoard::reveal(int x, int y) {
    Cell thisCell = getCell(x, y);
    
    if (thisCell.getHidden()) {
        thisCell.setHidden(false);
        thisCell.setExploded(thisCell.getIsMine());
        setCell(x, y, thisCell);
        
        if (thisCell.getIsMine()) {
            mGameOver = true;
            return;
        }
        
        /** If a tile not adjacent to any neighbouring mines, flood in each direction */
        if (getNeighbouringMines(x, y) == 0) {
            sweep(x - 1, y, -1);
            sweep(x + 1, y, 1);
            
            Cell up = getCell(x, y - 1);
            if (up.getHidden() && !up.getIsMine()) {
                reveal(x, y - 1);
            }
            Cell down = getCell(x, y + 1);
            if (down.getHidden() && !down.getIsMine()) {
                reveal(x, y + 1);
            }
        }
    }
}

void GameBoard::sweep(int x, int y, int step) {
    while (validCoordinate(x, y)) {
        Cell c = getCell(x, y);
        
        if (!c.getHidden() || c.getIsMine()) {
            break;
        }
        
        c.setHidden(false);
        setCell(x, y, c);
        
        if (getNeighbouringMines(x, y) > 0) {
            /** sweep does not go past numbered tiles */
            break;
        }
        
        x += step;
    } 
}

bool GameBoard::validCoordinate(int x, int y) {
    return x >= 0 && x < mColumns && y >= 0 && y < mRows;
}

void GameBoard::populateMines(int n) {
    while (n > 0) {
        int i = rand() % mColumns;
        int j = rand() % mRows;
        
        Cell c = getCell(i, j);
        
        if (c.getIsMine()) continue;
        
        c.setIsMine(true);
        setCell(i, j, c);
        n--;
    }
}
