/**
 * Minesweeper
 *
 * Copyright 2013, Robert Berry
 */

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
#include <string.h>
#include <GameBoard.h>
#include <memory.h>
#include "CellTextures.h"
#include "FaceTextures.h"
#include <string>

const int CELL_HEIGHT = 16;
const int CELL_WIDTH = 16;

const int FACE_WIDTH = 26;
const int FACE_HEIGHT = 26;

const int ROWS = 20;
const int COLUMNS = 30;
const int MINES = 40;

const int BOARD_X_OFFSET = 8;
const int BOARD_Y_OFFSET = 40;

const int BORDER = 8;

const int WINDOW_WIDTH = COLUMNS * CELL_WIDTH + BORDER * 2;
const int WINDOW_HEIGHT = BOARD_Y_OFFSET + CELL_HEIGHT * ROWS + BORDER;

const int FACE_X = (WINDOW_WIDTH - FACE_WIDTH) / 2;
const int FACE_Y = BORDER;

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Minesweeper");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    GameBoard gameBoard(COLUMNS, ROWS, MINES);
    
    CellTextures cellTextures;
    FaceTextures faceTextures;
    
    sf::RectangleShape backFill;
    backFill.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    backFill.setFillColor(sf::Color(164, 164, 164));

    sf::RectangleShape gridBorder;
    gridBorder.setPosition(sf::Vector2f(BOARD_X_OFFSET, BOARD_Y_OFFSET));
    gridBorder.setSize(sf::Vector2f(COLUMNS * CELL_WIDTH + 1, ROWS * CELL_HEIGHT + 1));
    gridBorder.setFillColor(sf::Color(86, 86, 86));
    
    int score = 0;
    
    sf::Font scoreFont;
    scoreFont.loadFromFile(resourcePath() + "sansation.ttf");
    sf::Text scoreCounter;
    scoreCounter.setPosition(BORDER, 0);
    scoreCounter.setColor(sf::Color::Black);
    scoreCounter.setFont(scoreFont);
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed) {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                
                int gridX = (mouseX - BOARD_X_OFFSET) / CELL_WIDTH;
                int gridY = (mouseY - BOARD_Y_OFFSET) / CELL_HEIGHT;
                
                if (gameBoard.validCoordinate(gridX, gridY)) {
                    if (event.mouseButton.button == sf::Mouse::Button::Left) {
                        score += gameBoard.onClick(gridX, gridY);
                    }
                    if (event.mouseButton.button == sf::Mouse::Button::Right) {
                        gameBoard.onRightClick(gridX, gridY);
                    }
                } else {
                    if (mouseX >= FACE_X && mouseX <= FACE_X + FACE_WIDTH &&
                        mouseY >= FACE_Y && mouseY <= FACE_Y + FACE_HEIGHT &&
                        event.mouseButton.button == sf::Mouse::Button::Left) {
                        /** RESTART GAME! */
                        score = 0;
                        gameBoard = GameBoard(COLUMNS, ROWS, MINES);
                    }
                }
            }
            
            // Close window : exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed : exit
            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();
        window.draw(backFill);
        window.draw(gridBorder);

        scoreCounter.setString(std::to_string(score));
        window.draw(scoreCounter);

        // Draw the grid
        for (int y = 0; y < gameBoard.getRows(); y++) {
            for (int x = 0; x < gameBoard.getColumns(); x++) {
                Cell cell = gameBoard.getCell(x, y);
                sf::Sprite sprite(*cellTextures.getCellTexture(cell, gameBoard.getNeighbouringMines(x, y)));
                sprite.setPosition(BOARD_X_OFFSET + x * CELL_WIDTH, BOARD_Y_OFFSET + y * CELL_HEIGHT);
                window.draw(sprite);
            }
        }
        
        // Draw the face
        sf::Sprite face(*(gameBoard.getIsGameOver() ? faceTextures.getLose() :
                          gameBoard.getIsGameWon() ? faceTextures.getWin() :
                          faceTextures.getPlaying()));
        face.setPosition(FACE_X, FACE_Y);
        window.draw(face);
 
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
