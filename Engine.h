#pragma once
#include "stdafx.h"
class CWindow;
class CButton;

class CEngine
{
public:
    CEngine();
    ~CEngine();

    void Click();
    void Draw();
    void Start();
    void EventHandler();
    void ButtonHandler();

    void Create();

private:
    RenderWindow _window;
    Vector2f _resolution;
    int _koef;

    CWindow* _programWindow;
    CButton* _programButton[20];
    Vector2f _buttonPosition;
    Vector2f _buttonSize;
    Color _buttonColor;
    int _value[2];
    Clock clock;
    int _tempValue;
    int _sizeOfValue;

    Event _event;
};