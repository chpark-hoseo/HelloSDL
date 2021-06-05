#pragma once

#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Game
{
	public:
		Game();
		~Game();

		void init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);
		void handleEvents();
		void update();
		void render();
		void clean();

		inline bool running() { return isRunning; };

	private:
		bool isRunning;
		int count;
		SDL_Window * win;
		SDL_Renderer * ren;

    SDL_Rect m_sourceRectangle;
    SDL_Rect m_destinationRectangle;
};