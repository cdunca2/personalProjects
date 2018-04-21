#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

using namespace std;

const int S_WIDTH = 640;
const int S_HEIGHT = 480;

/*enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};*/

bool init();
void close();
bool loadMedia();

SDL_Texture* loadTexture(string fname);
SDL_Surface* loadSurface(string fname);

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* texture = NULL;

bool init()
{
	bool success = true;

	// Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL failed to initalize.  Error: " << SDL_GetError() << endl;
		success = false;
	}
	else {
		// Create the window
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, S_WIDTH, S_HEIGHT, SDL_WINDOW_SHOWN );
		if(window == NULL) {
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else {
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if(renderer == NULL) {
				cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
				success = false;
			}
			else {
				SDL_SetRenderDrawColor(renderer, 0xFF,0xFF,0xFF,0xFF);
				// Initialize PNG loading via SDL_image
				int imgFlags = IMG_INIT_PNG;
				if(!(IMG_Init(imgFlags) & imgFlags)) {
					cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
					success = false;
				}
			}
		}
	}

	return success;
}

void close()
{
	// Free (all) loaded image(s)
	SDL_DestroyTexture(texture);
	texture = NULL;

	// Destroy the renderer
	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	// Destroy the window
	SDL_DestroyWindow(window);
	window = NULL;

	// GET OUT
	IMG_Quit();
	SDL_Quit();
}

bool loadMedia(char* fname)
{
	//Loading success flag
	bool success = true;

	texture = loadTexture("resources/texture.png");
	if(texture == NULL) {
		cout << "Failed to load texture image!" << endl;
		success = false; 
	}

	return success;
}

/*SDL_Surface* loadSurface(string fname)
{
	SDL_Surface* optiSurface = NULL;
	SDL_Surface* newSurface = IMG_Load(fname.c_str());

	if(newSurface == NULL)
		cout << "Unable to load image '" << fname << "' ; SDL Error: " << SDL_GetError() << endl;
	else {
		optiSurface = SDL_ConvertSurface(newSurface, SDL_GetWindowSurface(window)->format, NULL);
		if(optiSurface == NULL)
			cout << "Unable to optimize image '" << fname << "' ; SDL Error: " << SDL_GetError() << endl;

		SDL_FreeSurface(newSurface);
	}

	return optiSurface;
}*/

SDL_Texture* loadTexture(string fname)
{
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(fname.c_str());
	if(loadedSurface == NULL)
		cout << "Unable to load image " << fname << "! SDL_image Error: " << IMG_GetError() << endl;
	else {
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if(newTexture == NULL)
			cout << "Unable to create texture from " << fname << "! SDL Error: " << SDL_GetError() << endl;
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

int main(int argc, char* argv[])
{
	if(!init())
		cout << "failed to initialize" << endl;
	else {
		if(!loadMedia(argv[1]))
			cout << "failed to load media" << endl;
		else {
			bool quit = false;
			SDL_Event e;

			while(!quit) {
				while(SDL_PollEvent(&e) != 0) {
					// If user requests to exit
					if(e.type == SDL_QUIT)
						quit = true;
				}

				SDL_RenderClear(renderer);

				SDL_RenderCopy(renderer, texture, NULL, NULL);

				SDL_RenderPresent(renderer);
			}
		}
	}

	close();

	return 0;
}
