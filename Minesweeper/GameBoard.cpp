//
//  GameBoard.cpp
//  Minesweeper
//
//  Created by Robert Berry on 24/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#include "GameBoard.h"
#include <Vector>

GameBoard::GameBoard(int rows, int columns) : mRows(rows), mColumns(columns) {
    mCells = std::vector< std::vector<Cell> >();
    
    for (int i = 0; i < rows; i++) {
        mCells.push_back(std::vector<Cell>());
        for (int j = 0; j < columns; j++) {
            mCells[i].push_back(new Cell(false));
        }
    }
}

int GameBoard::neighbouringMines(int x, int y) {
    int neighbours = 0;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (!((i == x && y == j) ||       /* Don't count the cell itself */
                  x < 0 ||                    /* Don't examine out-of-bound cells */
                  x >= mRows ||
                  y < 0 ||
                  y >= mColumns
                  ) &&
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