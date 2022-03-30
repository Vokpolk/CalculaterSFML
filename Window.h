#pragma once
#include "stdafx.h"
#include "DrawEngine.h"
class CWindow : public CDrawEngine
{
public:
    CWindow(Vector2f position, Vector2f size, Color color);
    ~CWindow() {};

    virtual void Draw(RenderWindow& window) override;
    void ButtonValue(string value) { _buttonValue = value; }
    void ResultPosition(int value);
private:
    Vector2f _windowPosition;
    Vector2f _windowSize;
    Color _windowColor;
    Vector2f _resultPosition;
    unsigned int _resultSize;
    string _buttonValue;
};
