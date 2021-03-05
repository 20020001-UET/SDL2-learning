# Lesson 10
[Lesson source link here!](https://lazyfoo.net/tutorials/SDL/10_color_keying/index.php)

### Table of contents
  [Introduction](#introduction)  
  [Files](#files)  
  [Summary](#summary) 
  
## Introduction
When **rendering multiple images on the screen**, **having images with transparent backgrounds is usually necessary**. 
Fortunately _**SDL provides an easy way to do this using color keying.**_ 

## Files
- **Source files:**
  - lesson10.cpp
- **Assets:**
  - background.png
  - foo.png

## Summary
### LTexture class
```C++
//Texture wrapper class
class LTexture
{
    public:
        //Initializes variables
        LTexture();

        //Deallocates memory
        ~LTexture();

        //Loads image at specified path
        bool loadFromFile( std::string path );

        //Deallocates texture
        void free();

        //Renders texture at given point
        void render( int x, int y );

        //Gets image dimensions
        int getWidth();
        int getHeight();

    private:
        //The actual hardware texture
        SDL_Texture* mTexture;

        //Image dimensions
        int mWidth;
        int mHeight;
};
```
**LTexture is a class to make some things easier.**
- **Imformation about the texture**:
  - _width_
  - _height_
  - _SDL_Texture*_
- We're going to do in **use a class** to **wrap and store the information about the texture**.
- **Struture:**
  - **Constructor and destructor**
    ```C+
    LTexture::LTexture()
    {
        //Initialize
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }

    LTexture::~LTexture()
    {
        //Deallocate
        free();
    }
    ```
    The constructor initializes variables and the destructor calls the deallocator which we'll cover later.
    
  - **A file loader**
    ```C++
    bool LTexture::loadFromFile( std::string path )
    {
        //Get rid of preexisting texture
        free();
        //The final texture
        SDL_Texture* newTexture = NULL;

        //Load image at specified path
        SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
        if( loadedSurface == NULL )
        {
            printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
        }
        else
        {
            //Color key image
            SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
            //Create texture from surface pixels
            newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
            if( newTexture == NULL )
            {
                printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
            }
            else
            {
                //Get image dimensions
                mWidth = loadedSurface->w;
                mHeight = loadedSurface->h;
            }

            //Get rid of old loaded surface
            SDL_FreeSurface( loadedSurface );
        }

        //Return success
        mTexture = newTexture;
        return mTexture != NULL;
    }
    ```
    - First, deallocate the texture in case there's one that's already loaded.
    - Next, we color key the image with **SDL_SetColorKey** before creating a texture from it.
    - After color keying the loaded surface, we create a texture from the loaded and color keyed surface.
    - If successed, we store the width/height of the texture and return whether the texture loaded successfully.
    
  - **A deallocator**
    ```C++
    void LTexture::free()
    {
        //Free texture if it exists
        if( mTexture != NULL )
        {
            SDL_DestroyTexture( mTexture );
            mTexture = NULL;
            mWidth = 0;
            mHeight = 0;
        }
    }
    ```
    - Simply checks if a texture exists, destroys it, and reinitializes the member variables.
    
  - **A renderer that takes in a position**
    ```C++
    void LTexture::render( int x, int y )
    {
        //Set rendering space and render to screen
        SDL_Rect renderQuad = { x, y, mWidth, mHeight };
        SDL_RenderCopy( gRenderer, mTexture, NULL, &renderQuad );
    }
    ```
    - **Here you see why we needed a wrapper class.**
    - When rendering a texture in a certain place, you need to specify a destination rectangle that sets the x/y position and width/height.
    
  - **Functions to get the texture's dimensions**
    ```C++
    int LTexture::getWidth()
    {
        return mWidth;
    }

    int LTexture::getHeight()
    {
        return mHeight;
    }
    ```
    - These last member functions allow us to get the width/height when we need them.

### Color Keying
```C++
            //Color key image
            SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
```

**[SDL_SetColorKey](http://wiki.libsdl.org/SDL_SetColorKey)**
  ```C++
  int SDL_SetColorKey(SDL_Surface* surface,
                      int          flag,
                      Uint32       key)
  ```
  - The first argument is **the surface we want to color key.**
  - The second argument **covers whether we want to enable color keying.**
  - The last argument is **the pixel we want to color key with.**

**[SDL_MapRGB](http://wiki.libsdl.org/SDL_MapRGB)**
```C++
Uint32 SDL_MapRGB(const SDL_PixelFormat* format,
                  Uint8                  r, 
                  Uint8                  g, 
                  Uint8                  b)
```
- The most cross platform way to **create a pixel from RGB color** is with **SDL_MapRGB**.
  - The first argument is **the format we want the pixel in.**
  - The last three variables are **the red, green and blue components for color you want to map.**
- Here, we're mapping **cyan** which is **red 0, green 255, blue 255**.
