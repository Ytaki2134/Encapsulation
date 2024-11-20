// Encapsulation.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <SDL.h>
#include <raylib.h>

#include "Src/Window/Window.h"
#include "Src/Sprite/Sprite.h"
#include "QuadTree.h"

int random_int(int min, int max)
{
	return min + rand() % (max + 1 - min);
}

int main(int argc, char** args)
{
	//Change Desired Library Here
	Library currentLibrary = SDL;
	GameModeType currentGamemode = BOUNCING_BALLS;

	Window* win = Window::MakeWindow("Encapsulation", 400, 400, currentLibrary);
	win->Init(&currentGamemode);
	win->Open();

	while (win->IsOpen() == 0)
	{
		win->Clear();
		win->Update();
		win->Draw();
	}
	return 0;
}

