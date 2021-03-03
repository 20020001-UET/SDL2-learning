# Lesson 08
[Lesson source link here!](https://lazyfoo.net/tutorials/SDL/08_geometry_rendering/index.php)

### Table of contents
  [Introduction](#introduction)  
  [Files](#files)  
  [Noted](#noted)  
  [Summary](#summary) 
  
## Introduction

  According to **lazyfoo.net**, along with the _new texturing API_, SDL has new **primitive rendering calls as part of its rendering API.**
  So if you need **some basic shapes rendered and you don't want to create additional graphics for them**, SDL can save you the effort.

## Files

- **Source files:**
  - lesson08.cpp

## Noted

### 2D Accelerated Rendering
  **[SDL_render.h](http://wiki.libsdl.org/CategoryRender)** <br>
  Draw some basic shapes rendered.
 
### Clear screen
  ```c++
   //Clear screen
  SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear( gRenderer );
  ```
  - [SDL_RenderClear](http://wiki.libsdl.org/SDL_RenderClear)  
    ```C++
    int SDL_RenderClear(SDL_Renderer* renderer)
    ```
  - [SDL_SetRenderDrawColor](http://wiki.libsdl.org/SDL_SetRenderDrawColor)
    ```C++
    int SDL_SetRenderDrawColor(SDL_Renderer* renderer,
                             Uint8         r,
                             Uint8         g,
                             Uint8         b,
                             Uint8         a)
    ```
    
### SDL Rectangle
  - [SDL_Rect](http://wiki.libsdl.org/SDL_Rect)  
    The member variables that make up an SDL rect are **x**, **y**, **w**, and **h** for the **x position**, **y position**, **width**, and **height**.
    **The x and y positions are the location of the rectangle's upper left corner**.
    
  - [SDL_RenderFillRect](http://wiki.libsdl.org/SDL_RenderFillRect) 
    ```C++
    int SDL_RenderFillRect(SDL_Renderer*   renderer,
                       const SDL_Rect* rect)
    ```
    
### SDL coordinate system
  - The **[Cartesian coordinate system](https://en.wikipedia.org/wiki/Cartesian_coordinate_system)**: _Where the x axis points to the right, the y axis points up, and the origin is in the bottom left corner._
  - **SDL** uses a different coordinate system: **The x axis still points to the right, but the y axis points down and the origin is in the top left.**

### SDL Draw
  - [SDL_RenderDrawLine](http://wiki.libsdl.org/SDL_RenderDrawLine)
    ```C++
    int SDL_RenderDrawLine(SDL_Renderer* renderer,
                       int           x1,
                       int           y1,
                       int           x2,
                       int           y2)
    ```
  - [SDL_RenderDrawPoint](http://wiki.libsdl.org/SDL_RenderDrawPoint)
    ```C++
    int SDL_RenderDrawPoint(SDL_Renderer* renderer,
                        int           x, 
                        int           y)
    ```

## Summary

