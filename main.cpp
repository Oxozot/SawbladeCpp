#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // constante
    const int FPS = 60;
    const float Velocity = 6.f;
    const float jump = 320.f;
    const float Gravity = 6.f;

    const int largeurWindow = 600;
    const int hauteurWindow = 800;

    // variable
    float persoPosX = 300.f;
    float persoPosY = 760.f;
    int jumpCounter = 0;

    // création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(largeurWindow, hauteurWindow), "Sawblade PC", sf::Style::Close);
    window.setFramerateLimit(FPS);

    // création des textures et des sprites
    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("res/Img/BackgroundImage.png"))
    {

    }
    sf::Sprite bgSprite;
    bgSprite.setTexture(bgTexture);

    sf::Texture sawTexture;
    if (!sawTexture.loadFromFile("res/Img/saw.png"))
    {

    }
    sf::Sprite sawSprite;
    sawSprite.setTexture(sawTexture);
    sawSprite.setScale(0.2f, 0.2f);
    sawSprite.setOrigin(188.5f, 188.5f);

    // création d'un personnage temporaire
    sf::RectangleShape perso(sf::Vector2f(50,80));
    perso.setOrigin(25.f, 40.f);
    perso.setFillColor(sf::Color(0, 179, 196));
    perso.setPosition(persoPosX, persoPosY);


    // on fait tourner le programme tant que la fenêtre n'a pas été fermée
    while (window.isOpen())
    {
        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
        sf::Event event;
        while (window.pollEvent(event))
        {
            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed)
                window.close();

            // lecture des touches pressées
            if (event.type == sf::Event::KeyPressed)
            {
                // deplacement du perso
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    std::cout << "perso x = " << persoPosX << "perso y = " << persoPosY << std::endl;
                    persoPosX = persoPosX + Velocity;
                    perso.move(persoPosX, persoPosY);
                }
                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                {
                    std::cout << "perso x = " << persoPosX << "perso y = " << persoPosY << std::endl;
                    persoPosX = persoPosX - Velocity;
                    perso.move(persoPosX, persoPosY);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                {
                    std::cout << "jump counter = " << jumpCounter << std::endl;
                    if (jumpCounter < 2)
                    {
                        std::cout << "perso x = " << persoPosX << "perso y = " << persoPosY << std::endl;
                        persoPosY = persoPosY - jump;
                        perso.move(persoPosX, persoPosY);
                        jumpCounter ++;
                    }
                }
            }
        }

        // gravite
        persoPosY = persoPosY + Gravity;
        perso.setPosition(persoPosX, persoPosY);

        // bordure du jeu
        if (perso.getPosition().x < 25)
        {
            persoPosX = 25.f;
        }
        if (perso.getPosition().x > 575)
        {
            persoPosX = 575.f;
        }
        if (perso.getPosition().y > 760)
        {
            persoPosY = 760.f;
            jumpCounter = 0;
        }

        // effacement de la fenêtre en noir
        window.clear(sf::Color::Black);

        // c'est ici qu'on dessine tout
        // window.draw(...);

        window.draw(bgSprite);
        window.draw(sawSprite);
        sawSprite.setPosition(300.f, 200.f);
        sawSprite.rotate(15.f);
        window.draw(perso);


        // fin de la frame courante, affichage de tout ce qu'on a dessiné
        window.display();
    }

    return 0;
}