# Lesson 05
[Lesson source link here!](https://lazyfoo.net/tutorials/SDL/05_optimized_surface_loading_and_soft_stretching/index.php)

### Table of contents
  [Introduction](#introduction)  
  [Files](#files)  
  [Summary](#summary) 
  
## Introduction
When you're making a game, blitting images raw causes needless slow down. 
We'll be converting them to an optimized format to speed them up.  
SDL 2 also has a new feature for SDL surfaces called soft stretching, which allows you to blit an image scaled to a different size.

## Files
- **Source files:**
  - lesson05.cpp
- **Assets:**
  - stretch.bmp

## Summary
### Why do we need to optimized surface loading image before blit it?
When you're load a bitmap, it's typically loaded in a 24bit format since most bitmap are 24bit. 
Most is not all, modern displays are not 24bit by default. 
If we blit that's 24bit onto a 32bit image, **SDL will convert it every time the image is blitted.**

So what we're going to do when an image is loaded **is convert it to the same format as the screen** -> **no conversion needs to be done on blit.**
```C++
    //Convert surface to screen format
    optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
```

- **Pass in the surface we want to convert with the format of the screen.**
- **[SDL_ConvertSurface](https://wiki.libsdl.org/SDL_ConvertSurface)**
  ```C++
  SDL_Surface* SDL_ConvertSurface(SDL_Surface*           src,
                                  const SDL_PixelFormat* fmt,
                                  Uint32                 flags)
  ```
- **Noted:** **SDL_ConvertSurface returns a copy of the original in a new format.** 
  The original loaded image is still in memory after this call.
  -> **We have to free the original loaded surface** or **we'll have two copies of the same image in memory**.

### Soft stretching
```C++
          //Apply the image stretched
          SDL_Rect stretchRect;
          stretchRect.x = 0;
          stretchRect.y = 0;
          stretchRect.w = SCREEN_WIDTH;
          stretchRect.h = SCREEN_HEIGHT;
          SDL_BlitScaled( gStretchedSurface, NULL, gScreenSurface, &stretchRect );
```
- **[SDL_BlitScaled](https://wiki.libsdl.org/SDL_BlitScaled)**
  ```C++
  int SDL_BlitScaled(SDL_Surface*    src,
                     const SDL_Rect* srcrect,
                     SDL_Surface*    dst,
                     SDL_Rect*       dstrect)
  ```
  - A function to blit images to a different size.
- **SDL_BlitScaled** takes in a **source surface to blit onto the destination surface**.
- It also takes in a **destination SDL_Rect** -> defines the **position and size of the image** you are blitting.
