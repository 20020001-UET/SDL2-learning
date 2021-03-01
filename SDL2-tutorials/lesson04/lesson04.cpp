//Using SDL and iostream
#include <SDL.h>
#include <iostream>

//Using string
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Key press surface constants
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image that correspond to a keypress
SDL_Surface* gKeyPressSurface[KEY_PRESS_SURFACE_TOTAL];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;

int main(int argc, char* args[])
{
    //Start up SDL and create window
    if (!init())
    {
        std::cout << "Falled to initialize!\n";
    }
    else
    {

        //Load media
        if (!loadMedia())
        {
            std::cout << "Failed to load media\n";
        }
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //Set default current surface
            gCurrentSurface = gKeyPressSurface[KEY_PRESS_SURFACE_DEFAULT];

            //While application is running
            while (!quit)
            {
                //Handle events on queue
                while (SDL_PollEvent(&e) != 0)
                {
                    //User requests quit
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }

                    //User pressed a key
                    else if (e.type == SDL_KEYDOWN)
                    {
                        //Select surface based on key press
                        switch (e.key.keysym.sym)
                        {
                            case SDLK_UP:
                                gCurrentSurface = gKeyPressSurface[KEY_PRESS_SURFACE_UP];
                                break;
                            case SDLK_DOWN:
                                gCurrentSurface = gKeyPressSurface[KEY_PRESS_SURFACE_DOWN];
                                break;
                            case SDLK_LEFT:
                                gCurrentSurface = gKeyPressSurface[KEY_PRESS_SURFACE_LEFT];
                                break;
                            case SDLK_RIGHT:
                                gCurrentSurface = gKeyPressSurface[KEY_PRESS_SURFACE_RIGHT];
                                break;
                            default:
                                gCurrentSurface = gKeyPressSurface[KEY_PRESS_SURFACE_DEFAULT];
                                break;
                        }
                    }
                }

                //Apply the image
                SDL_BlitSurface(gCurrentSurface,
                                NULL,
                                gScreenSurface,
                                NULL);

                //Update the surface
                SDL_UpdateWindowSurface(gWindow);
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}

SDL_Surface* loadSurface(std::string path)
{
    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if (loadedSurface == NULL)
    {
        std::cout << "Unable to load image " << path.c_str() << "! SDL_Error: " << SDL_GetError();
    }

    return loadedSurface;
}

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError();
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial",
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SCREEN_WIDTH,
                                   SCREEN_HEIGHT,
                                   SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            std::cout << "Window could not be created! SDL_Error: " << SDL_GetError();
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load default surface
    gKeyPressSurface[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("press.bmp");
    if (gKeyPressSurface[KEY_PRESS_SURFACE_DEFAULT] == NULL)
    {
        std::cout << "Failed to load default image!\n";
        success = false;
    }

    //Load up surface
    gKeyPressSurface[KEY_PRESS_SURFACE_UP] = loadSurface("up.bmp");
    if (gKeyPressSurface[KEY_PRESS_SURFACE_UP] == NULL)
    {
        std::cout << "Failed to load up image!\n";
        success = false;
    }

    //Load down surface
    gKeyPressSurface[KEY_PRESS_SURFACE_DOWN] = loadSurface("down.bmp");
    if (gKeyPressSurface[KEY_PRESS_SURFACE_DOWN] == NULL)
    {
        std::cout << "Failed to load down image!\n";
        success = false;
    }

    //Load left surface
    gKeyPressSurface[KEY_PRESS_SURFACE_LEFT] = loadSurface("left.bmp");
    if (gKeyPressSurface[KEY_PRESS_SURFACE_LEFT] == NULL)
    {
        std::cout << "Failed to load left image!\n";
        success = false;
    }

    //Load right surface
    gKeyPressSurface[KEY_PRESS_SURFACE_RIGHT] = loadSurface("right.bmp");
    if (gKeyPressSurface[KEY_PRESS_SURFACE_RIGHT] == NULL)
    {
        std::cout << "Failed to load right image!\n";
        success = false;
    }

    return success;
}

void close()
{
    //Deallocate surfaces
    for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i)
    {
        SDL_FreeSurface(gKeyPressSurface[i]);
        gKeyPressSurface[i] = NULL;
    }

    //Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    //Quit SDL Subsystems
    SDL_Quit();
}
