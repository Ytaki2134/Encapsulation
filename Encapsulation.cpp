// Encapsulation.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include"WindowRayLib.h"
//#include"WindowSDL.h"
#include"raylib.h"

int main()
{
    WindowRayLib window;
    window.Open();
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        window.Clear();
    }

	return 0;
}
