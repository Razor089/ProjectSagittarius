#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H
#include <string>

class LoaderParams
{
public:
    LoaderParams(int x, int y, int width, int height, std::string textureID) : m_x(x), m_y(y),
                                                                               m_width(width), m_height(height),
                                                                               m_textureID(textureID)
    {}

    int GetX() const { return m_x; }
    int GetY() const { return m_y;}
    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }
    int GetNumFrames() const { return m_numFrames; }
    std::string GetTextureID() const { return m_textureID; }
private:
    int m_x;
    int m_y;

    int m_width;
    int m_height;

    int m_numFrames;

    std::string m_textureID;
};

#endif