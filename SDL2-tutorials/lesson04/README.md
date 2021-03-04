# Lesson 04
[Lesson source link here!](https://lazyfoo.net/tutorials/SDL/04_key_presses/index.php)

### Table of contents
  [Introduction](#introduction)  
  [Files](#files)  
  [Summary](#summary) 
  
## Introduction
In this tutorial we're going to make different images appear depending on which key you press.

## Files
- **Source files:**
  - lesson04.cpp
- **Assets:**
  - press.bmp
  - up.bmp
  - down.bmp
  - left.bmp
  - right.bmp

## Summary

### Key press surface constants
```C++
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};
```

Enumerations are a shorthand way to do symbolic constants instead of having to do:
```C++
const int KEY_PRESS_SURFACE_DEFAULT = 0;
const int KEY_PRESS_SURFACE_UP = 1;
const int KEY_PRESS_SURFACE_DOWN = 2;
...
```

They default to start couting at 0 and go up by one for each enumeration you declare.
This means:
  - KEY_PRESS_SURFACE_DEFAULT = 0
  - KEY_PRESS_SURFACE_UP = 1
  - KEY_PRESS_SURFACE_DOWN = 2
  - KEY_PRESS_SURFACE_LEFT = 3
  - KEY_PRESS_SURFACE_RIGHT = 4
  - KEY_PRESS_SURFACE_TOTAL = 5

**Noted:** One bad habit begining programmers have is using **abritary numbers** instead of **symbolic constants.**

### loadSurface
A new function called **loadSurface**:
```C++
SDL_Surface* loadSurface(std::string path)
{
    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    return loadedSurface;
}
```

**Noted:** There's a general rule that if **you're copy/pasting code, you're doing something wrong.**  
Rather than **copy/paste loading code everytime,** **we're going to use a function to handle that!**

### Handle key presss event
```C++
                    //User presses a key
                    else if( e.type == SDL_KEYDOWN )
                    {
                        //Select surfaces based on key press
                        switch( e.key.keysym.sym )
                        {
                            case SDLK_UP:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                            break;

                            case SDLK_DOWN:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                            break;

                            case SDLK_LEFT:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                            break;

                            case SDLK_RIGHT:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                            break;

                            default:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                            break;
                        }
                    }
```
**[SDL_KEYDOWN](https://wiki.libsdl.org/SDL_KeyboardEvent)**
This event happens when ever you press a key on the keyboard.

- Inside of the **SDL_Event** is an **SDL_KeyboardEvent** -> _**contains the information for the key event.**_  
- Inside of that is a **[SDL Keysym](https://wiki.libsdl.org/SDL_Keysym)** -> _**contains the information about the key that was pressed.**_  
- **Keysym** contains the **[SDL_Keycode](https://wiki.libsdl.org/SDL_Keycode)** -> _**identifies the key that was pressed.**_
