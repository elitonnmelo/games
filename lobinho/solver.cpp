// command to build program: g++ -std=c++17 -Wall -Wextra -Werror solver.cpp -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

void setSize(sf::Sprite& sprite, int width, int height) {
    auto dim = sprite.getLocalBounds();
    sprite.setScale((float) width / dim.width, (float) height / dim.height);
}

struct Entity {
    int x {0}; //atributos
    int y {0};
    int step {0};
    sf::Sprite sprite;

    Entity(int x, int y, int step, sf::Texture& texture):
        x {x}, y {y}, step {step}, sprite(texture) {
    }

    void draw(sf::RenderWindow& window) { //métodos
        this->sprite.setPosition(x * step, y * step);
        setSize(this->sprite, step, step);
        window.draw(this->sprite);
    }
};

struct Board {
    int nc {0};
    int nl {0};
    int step {0};//atributos
    sf::Sprite sprite;
    sf::RectangleShape rect;
    //parametros
    Board(int nc, int nl, int step, sf::Texture& texture) {
        this->nc = nc;
        this->nl = nl;
        this->step = step;
        this->sprite.setTexture(texture);
        setSize(this->sprite, nc * step, nl * step);
        this->sprite.setPosition(0, 0);

        this->rect.setSize(sf::Vector2f(step, step));
        this->rect.setFillColor(sf::Color::Transparent);
        this->rect.setOutlineColor(sf::Color::Black);
        this->rect.setOutlineThickness(2);
    }
    void draw(sf::RenderWindow& window) {
        window.draw(this->sprite);
        for (int i = 0; i < nc; i++) {
            for (int j = 0; j < nl; j++) {
                rect.setPosition(i * step, j * step);
                window.draw(rect);
            }
        }
    }
};

int windowWidth = 0;
int windowHeight = 0;
const int STEP {100};


void moveEntity(sf::Keyboard::Key key, Entity& entity, std::vector<sf::Keyboard::Key> move_keys) {
    // if (key == move_keys[0])
    //     entity.x--;
    // else if (key == move_keys[1])
    //     entity.y--;
    // else if (key == move_keys[2])
    //     entity.x++;
    // else if (key == move_keys[3])
    //     entity.y++;

    if (key == move_keys[0] && entity.x > 0)
        entity.x--;
    else if (key == move_keys[1] && entity.y > 0)
        entity.y--;
    else if (key == move_keys[2] && entity.x < windowWidth / STEP - 1)
        entity.x++;
    else if (key == move_keys[3] && entity.y < windowHeight / STEP - 1)
        entity.y++;

}

sf::Texture loadTexture(std::string path) {
    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cout << "Error loading texture" << std::endl;
        exit(1);
    }
    return texture;
}



int main() {

    sf::Texture wolf_tex { loadTexture("lobol.png") };
    sf::Texture rabbit_tex { loadTexture("coelho.png") };
    sf::Texture grass_tex { loadTexture("grama.jpg") };

    //const int STEP {100};


    Entity wolf(1, 1, STEP, wolf_tex);
    Entity rabbit(3, 3, STEP, rabbit_tex);
    Board board(7, 5, STEP, grass_tex);

    sf::RenderWindow window(sf::VideoMode(board.nc * STEP, board.nl * STEP), "SFML works!");

    bool wolfAteRabbit = (false);

    sf::Vector2u windowSize = window.getSize();
    windowWidth = windowSize.x;
    windowHeight = windowSize.y;


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (wolfAteRabbit) {
                    break;
                }
                moveEntity(event.key.code, wolf, {sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Right, sf::Keyboard::Down});
                moveEntity(event.key.code, rabbit, {sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::D, sf::Keyboard::S});
                if ((wolf.x == rabbit.x) && (wolf.y == rabbit.y) && (event.key.code == sf::Keyboard::Enter)) {
                    wolfAteRabbit = (true);
                }
            }
        }

        if (wolfAteRabbit) {
            window.clear();
            
            //draw a big red x in the screen
            sf::RectangleShape line1(sf::Vector2f(100, 10));
            line1.rotate(45);
            line1.setPosition(200, 200);
            line1.setFillColor(sf::Color::Red);
            window.draw(line1);
            window.display();
        } else {
            window.clear();
            board.draw(window);
            wolf.draw(window);
            rabbit.draw(window);
            window.display(); 
        }
    }

    return 0;
}