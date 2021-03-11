# Lesson 12
[Lesson source link here!](https://lazyfoo.net/tutorials/SDL/12_color_modulation/index.php)

### Table of contents
  [Introduction](#introduction)  
  [Files](#files)  
  [Summary](#summary) 
  
## Introduction
Color modulation allows you to alter **the color of your rendered textures**.

## Files
- **Source files:**
  - lesson12.cpp
- **Assets:**
  - colors.png

## Summart
### Color Mod
```C++
void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
    //Modulate texture
    SDL_SetTextureColorMod( mTexture, red, green, blue );
}
```
This function will allow the texture modulation to be set. All it does it take in a red, green, and blue color components.

**[SDL_SetTextureColorMod](https://wiki.libsdl.org/SDL_SetTextureColorMod)**
Setting texture modulation.

**SDL_SetTextureColorMod** accepts Uint8 as arguments for the color components. 
An Uint8 is just an integer that in Unsigned and 8bit. This means is goes from 0 to 255.
