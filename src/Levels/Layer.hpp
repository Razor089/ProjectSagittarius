/**
 * @file Layer.hpp
 * @author Cosimo Davide Viggiano (cosimod089@gmail.com)
 * @brief Abstract base class for Layers type objects
 * @version 0.1
 * @date 2022-05-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LAYER_H
#define LAYER_H

class Layer
{
public:
    virtual void Update()=0;
    virtual void Render()=0;

protected:
    virtual ~Layer() {}
};

#endif