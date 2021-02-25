//setupSDL [source]
#include "setupSDL.h"

///main setup

// logSDLError
void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << "Error: " << SDL_GetError() << std::endl;
    if (fatal)
    {
        SDL_Quit();
        exit(1);
    }
}

// initSDL
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    //CreateWindow
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(),
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    /*
    window = SDL_CreateWindow(WINDOW_TITLE.c_str(),
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_FULLSCREEN_DESKTOP);
    */

    if (window == nullptr)
        logSDLError(std::cout, "CreateWindow", true);


    //CreateRenderer
    //PC - Lap
    renderer = SDL_CreateRenderer(window, -1,
                                  SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC);
    //Virtual machine (VM)
    /*
    renderer = SDL_CreateRenderer(SDL_GetWindowSurface(window));
    */

    if (renderer == nullptr)
        logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

// quitSDL
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    //Destroy renderer
    SDL_DestroyRenderer(renderer);

    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();
}

///function setup

// waitUntilKeyPressed
void waitUntilKeyPressed()
{
    SDL_Event e;
    while(true)
    {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100); //ms
    }
}

