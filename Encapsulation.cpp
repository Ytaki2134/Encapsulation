// Encapsulation.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <SDL.h>
#include <iostream>
#include <raylib.h>
#include "App.h"
#include "Window.h"
#include "Sprite.h"

int main(int argc, char** args)
{
	App app;
	//Change Desired Library Here
	Library currentLibrary = SDL;

	Window* win = Window::MakeWindow("Encapsulation", 800, 600, currentLibrary);
	win->Init();
	win->Open();

	switch (currentLibrary)
	{
	case SDL:
		while (app.IsAppRunning())
		{
			app.EventLoop();
		}
		break;

	case RAYLIB:
		while (!WindowShouldClose())
		{
			win->Draw();
		}
		break;

	default:
		//todo
		break;
	}

	return 0;
}
