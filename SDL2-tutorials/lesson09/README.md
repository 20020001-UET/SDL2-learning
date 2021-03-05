# Lesson 09
[Lesson source link here!](https://lazyfoo.net/tutorials/SDL/09_the_viewport/index.php)

### Table of contents
  [Introduction](#introduction)  
  [Files](#files)  
  [Summary](#summary) 
  
## Introduction
Some times you only want to render part of the screen for things like minimaps. 
Using the viewport you can control where you render on the screen.

## Files
- **Source files:**
  - lesson09.cpp
- **Assets:**
  - viewport.png

## Summary
### Define a Viewport
Using **SDL_Rect** to creating a rectangle and passing this region to **SDL_RenderSetViewport**. <br>
Any rendering done after that call will render inside that region defined by the given viewport. <br>

**Example**
  - Top left corner Viewport:
  ```C++
                  //Top left corner viewport
                  SDL_Rect topLeftViewport;
                  topLeftViewport.x = 0;
                  topLeftViewport.y = 0;
                  topLeftViewport.w = SCREEN_WIDTH / 2;
                  topLeftViewport.h = SCREEN_HEIGHT / 2;
                  SDL_RenderSetViewport( gRenderer, &topLeftViewport );
  ```
  - Top right corner Viewport:
  ```C++
                  //Top right viewport
                  SDL_Rect topRightViewport;
                  topRightViewport.x = SCREEN_WIDTH / 2;
                  topRightViewport.y = 0;
                  topRightViewport.w = SCREEN_WIDTH / 2;
                  topRightViewport.h = SCREEN_HEIGHT / 2;
                  SDL_RenderSetViewport( gRenderer, &topRightViewport );
  ```
  - Bottom Viewport:
  ```C++
                  //Bottom viewport
                  SDL_Rect bottomViewport;
                  bottomViewport.x = 0;
                  bottomViewport.y = SCREEN_HEIGHT / 2;
                  bottomViewport.w = SCREEN_WIDTH;
                  bottomViewport.h = SCREEN_HEIGHT / 2;
                  SDL_RenderSetViewport( gRenderer, &bottomViewport );
  ```
 
 ### SDL Viewport
 **[SDL_RenderSetViewport](http://wiki.libsdl.org/SDL_RenderSetViewport)**
 ```C++
 int SDL_RenderSetViewport(SDL_Renderer*   renderer,
                           const SDL_Rect* rect)
 ```
 Set the drawing area for rendering on the current target.
