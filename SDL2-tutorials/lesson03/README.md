# Lesson 03
[Lesson source link here!](https://lazyfoo.net/tutorials/SDL/03_event_driven_programming/index.php)

### Table of contents
  [Introduction](#introduction)  
  [Files](#files)  
  [Summary](#summary) 
  
## Introduction

Besides just _putting images on the screen_, games require that **you handle input from the user**. 
You can do that with SDL using the **event handling system**.

## Files

- **Source files:**
  - lesson03.cpp
- **Assets:**
  - x.bmp

## Summary

### Main loop 
The window frame loop.
```C++
//Main loop flag
bool quit = false;

//Event handler
SDL_Event e;

//While application is running
while( !quit )
{
  //Handle events on queue
  while( SDL_PollEvent( &e ) != 0 )
  {
      //User requests quit
      if( e.type == SDL_QUIT )
      {
          quit = true;
      }
  }
  //Apply the image
  SDL_BlitSurface( gXOut, NULL, gScreenSurface, NULL );

  //Update the surface
  SDL_UpdateWindowSurface( gWindow );
}
```
- Declare a quit flag that keeps track of whether the user has quit or not.
  ```C++
  //Main loop flag
  bool quit = false;
  ```
  
- Declare an **SDL_Event** union to** handle input from user.**
  The application wait until the user quits.
  ```C++
  //Handle events on queue
  while( SDL_PollEvent( &e ) != 0 )
  {
      //User requests quit
      if( e.type == SDL_QUIT )
      {
          quit = true;
      }
  }
  ```
  This loop is called the **main loop**, which is sometimes called the **game loop**.

### SDL Event
**[SDL_Event](http://wiki.libsdl.org/SDL_Event)**  
SDL Event is some thing like: 
  - [Key press](http://wiki.libsdl.org/SDL_KeyboardEvent?highlight=%28\bCategoryStruct\b%29|%28CategoryEvents%29)
  - [Mouse motion](http://wiki.libsdl.org/SDL_MouseMotionEvent?highlight=%28\bCategoryStruct\b%29|%28CategoryEvents%29)
  - [Joy button press](http://wiki.libsdl.org/SDL_JoyButtonEvent?highlight=%28\bCategoryStruct\b%29|%28CategoryEvents%29)

When you press a key, move the mouse, or touch a touch screen you put events onto **the event queue**.  
**The event queue** will then **store them in the order the events occured** waiting for you to process them.

- **[SDL_PollEvent](http://wiki.libsdl.org/SDL_PollEvent)**
  ```C++
  int SDL_PollEvent(SDL_Event* event)
  ```
  - Poll the event queue to **get the most recent event.**
  - **SDL_PollEvent** will _keep taking events off the queue until it is empty. _
  - When the queue is empty, **SDL_PollEvent will return 0.**
  
- **[SDL_QUIT](http://wiki.libsdl.org/SDL_QuitEvent)** event:
  - The event when the **user Xs out the window.**
  - Set **the quit flag to true** in order to **quit the main loop.**
  - So we can** exit the application.**

