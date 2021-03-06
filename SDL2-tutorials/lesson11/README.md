# Lesson 11
[Lesson source link here!](https://lazyfoo.net/tutorials/SDL/11_clip_rendering_and_sprite_sheets/index.php)

### Table of contents
  [Introduction](#introduction)  
  [Files](#files)  
  [Summary](#summary) 
  
## Introduction
Sometimes you only want to render part of a texture. 
A lot of times games like to keep multiple images on the same sprite sheet as opposed to having a bunch of textures. 
Using clip rendering, we can define a portion of the texture to render as opposed to rendering the whole thing.

## Files
- **Source files:**
  - lesson11.cpp
- **Assets:**
  - dots.png

## Sumamry
### Clip rendering 
```C++
        //Renders texture at given point
        void render( int x, int y, SDL_Rect* clip = NULL );
```
- The render function now accepts a rectangle defining which position of the texture we want to render.
- Give that rectangle a defautt arguments of NULL in case we want to render the whole texture.

```C++
void LTexture::render( int x, int y, SDL_Rect* clip )
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    //Set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
}
```
- The new rendering function for the texture class is mostly te same as the previous but with two changes:
  - First, when clipping and using the dimensions of the clip rectangle instead of the texture.
  - Second, we're going to pass in the clip rectangle to **SDL_RenderCopy** as the source rectangle.
    - The source rectangle defines what part of the texture you want to render.
    - When the source rectangle is NULL -> the whole texture is rendered.

### Set sprite
The sprite is defined as a SDL_Rect
```C++
//Scene sprites
SDL_Rect gSpriteClips[ 4 ];
```

In this tutorial, there are 4 spirtes:
```C++
        //Set top left sprite
        gSpriteClips[ 0 ].x =   0;
        gSpriteClips[ 0 ].y =   0;
        gSpriteClips[ 0 ].w = 100;
        gSpriteClips[ 0 ].h = 100;

        //Set top right sprite
        gSpriteClips[ 1 ].x = 100;
        gSpriteClips[ 1 ].y =   0;
        gSpriteClips[ 1 ].w = 100;
        gSpriteClips[ 1 ].h = 100;
        
        //Set bottom left sprite
        gSpriteClips[ 2 ].x =   0;
        gSpriteClips[ 2 ].y = 100;
        gSpriteClips[ 2 ].w = 100;
        gSpriteClips[ 2 ].h = 100;

        //Set bottom right sprite
        gSpriteClips[ 3 ].x = 100;
        gSpriteClips[ 3 ].y = 100;
        gSpriteClips[ 3 ].w = 100;
        gSpriteClips[ 3 ].h = 100;
```
- The media loading function loads the texture and then defines the clip rectangles for the sprites.

### Sprite rendering
```C++
//Render top left sprite
                gSpriteSheetTexture.render( 0, 0, &gSpriteClips[ 0 ] );

                //Render top right sprite
                gSpriteSheetTexture.render( SCREEN_WIDTH - gSpriteClips[ 1 ].w, 
                                            0, 
                                            &gSpriteClips[ 1 ] );

                //Render bottom left sprite
                gSpriteSheetTexture.render( 0, 
                                            SCREEN_HEIGHT - gSpriteClips[ 2 ].h, 
                                            &gSpriteClips[ 2 ] );

                //Render bottom right sprite
                gSpriteSheetTexture.render( SCREEN_WIDTH - gSpriteClips[ 3 ].w, 
                                            SCREEN_HEIGHT - gSpriteClips[ 3 ].h, 
                                            &gSpriteClips[ 3 ] )
```
In the main loop, we render the same texture 4 times.
But we're rendering a different portion of the sprite sheet in different places each call.

**Noted:** _Different portion came from the Sprite sheet that we defined._
