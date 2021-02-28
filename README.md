# SDL2 Learning
Bá Lương - K65 UET  
SDL2 learning from **lazyfoo.net**

## Introduction
Beginning Game Programming with SDL2.  
**Source**: [SDL2 Turtorials](https://lazyfoo.net/tutorials/SDL/index.php)  
**SDL2 Wiki:** [SDL2 Wiki](https://wiki.libsdl.org/FrontPage)

### Table of Contents
**[Table of Lessons](#table-of-lessons)** <br>
**[Projects](#projects)** <br>
**[Notes](#notes)** <br>

## Table of Lessons
**Lesson** | **Contents** | **Check**
-------|----------|-------
**Lesson 01** - Hello SDL | _In this tutorial we will be setting up the SDL library and creating our first window._ | **done!**
**Lesson 02** - Getting an Image on the Screen | _Now that we can get a window to appear, lets blit an image onto it._ | **done!**
**Lesson 03** - Event Driven Programming | _Here we'll start handling user input by allowing the user to X out the window._ | **done!**
**Lesson 04** - Key Presses | _Here we'll learn to handle keyboard input._ |
**Lesson 05** - Optimized Surface Loading and Soft Stretching | _Now that we know how to load and blit surfaces, it's time to make our blits faster. We'll also take a smaller image and stretch it to fit the screen._ |
**Lesson 06** - Extension Libraries and Loading Other Image Formats | _Here we'll be using the SDL_image extension library to load png images._ |
**Lesson 07** - Texture Loading and Rendering | _A big new feature in SDL 2.0 is hardware accelerated texture based 2D rendering. Here we'll be loading an image to render it using textures._ |
**Lesson 08** - Geometry Rendering | _Another new feature in SDL 2.0 is hardware accelerated primitive rendering. Here we'll be using it to render some common shapes._ |
**Lesson 09** - The Viewport | _SDL 2.0 also lets you control where you render on the screen using the viewport. We'll be using the viewport to create subscreens._ |
**Lesson 10** - Color Keying | _Here we'll use color keying to give textures transparent backgrounds._ |
**Lesson 11** - Clip Rendering and Sprite Sheets | _Using clip rendering, you can keep multiple images on one texture and render the part you need. We'll be using this to render individual sprites from a sprite sheet._ |
**Lesson 12** - Color Modulation | _We'll be altering the color of rendered textures using color modulation._ |
**Lesson 13** - Alpha Blending | _Here we'll be using SDL 2.0 new hardware accelerated alpha blending._ |
**Lesson 14** - Animated Sprites and Vsync | _Here we'll be using a sequence of sprites to animate them._ |
**Lesson 15** - Rotation and Flipping | _Here we'll be using SDL 2.0's new texture rotation and flipping._ |
**Lesson 16** - True Type Fonts | _Here we'll be rendering text from true type fonts using SDL_ttf._ |
**Lesson 17** - Mouse Events | _Here we'll learn to read mouse input using mouse events._
**Lesson 18** - Key States | _There are other ways to read the keys besides event polling. Here we will get the current state of the keyboard using key states._ |
**Lesson 19** - Gamepads and Joysticks | _Here we'll learn to read input from a game controller._ |
**Lesson 20** - Force Feedback | _Another new feature for SDL 2.0 is rumble support using the SDL haptics. We'll make our controller rumble when a button is pressed._ |
**Lesson 21** - Sound Effects and Music | _Here we'll be using SDL_mixer to add music and sound to our SDL App._ |
**Lesson 22** - Timing | _Here we'll be using SDL's time capabilites._ |
**Lesson 23** - Advanced Timers | _Here we'll extend SDL time capabilities to make our own custom timer._ |
**Lesson 24** - Calculating Frame Rate | _Here we'll use the timers we built to measure frame rate._ |
**Lesson 25** - Capping Frame Rate | _If you need a constant frame rate when vsync isn't available, frame rate capping can be used as a fall back._ |
**Lesson 26** - Motion | _Here we'll be taking what we learned about rendering and handling input to make a dot move around the screen._ |
**Lesson 27** - Collision Detection | _Here we'll have two objects interact with each other using bounding box collision detection._ |
**Lesson 28** - Per-pixel Collision Detection | _Here we'll have two objects collide using per-pixel collision detection._ |
**Lesson 29** - Circular Collision Detection | _Here we'll learn to detect collisions with circles and boxes._ |
**Lesson 30** - Scrolling | _Here we'll be implementing a camera to scroll levels larger than the screen._ |
**Lesson 31** - Scrolling Backgrounds | _Here we'll be using a scrolling background to give the illusion of an infinite level._ |
**Lesson 32** - Text Input and Clipboard Handling | _Here we'll be using SDL 2.0's new way of handling text input and its new clipboard handling feature._ |
**Lesson 33** - File Reading and Writing | _Here we'll be using SDL's RWOps API to do binary file IO._ |
**Lesson 34** - Audio Recording | _SDL 2.0.8 supports audio recording. Here we'll be copying from the audio device to record and copying to the audio device to play back._ |
**Lesson 35** - Window Events | _Here we'll be handling events from a resizable window._ |
**Lesson 36** - Multiple Windows | _A new feature in SDL is the ability to support more than one window. Here we'll make an application that has 3 windows._ |
**Lesson 37** - Multiple Displays | _Another new feature of SDL 2.0 is the ability to handle more than one physical display. Here we'll make our window jump from display to display._ |
**Lesson 38** - Particle Engines | _Here we'll use a simple particle effect to create a simple trail effect._ |
**Lesson 39** - Tiling | _Here we'll make a simple level using a tiling engine._ |
**Lesson 40** - Texture Manipulation | _Here we'll be directly accessing and manipulating a texture's pixels._ |
**Lesson 41** - Bitmap Fonts | _Here we'll be using a texture as a font using bitmap font techniques._ |
**Lesson 42** - Texture Streaming | _Here we'll be rendering from a streaming data source using texture streaming._ |
**Lesson 43** - Render to Texture | _Here we'll be taking a scene and rendering it to a texture._ |
**Lesson 44** - Frame Independent Movement | _Here we'll be making the dot move independent of the current frame rate._ |
**Lesson 45** - Timer Callbacks | _SDL has another timing mechanism called timer callbacks. Here we'll be setting a function to be called back after a certain amount of time._ |
**Lesson 46** - Multithreading | _Multithreading allows your program to do things simultaneously. Here we'll make things print to the console from outside our main thread._ |
**Lesson 47** - Semaphores | _A major issue in multithreaded applications is that you need to make sure that they don't try to access the same data at the same time. Semaphores are a way to make sure only a certain amount of threads are performing an action at the same time._ |
**Lesson 48** - Atomic Operations | _Atomic operations are another way to synchronize threads. Here we'll be redoing the previous tutorial with atomic counters._ |
**Lesson 49** - Mutexes and Conditions | _Mutexes and conditions are yet another way to synchronize threads. Here we'll be using the added benefit that they allow threads to communicate with each other._ |
**Lesson 50** - SDL and OpenGL 2 | _SDL is a powerful tool when combined with OpenGL. If you're just starting out with OpenGL or want to maximize compatibility, you can use SDL with OpenGL 2.1. In this tutorial we will make a minimalist OpenGL 2.1 program._ |
**Lesson 51** - SDL and Modern OpenGL | _SDL 2.0 now has support for OpenGL 3.0+ with context controls. Here we'll be making a minimalist OpenGL 3+ core program._ |
**Lesson 52** - Hello Mobile | _Here we'll be loading and displaying an image in our first mobile app!_ |
**Lesson 53** - Extensions and Changing Orientation | _Here we'll be using SDL extension libraries and handling changing orientation._
**Lesson 54** - Touches | _Here we'll be handling single touch input._ |
**Lesson 55** - Multitouch | _Here we'll be handling multitouch events like pinches and rotation._

## Projects

## Notes
