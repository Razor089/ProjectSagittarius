#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
    static int s_ID;
    int m_ID;
public:
    GameObject(int ID)
    {
        SetID(ID);
    }
    int GetID() { return m_ID; }
    virtual void Update()=0;
    virtual void Render()=0;
private:
    void SetID(int ID) { s_ID++; ID = s_ID; }
};

#endif