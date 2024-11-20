// Encapsulation.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <SDL.h>
#include <raylib.h>
#include "Src/Core/App.h"
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
		win->Update();

		////QUADTREE
		//QTRectangle QTrectangle(0, 0, 400, 400);
		//QuadTree quadtree(&QTrectangle, 4);

		//for (int i = 0; i < 500; i++)
		//{
		//	QTPoint p(random_int(0, 400), random_int(0, 400));
		//	quadtree.Insert(p);
		//}
		//quadtree.Show(static_cast<WindowSDL*>(win));
		//system("pause");
		//std::cout << "trash" << std::endl;
		win->Clear();
		win->Draw();
	}

	return 0;
}

