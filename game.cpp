#include "game.h"

SDL_Texture * doge;

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen)
{
	int flags = 0;

	if (fullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		printf("Game Initialized successfully..\n");
		win = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (win) { printf("Window Created..\n"); }
		ren = SDL_CreateRenderer(win, -1, 0);
		if (ren)
		{
			SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
			printf("Renderer Created..\n");
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	SDL_Surface * tempSurface = IMG_Load("assets/animate-alpha.png");
	doge = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);

  m_sourceRectangle.w = 128; // 실제 이미지의 크기가 아닌 고정 상수값
m_sourceRectangle.h = 82;

m_destinationRectangle.x = m_sourceRectangle.x = 0;
m_destinationRectangle.y = m_sourceRectangle.y = 0;
m_destinationRectangle.w = m_sourceRectangle.w;
m_destinationRectangle.h = m_sourceRectangle.h;
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch(event.type)
	{
		case SDL_QUIT:
		isRunning = false;
		break;

    case SDL_KEYDOWN:
    isRunning = false;
    printf("key down\n");
    break;

		default:
		break;
	}
}

void Game::update()
{
	//count++;
	//printf("\033[0GGame Cycles: %i", count);
  m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
  m_destinationRectangle.x++;
}

void Game::render()
{
	SDL_RenderClear(ren);

	SDL_RenderCopy(ren, doge, &m_sourceRectangle, &m_destinationRectangle);

	SDL_RenderPresent(ren);
}

void Game::clean()
{
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_Quit();
	printf("Mess Cleaned Up.\n");
}
