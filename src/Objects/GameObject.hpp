#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL2/SDL.h>
#include <string>
#include <LoaderParams.hpp>
#include <vector>
#include <TileLayer.hpp>
#include <Vector2D.hpp>

class GameObject
{
public:
    virtual ~GameObject() {}
    virtual void Update()=0;
    virtual void Draw()=0;
    virtual void Clean()=0;
    virtual void Collision()=0;
    virtual std::string GetTye()=0;

    virtual void Load(const LoaderParams* pParams)=0;

    Vector2D& GetPosition() { return m_position; }
    Vector2D& GetVelocity() { return m_velocity; }

    int GetWidth() { return m_width; }
    int GetHeight() { return m_height; }

    void Scroll(){}

    bool IsUpdating() { return m_updating; }
    bool IsDead() { return m_dead; }
    bool IsDying() { return m_dying; }

    void SetUpdating(bool updating) { m_updating = updating; }

    void SetCollisionLayer(std::vector<TileLayer*>* layer) { m_collisionLayers = layer; }
protected:
    GameObject() : m_position(0,0),
                   m_velocity(0,0),
                   m_acceleration(0,0),
                   m_width(0),
                   m_height(0),
                   m_currentRow(0),
                   m_currentFrame(0),
                   m_updating(false),
                   m_dead(false),
                   m_dying(false),
                   m_angle(0),
                   m_alpha(255)
    {}

    // Movement Variables
    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;

    // Size Variables
    int m_width;
    int m_height;

    // Common Variables
    bool m_updating;
    bool m_dead;
    bool m_dying;

    // Animation Variables
    int m_currentRow;
    int m_currentFrame;
    int m_numFrames;
    int m_animSpeed;
    std::string m_textureID;

    // Rotation
    double m_angle;

    // Blending
    int m_alpha;

    // CollisionLayersa
    std::vector<TileLayer*>* m_collisionLayers;
};

#endif