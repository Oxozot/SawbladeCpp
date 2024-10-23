#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

int main()
{
    // constante
    const int FPS = 240;
    const float Velocity = 500.f;
    const float jump = 320.f;
    const float Gravity = 500.f;

    const int largeurWindow = 600;
    const int hauteurWindow = 800;
    // variable
    sf::Vector2f playerPosition(300, 760);
    int jumpCounter = 0;

    bool up = false;
    bool down = false;
    bool right = false;
    bool left = false;

    // création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(largeurWindow, hauteurWindow), "Sawblade PC", sf::Style::Close | sf::Style::Titlebar);
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

    // création d'un personnage
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("res/Img/Player.png")){

    }

    sf::Sprite player;

    player.setTexture(playerTexture);

    player.setScale(0.25f, 0.25f);
    player.setOrigin(216/2, 244/2);

    // création d'une platforme
    sf::Texture platformTexture;
    if (!platformTexture.loadFromFile("res/Img/test.png")){

    }

    sf::Sprite platformSprite;

    platformSprite.setTexture(platformTexture);

    platformSprite.setScale(4.f, 4.f);
    platformSprite.setOrigin(8.f, 8.f);
    platformSprite.setPosition(300.f, 600.f);





    //sf::RectangleShape player(sf::Vector2f(50,80));
    //player.setOrigin(25.f, 40.f);
    //player.setFillColor(sf::Color(0, 179, 196));
    player.setPosition(playerPosition);

    sf::Clock clock;

    // on fait tourner le programme tant que la fenêtre n'a pas été fermée
    while (window.isOpen())
    {
        // delta time
        
        sf::Time time = clock.restart();
        clock.restart();     

    // mouvement
    //if (right) playerPosition.x = playerPosition.x + Velocity * time.asSeconds();
    

        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            float frameVelocity = Velocity * time.asSeconds();

            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed)
                window.close();

            // lecture des touches pressées
            if (event.type == sf::Event::KeyReleased)
            {
                if (sf::Keyboard::D) right = false;
                if (sf::Keyboard::Q) left = false;
            }
            if (event.type == sf::Event::KeyPressed)
            {
                // deplacement du perso
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    right = true;
                    //std::cout << "perso x = " << playerPosition.x << "perso y = " << playerPosition.y << std::endl;
                    //playerPosition.x = playerPosition.x + Velocity * time.asSeconds();
                } 
                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                {
                    left = true;
                    //std::cout << "perso x = " << playerPosition.x << "perso y = " << playerPosition.y << std::endl;
                    //playerPosition.x = playerPosition.x - Velocity * time.asSeconds();
                    
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                {
                    std::cout << "jump counter = " << jumpCounter << std::endl;
                    if (jumpCounter < 2)
                    {
                        std::cout << "perso x = " << playerPosition.x << "perso y = " << playerPosition.y << std::endl;
                        playerPosition.y = playerPosition.y - jump;
                        player.move(playerPosition.x, playerPosition.y);
                        jumpCounter ++;
                    }
                }
            }

            
        }

        //mvmnt 
        if (right) playerPosition.x = playerPosition.x + Velocity * time.asSeconds();
        if (left) playerPosition.x = playerPosition.x - Velocity * time.asSeconds();

        // gravite
        playerPosition.y = playerPosition.y + Gravity * time.asSeconds();
        player.setPosition(playerPosition.x, playerPosition.y);

        // bordure du jeu
        if (player.getPosition().x < 25)
        {
            playerPosition.x = 25.f;
        }
        if (player.getPosition().x > 575)
        {
            playerPosition.x = 575.f;
        }
        if (player.getPosition().y > 760)
        {
            playerPosition.y = 760.f;
            jumpCounter = 0;
        }

        //std::cout << left << std::endl;


        // effacement de la fenêtre en noir
        window.clear(sf::Color::Black);


        // c'est ici qu'on dessine tout
        // window.draw(...);

        

        window.draw(bgSprite);
        window.draw(sawSprite);
        window.draw(platformSprite);
        sawSprite.setPosition(300.f, 200.f);
        sawSprite.rotate(3.75f);
        window.draw(player);


        
        // fin de la frame courante, affichage de tout ce qu'on a dessiné
        window.display();
    }

    return 0;
}