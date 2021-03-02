# Lesson 01

### Table of contents
  [Introduction](#introduction)  
  [Files](#files)  
  [Noted](#noted)  
  [Summary](#summary) 
  
## Introduction

  According to **lazyfoo.net**, this tutorial covers the first major stepping stone: **getting a window to pop up.**

## Files

- **Source files:** 
  - _lesson01.cpp_  

## Noted

### At the top of the source file: 
- **Include SDL**  
  ```C++
  #include <SDL.h>
  ```
  In order to use ***SDL functions and datatypes to make any SDL code.***

- **Include iostream** to **cout** errors to the console.

### **In main function:**
```C++
int main(int argc, char* argv[])
```
The arguments of the function be an integer followed by a char* array and the return type be an integer.  
_**Any other type of main function will cause an underfined reference to main!**_  
SDL requires this type of main so **it is compatible with multiple platforms.**
  
- **SDL_window**  
  The window that we're going to render to.
  
- **[SDL_surface](https://wiki.libsdl.org/SDL_Surface)**  
  A screen SDL surface is just a 2D image. A 2D image can be loaded from a file or it can be the image inside of a window.  
  
- **Initialize SDL:**  
  - **[SDL_Init](https://wiki.libsdl.org/SDL_Init)**
     ```C++
     SDL_Init( SDL_INIT_VIDEO )
     ```
     **You can't call any SDL function without initialize SDL first!**  
  - **SDL_INIT_VIDEO** flag: _video subsystem; automatically initializes the events subsystem_.
  - When there's an error, **SDL_Init** returns -1.
  
- **[SDL_GetError](https://wiki.libsdl.org/SDL_GetError)**
  ```C++
  const char* SDL_GetError(void)
  ```
  **SDL_GetError** returns the lastest error produced by an SDL function.

- **[SDL_CreateWindow](https://wiki.libsdl.org/SDL_CreateWindow)** 
  ```C++
  SDL_Window* SDL_CreateWindow(const char* title,
                               int         x,
                               int         y,
                               int         w,
                               int         h,
                               Uint32      flags)
  ```
  - The first argument **sets the window's caption.**  
  - The next two arguments **define the x and y position the window is created in.**  
  - The next two arguments **define the window's width and height.**
  - The last argument are the **creation flags.**
    - **SDL_WINDOW_SHOWN**: the window is shown when it is created.
  
- **[SDL_FillRect](https://wiki.libsdl.org/SDL_FillRect)**
  ```C++
  int SDL_FillRect(SDL_Surface*    dst,
                 const SDL_Rect* rect,
                 Uint32          color)
  ```
  
- **[SDL_UpdateWindowSurface](https://wiki.libsdl.org/SDL_UpdateWindowSurface)**
  ```C++
  int SDL_UpdateWindowSurface(SDL_Window* window)
  ```
  
- **[SDL_Delay](https://wiki.libsdl.org/SDL_Delay)**
  ```C++
  void SDL_Delay(Uint32 ms)
  ```
- **[SDL_DestroyWindow](https://wiki.libsdl.org/SDL_DestroyWindow)**
  ```C++
  void SDL_DestroyWindow(SDL_Window* window)
  ```
  
- **[SDL_Quit](https://wiki.libsdl.org/SDL_Quit)**
  ```C++
  void SDL_Quit(void)
  ```

## Summary

