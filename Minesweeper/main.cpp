
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

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
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

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
    
    GameBoard gameBoard(10, 10);
    
    Cell c = gameBoard.getCell(5, 5);
    c.setFlagged(true);
    gameBoard.setCell(5, 5, c);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed : exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
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
                } else {
                    switch (gameBoard.neighbouringMines(x, y)) {
                        case 0: texture = blankCell; break;
                        case 1: texture = oneCell; break;
                        case 2: texture = twoCell; break;
                        case 3: texture = threeCell; break;
                        case 4: texture = fourCell; break;
                        case 5: texture = fiveCell; break;
                        case 6: texture = sixCell; break;
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
