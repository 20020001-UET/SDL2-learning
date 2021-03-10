//Using SDL, SDL_image, iostream and strings
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

class LTexture
{
    public:
        //Initialize variables
        LTexture();

        //Deallocates memory
        ~LTexture();

        //Loads image at specified path
        bool loadFromFile(std::string pth);

        //Deallocates texture
        void free();

        //Set color modulation
        void setColor (Uint8 red, Uint8 green, Uint8 blue);

        //Renders texture at given point
        void render(int x, int y, SDL_Rect* clip = NULL);

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

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Scene texture
LTexture gModulatedTexture;

int main(int argc, char* args[])
{
    //Start up SDL and create window
    if (!init())
    {
        std::cout << "Falled to initialize!\n";
    }
    else
    {

        //Load media
        if (!loadMedia())
        {
            std::cout << "Failed to load media\n";
        }
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //Modulation components
            Uint8 r = 255;
            Uint8 g = 255;
            Uint8 b = 255;

            //While application is running
            while (!quit)
            {
                //Handle events on queue
                while (SDL_PollEvent(&e) != 0)
                {
                    //User requests quit
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                    else
                        if (e.type == SDL_KEYDOWN)
                        {
                            switch (e.key.keysym.sym)
                            {
                                //Increase red
                                case SDLK_q:
                                    r += 32;
                                    break;

                                //Increase green
                                case SDLK_w:
                                    g += 32;
                                    break;

                                //Increase blue
                                case SDLK_e:
                                    b += 32;
                                    break;

                                //Decrease red
                                case SDLK_a:
                                    r -= 32;
                                    break;

                                //Decrease green
                                case SDLK_s:
                                    g -= 32;
                                    break;

                                //Decrease blue
                                case SDLK_d:
                                    b -= 32;
                                    break;
                            }
                        }
                }

                //Clear screen
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);

                //Modulate and render texture
                gModulatedTexture.setColor(r, g, b);
                gModulatedTexture.render(0, 0);

                //Update screen
                SDL_RenderPresent(gRenderer);
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}

SDL_Texture* loadTexture(std::string path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        std::cout << "Unable to load image " << path.c_str() << "! SDL_image Error: " << IMG_GetError();
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            std::cout << "Unable to create texture from " << path.c_str() << "! SDL Error: " << SDL_GetError();
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError();
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial",
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SCREEN_WIDTH,
                                   SCREEN_HEIGHT,
                                   SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            std::cout << "Window could not be created! SDL_Error: " << SDL_GetError();
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError();
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0Xff, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError();
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load spirtes sheet texture
    if (!gModulatedTexture.loadFromFile("colors.png"))
    {
        std::cout << "Failed to load colors texture!\n";
        success = false;
    }

    return success;
}

void close()
{
    //Free loaded images
    gModulatedTexture.free();

    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL Subsystems
    IMG_Quit();
    SDL_Quit();
}

///LTexture
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

bool LTexture::loadFromFile(std::string path)
{
    //Get rid of preexisting
    free();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        std::cout << "Unable to load image " << path.c_str() << "! SDL_image Error: " << IMG_GetError() << '\n';
    }
    else
    {
        //Color key image
        SDL_SetColorKey(loadedSurface,
                        SDL_TRUE,
                        SDL_MapRGB(loadedSurface->format, 0x00, 0xFF, 0xFF));

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            std::cout << "Unable to create texet from " << path.c_str() << "! SDL Error: " << SDL_GetError() << '\n';
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
    mTexture = newTexture;
    return (mTexture != NULL);
}

void LTexture::free()
{
    //Free texture if it exists
    if (mTexture != NULL)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
    //Modulate texture
    SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void LTexture::render(int x, int y, SDL_Rect* clip)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};

    //Set clip rendering dimensions
    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
}

int LTexture::getWidth()
{
    return mWidth;
}

int LTexture::getHeight()
{
    return mHeight;
}
