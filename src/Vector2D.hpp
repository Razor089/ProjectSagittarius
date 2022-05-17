#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <math.h>

class Vector2D
{
public:
    Vector2D(float x, float y) : m_x(x), m_y(y)
    {}

    Vector2D() : m_x(0), m_y(0)
    {}

    float GetX() { return m_x; }
    float GetY() { return m_y; }

    void SetY(float y) { m_y = y; }
    void SetX(float x) { m_x = x; }

    float Lenght() { return sqrt(m_x * m_x + m_y * m_y); }

    void Normalize()
    {
        float l = Lenght();
        if(l > 0)
        {
            (*this) /= l;
        }
    }

    Vector2D operator+(const Vector2D &v2) const
    {
        return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
    }

    friend Vector2D& operator+=(Vector2D &v1, const Vector2D &v2)
    {
        v1.m_x += v2.m_x;
        v1.m_y += v2.m_y;
        return v1;
    }

    Vector2D operator* (float scalar)
    {
        return Vector2D(m_x * scalar, m_y * scalar);
    }

    friend Vector2D& operator*=(Vector2D &v1,float scalar)
    {
        v1.m_x *= scalar;
        v1.m_y *= scalar;

        return v1;
    }

    Vector2D operator-(const Vector2D &v2) const
    {
        return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
    }

    friend Vector2D& operator-=(Vector2D &v1, const Vector2D &v2)
    {
        v1.m_x -= v2.m_x;
        v1.m_y -= v2.m_y;

        return v1;
    }

    Vector2D operator/(float scalar) const
    {
        return Vector2D(m_x / scalar, m_y / scalar);
    }

    friend Vector2D& operator/=(Vector2D &v1, float scalar)
    {
        v1.m_x /= scalar;
        v1.m_y /= scalar;

        return v1;
    }

    float m_x;
    float m_y;
};

#endif