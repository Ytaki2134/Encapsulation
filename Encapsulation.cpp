// Encapsulation.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Window.h"
#include "Sprite.h"

int main(int argc, char** args)
{
    Window* win = new Window("Encapsulation", 800, 800, SDL);
    win->Open();
}
