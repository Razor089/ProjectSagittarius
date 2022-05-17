#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>

class TextureLoader
{
    static TextureLoader* pInstance;
    SDL_Surface* image;
    std::map<std::string, SDL_Texture*> TextureMap;
public:
    static TextureLoader* Instance();
    bool LoadTexture(const char* filename, const char* key);
    void DrawTile(std::string id, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer);
    SDL_Texture* GetTexture(const char* key);
private:
    TextureLoader() : image(0)
    {}
};

#endif