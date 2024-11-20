// Encapsulation.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <SDL.h>
#include <raylib.h>

#include "Src/Window/Window.h"
#include "Src/Sprite/Sprite.h"

int main(int argc, char** args)
{
	//Change Desired Library Here
	Library currentLibrary = RAYLIB;
	GameModeType currentGamemode = BOUNCING_BALLS;

	Window* win = Window::MakeWindow("Encapsulation", 800, 600, currentLibrary);
	win->Init(&currentGamemode);
	win->Open();
	while (!win->IsOpen()) {
		win->Update();
		win->Draw();
	}
	return 0;
}
