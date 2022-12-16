// Sliwa_A_CGT215_ZombieGame.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
#include <vector>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;
using namespace sfp;

const float KB_SPEED = 0.2;

//error message if file not found
void LoadTex(Texture& tex, string filename) {
    if (!tex.loadFromFile(filename)) {
        cout << "Could not load " << filename << endl;
    }
}

void ZombieWalk(PhysicsSprite& zombie, int elapsedMS) {
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        Vector2f newPos(zombie.getCenter());
        newPos.x = newPos.x + (KB_SPEED * elapsedMS);
        zombie.setCenter(newPos);
    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        Vector2f newPos(zombie.getCenter());
        newPos.x = newPos.x - (KB_SPEED * elapsedMS);
        zombie.setCenter(newPos);
    }
    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        Vector2f newPos(zombie.getCenter());
        newPos.x = newPos.x - (KB_SPEED * elapsedMS);
        zombie.setCenter(newPos);
    }
}

int main()
{

    //loading in background image
    string background = "gameimages_final/graveyard.png";
    Texture backgroundTex;
    //if fails
    if (!backgroundTex.loadFromFile(background)) {
        cout << "Couldn't Load Image" << endl;
        exit(1);
    }

    //loading in zombie start point image
    PhysicsSprite& WalkLeft2 = *new PhysicsSprite();
    Texture wl2Tex;
    LoadTex(wl2Tex, "gameimages_final/WalkLeft2.png");
    WalkLeft2.setTexture(wl2Tex);
    Vector2f sz = WalkLeft2.getSize();
    WalkLeft2.setCenter(Vector2f(400, 600 - (sz.y)));



    //setting boundaries i think?                                                                yes?
    Image backgroundImage;
    backgroundImage = backgroundTex.copyToImage();


    //window display
    RenderWindow window(VideoMode(2000,1396),"Grrrr... Brains...");
    window.draw(WalkLeft2);

    Sprite sprite1;
    Texture text1;
    text1.loadFromImage(backgroundImage);
    sprite1.setTexture(text1);
    window.clear();
    window.draw(sprite1);
    window.display();
    while (true);
 
}

