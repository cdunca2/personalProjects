#include <SDL2/SDL.h>
#include <iostream>
#include <string>

using namespace std;

const int S_WIDTH = 640;
const int S_HEIGHT = 480;

enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

bool init();
void close();
bool loadMedia();
SDL_Surface* loadSurface(string fname);

SDL_Window* window = NULL;
SDL_Surface* surface = NULL;
SDL_Surface* currentSurface = NULL;
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

bool init()
{
	bool success = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL failed to initalize.  Error: " << SDL_GetError() << endl;
		success = false;
	}
	else {
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, S_WIDTH, S_HEIGHT, SDL_WINDOW_SHOWN );
		if(window == NULL) {
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
			surface = SDL_GetWindowSurface(window);
	}

	return success;
}

void close()
{
	for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i )
	{
		SDL_FreeSurface( gKeyPressSurfaces[ i ] );
		gKeyPressSurfaces[ i ] = NULL;
	}

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}

bool loadMedia(char* fname)
{
	//Loading success flag
	bool success = true;

	//Load default surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "press.bmp" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL )
	{
		printf( "Failed to load default image!\n" );
		success = false;
	}

	//Load up surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface( "up.bmp" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL )
	{
		printf( "Failed to load up image!\n" );
		success = false;
	}

	//Load down surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface( "down.bmp" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL )
	{
		printf( "Failed to load down image!\n" );
		success = false;
	}

	//Load left surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( "left.bmp" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL )
	{
		printf( "Failed to load left image!\n" );
		success = false;
	}

	//Load right surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "right.bmp" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
	{
		printf( "Failed to load right image!\n" );
		success = false;
	}

	return success;
}

SDL_Surface* loadSurface(string fname)
{
	SDL_Surface* optiSurface = NULL;
	SDL_Surface* newSurface = SDL_LoadBMP(fname.c_str());

	if(newSurface == NULL)
		cout << "Unable to load image '" << fname << "' ; SDL Error: " << SDL_GetError() << endl;
	else{
		optiSurface = SDL_ConvertSurface(newSurface, surface->format, NULL);
		if(optiSurface == NULL)
			cout << "Unable to optimize image '" << fname << "' ; SDL Error: " << SDL_GetError() << endl;

		SDL_FreeSurface(newSurface);
	}

	return optiSurface;
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

			currentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

			while(!quit) {
				while(SDL_PollEvent(&e) != 0) {
					if(e.type == SDL_QUIT)
						quit = true;
					else if(e.type == SDL_KEYDOWN) {
						switch(e.key.keysym.sym) {
							case SDLK_UP:
								currentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
							break;
							case SDLK_DOWN:
								currentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
							break;
							case SDLK_LEFT:
								currentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
							break;
							case SDLK_RIGHT:
								currentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
							break;
							default:
								currentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
							break;
						}
					}
				}
				SDL_BlitSurface(currentSurface, NULL, surface, NULL);
				SDL_UpdateWindowSurface(window);
			}
		}
	}

	close();

	return 0;
}
