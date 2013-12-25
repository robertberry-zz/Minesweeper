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

const int CELL_HEIGHT = 16;
const int CELL_WIDTH = 16;

sf::Texture *loadTexture(std::string filename) {
    sf::Texture *texture = new sf::Texture();
    if (!texture->loadFromFile(resourcePath() + filename)) {
        return NULL;
    }
    return texture;
}

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Texture *blankCell = loadTexture("empty.png");
    sf::Texture *flagCell = loadTexture("flag.png");
    sf::Texture *hiddenCell = loadTexture("hidden.png");
    sf::Texture *oneCell = loadTexture("one.png");
    sf::Texture *twoCell = loadTexture("two.png");
    sf::Texture *threeCell = loadTexture("three.png");
    sf::Texture *fourCell = loadTexture("four.png");
    sf::Texture *fiveCell = loadTexture("five.png");
    sf::Texture *sixCell = loadTexture("six.png");
    sf::Texture *sevenCell = loadTexture("seven.png");
    sf::Texture *eightCell = loadTexture("eight.png");
    sf::Texture *mineCell = loadTexture("mine.png");
    sf::Texture *blownMineCell = loadTexture("blown-mine.png");
    
    GameBoard gameBoard(10, 10);
    gameBoard.populateMines(10);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed) {
                int gridX = event.mouseButton.x / CELL_WIDTH;
                int gridY = event.mouseButton.y / CELL_HEIGHT;
                
                if (gameBoard.validCoordinate(gridX, gridY)) {
                    if (event.mouseButton.button == sf::Mouse::Button::Left) {
                        gameBoard.onClick(gridX, gridY);
                    }
                    if (event.mouseButton.button == sf::Mouse::Button::Right) {
                        gameBoard.onRightClick(gridX, gridY);
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

        // Draw the grid
        for (int x = 0; x < gameBoard.getRows(); x++) {
            for (int y = 0; y < gameBoard.getColumns(); y++) {
                Cell cell = gameBoard.getCell(x, y);
                sf::Texture *texture = NULL;
                
                if (cell.getFlagged()) {
                    texture = flagCell;
                } else if (cell.getHidden()) {
                    texture = hiddenCell;
                } else if (cell.getExploded()) {
                    texture = blownMineCell;
                } else if (cell.getIsMine()) {
                    texture = mineCell;
                } else {
                    switch (gameBoard.getNeighbouringMines(x, y)) {
                        case 0: texture = blankCell; break;
                        case 1: texture = oneCell;   break;
                        case 2: texture = twoCell;   break;
                        case 3: texture = threeCell; break;
                        case 4: texture = fourCell;  break;
                        case 5: texture = fiveCell;  break;
                        case 6: texture = sixCell;   break;
                        case 7: texture = sevenCell; break;
                        case 8: texture = eightCell; break;
                    }
                }
                sf::Sprite sprite(*texture);
                sprite.setPosition(x * CELL_WIDTH, y * CELL_HEIGHT);
                window.draw(sprite);
            }
        }
 
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
