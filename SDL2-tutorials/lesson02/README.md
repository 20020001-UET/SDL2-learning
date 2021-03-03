# Lesson 02
[Lesson source link here!](https://lazyfoo.net/tutorials/SDL/02_getting_an_image_on_the_screen/index.php)

### Table of contents
  [Introduction](#introduction)  
  [Files](#files)  
  [Noted](#noted)  
  [Summary](#summary) 
  
## Introduction
**Put an image on the window.**

## Files
- **Source files:**
  - lesson02.cpp
- **Assets:**
  - hello_world.bmp

## Noted

### Main functions

- **Initialization**
  ```C++
  bool init();
  ```
  - Initialize SDL
  - Create window
  - Get window surface
  
- **Loading media**
  ```C++
  bool loadMedia();
  ```
  - Load image
  
- **Closing down the SDL application**
   ```C++
   void close();
   ```
  - Deallocate surface
  - Destroy window
  - Quit SDL subsystems

### Getting an image on the screen

- Initialize SDL and load the image.
  - Load the image: (_**to SDL_surface**_)
    ```C++
    //Load splash image
    gHelloWorld = SDL_LoadBMP( "02_getting_an_image_on_the_screen/hello_world.bmp" );
    ```
    or
    ```C++
    //Load splash image
    gHelloWorld = SDL_LoadBMP( "hello_world.bmp" );
    ```
    **Noted:** _Working directories function differently from OS to OS and IDE to IDE._
  - Blit the loaded surface: (_onto the screen surface_)  
    **[SDL_BlitSurface](http://wiki.libsdl.org/SDL_BlitSurface)**
    ```C++
    int SDL_BlitSurface(SDL_Surface*    src,
                    const SDL_Rect* srcrect,
                    SDL_Surface*    dst,
                    SDL_Rect*       dstrect)
    ```
    **SDL_BlitSurface _take a source surface and stamps a copy of it onto the destination surface_.**
  - **Noted:** _After drawing everything on the screen, we have to update the screen using **SDL_UpdateWindowSurface** in order to show that frame!_

## Summary
