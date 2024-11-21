// Encapsulation.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <SDL.h>
#include <raylib.h>

#include "Src/Window/Window.h"
#include "Src/Sprite/Sprite.h"
#include "Src/Physics/QuadTree.h"

int random_int(int min, int max)
{
	return min + rand() % (max + 1 - min);
}

int main(int argc, char** args)
{
	//Change Desired Library Here
	Library currentLibrary = RAYLIB;
	GameModeType currentGamemode = BOUNCING_BALLS;
	int fps = 60;

	Window* win = Window::MakeWindow("Encapsulation", 410, 410, currentLibrary,fps);
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

