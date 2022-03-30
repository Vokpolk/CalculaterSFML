#include "Window.h"

CWindow::CWindow(Vector2f position, Vector2f size, Color color)
{   
    _windowPosition = position;
    _windowSize = size;
    _windowColor = color;
    _resultPosition.x = _windowPosition.x + 10.f;// + size.x - 70.f;
    _resultPosition.y = _windowPosition.y + size.y - 100.f;
    _buttonValue = "0";
    _resultSize = 80;
}

void CWindow::Draw(RenderWindow& window)
{
    RectangleShape resultWindow(_windowSize);
    resultWindow.setFillColor(_windowColor);
    resultWindow.setPosition(_windowPosition);
    window.draw(resultWindow);

    ButtonValue(_buttonValue);
    Font font;//шрифт 
    font.loadFromFile("Fonts/AppleFont/SF-Pro-Display-Medium.otf");
    Text text(_buttonValue, font, _resultSize);
    text.setFillColor(Color::White);
    text.setPosition(_resultPosition);
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    window.draw(text);
}

void CWindow::ResultPosition(int value)
{
    if (value < 10)
        return;
    _resultPosition.x -= 49.f * sizeof(value) / sizeof(int);
}