# SDL2 Template
Codeblock SDL2 project template.

### Introduction

Compiler **64-bit.** <br>
SDL2 library: **x86_64-w64-mingw32** <br>

## Setup
**Include header files:**
- SDL2
- SDL2_image
- SDL2_mixer

**Library files:** (/lib)
- SDL2
- SDL2_image
- SDL2_mixer

**Linker:** 
- -lmingw32 
- -lSDL2main 
- -lSDL2 
- -lSDL2_image 
- -lSDL2_mixer

**Dll files:**
- SDL2.dll
- SDL2_image.đll
- SDL2_mixer.dll

## setupSDL.h
This header will help you use the SDL2 lib easier. <br>
Based on source: [ltncvnu (UET)](https://sites.google.com/site/ltncvnu/home)

logSDLError: Sends an error message to ostream& os <br>
```c++
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
```

initSDL: Create window and renderer
```c++
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
```

quitSDL: Destroy renderer and window, quit the SDL subsystems
```c++
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    //Destroy renderer
    SDL_DestroyRenderer(renderer);

    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();
}
```

waitUntilKeyPressed: Handle key pressed event
```c++
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
```
