#include <TextureLoader.hpp>
#include <SDLEngine.hpp>
#include <iostream>

TextureLoader* TextureLoader::pInstance = 0;

TextureLoader* TextureLoader::Instance()
{
    if(pInstance == 0) pInstance = new TextureLoader();
    return pInstance;
}

bool TextureLoader::LoadTexture(const char* filename, const char* key)
{
    image = IMG_Load(filename);
    if(!image)
    {
        std::cout << "Cannot load Image; Error: " << SDL_GetError() << std::endl;
        return false;
    }


    SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::Instance()->GetRenderer(), image);
    SDL_FreeSurface(image);

    TextureMap[key] = texture;
    std::cout << "Loaded " << filename << "with key : " << key << std::endl;
    return true;
}

SDL_Texture* TextureLoader::GetTexture(const char* filename)
{
    return TextureMap[filename];
}

void TextureLoader::DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = dstRect.w = width;
    srcRect.h = dstRect.h = height;
    dstRect.x = x;
    dstRect.y = y;

    SDL_RenderCopyEx(pRenderer, TextureMap[id], &srcRect, &dstRect, 0, 0, flip);
}

void TextureLoader::DrawTile(std::string id, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer)
{
    /*
    std::cout << "Draw Call on " << id << std::endl;
    std::cout << "Margin: " << margin << std::endl;
    std::cout << "Spacing: " << spacing << std::endl;
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;
    */
    SDL_Rect srcRect;
    SDL_Rect dstRect;

    srcRect.x = margin + (spacing + width) * currentFrame;
    srcRect.y = margin + (spacing + height) * currentRow;

    srcRect.w = dstRect.w = width;
    srcRect.h = dstRect.h = height;
    dstRect.x = x;
    dstRect.y = y;

    //std::cout << "Trying Rendering: " << TextureMap[id] << std::endl;
    SDL_RenderCopyEx(renderer, TextureMap[id], &srcRect, &dstRect, 0, 0, SDL_FLIP_NONE);
}