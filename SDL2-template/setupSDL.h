//setupSDL [header]
#ifndef SETUP_SDL
#define SETUP_SDL

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

///main constance

// initSDL
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const std::string WINDOW_TITLE = "SDL work!";

///main setup

// logSDLError
void logSDLError(std::ostream& os,
                const std::string &msg, bool fatal = false);

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

// quitSDL
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

///function setup

// waitUntilKeyPressed
void waitUntilKeyPressed();

// loadMedia
void loadMedia();

#endif // SETUP_SDL



