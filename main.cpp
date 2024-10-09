#include <SFML/Graphics.hpp>

int main()
{
    // création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(600, 800), "Sawblade PC");
    window.setFramerateLimit(60);

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
    sawSprite.setScale(0.25f, 0.25f);
    sawSprite.setOrigin(188.5f, 188.5f);


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
        }

        // effacement de la fenêtre en noir
        window.clear(sf::Color::Black);

        // c'est ici qu'on dessine tout
        // window.draw(...);

        window.draw(bgSprite);
        window.draw(sawSprite);
        sawSprite.setPosition(300.f, 200.f);
        sawSprite.rotate(15.f);
        


        // fin de la frame courante, affichage de tout ce qu'on a dessiné
        window.display();
    }

    return 0;
}