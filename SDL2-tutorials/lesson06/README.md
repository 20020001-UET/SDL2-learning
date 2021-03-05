# Lesson 06
[Lesson source link here!](https://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/index2.php)

### Table of contents
  [Introduction](#introduction)  
  [Files](#files)  
  [Summary](#summary) 
  
## Introduction
SDL_image library setup.
Using SDL_image to load PNG image.

## Files
- **Source files:**
  - lesson06.cpp
- **Assets:**
  - loaded.bmp

## Summary
### Setup SDL_image library
[The tutorial here!](https://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/index.php)

### Using SDL_image library
To use any **SDL_image function or data types**, we need to **include the SDL_image header**. 
The same with **SDL_ttf** and **SDL_mixer**.
```C++
#include <SDL.h>
#include <SDL_image.h>
```

### Initialize SDL_image
```C++
            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                success = false;
            }
```
Here we want to **initialize SDL_image** with **PNG loading**, so we pass in **the PNG loading flags** into **IMG_Init**. <br>

**[IMG_Init](https://www.libsdl.org/projects/SDL_image/docs/SDL_image_8.html)**
```C++
int IMG_Init(int flags)
```
- flags: _bitwise OR'd set of image formats to support by loading a library now._ 
- The values you may **OR together to pass in** are:
  - **IMG_INIT_JPG**
  - **IMG_INIT_PNG**
  - **IMG_INIT_TIF**
  
When there's **an error with SDL_image**, you **get error string** with **IMG_GetError** as opposed to **SDL_GetError.** <br>

**[IMG_GetError](https://www.libsdl.org/projects/SDL_image/docs/SDL_image_45.html)**
```C++
char *IMG_GetError()
```
- This is **the same as SDL_GetError.**

### Load image with SDL_image
```C++
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
```

**[IMG_Load](https://www.libsdl.org/projects/SDL_image/docs/SDL_image_11.html)**
```C++
SDL_Surface *IMG_Load(const char *file)
```
- file: _Image file name to load a surface from._
- **IMG_Load** can **load many different types of format**

