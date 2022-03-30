#pragma once

#include "stdafx.h"
class CDrawEngine
{
public:
    CDrawEngine(){};
    virtual ~CDrawEngine(){};
    
    virtual void Draw(RenderWindow& window) = 0;
protected:
};