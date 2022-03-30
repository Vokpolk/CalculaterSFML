#include "Button.h"

CButton::CButton(Vector2f position, Vector2f size, Color color, string symbol, void(*handler)(CButton*), int buttonValue)
{
    _buttonPosition = position;
    _buttonSize.x = size.x;
    _buttonSize.y = size.y;
    _buttonColor = color;
    _buttonClickedColor = Color(0, 0, 0);
    _symbol = symbol;
    _buttonValue = buttonValue;
    _handler = handler;
    _textOnButtonPosition.x = _buttonPosition.x + _buttonSize.x;// / 2.0f;
    _textOnButtonPosition.y = _buttonPosition.y + _buttonSize.y / 2.0f;
    _buttonClicked = false;
}

void CButton::Draw(RenderWindow& window)
{
    DrawClickedButton(window);
    DrawText(window);    
}

void CButton::DrawClickedButton(RenderWindow& window)
{
    CircleShape circle(_buttonSize.x, 50);
    // Закрашиваем наш круг
    if (_buttonClicked)
        circle.setFillColor(_buttonClickedColor);
    else
        circle.setFillColor(_buttonColor);
    circle.setPosition(_buttonPosition);
    window.draw(circle);
}

void CButton::DrawText(RenderWindow& window)
{
    Font font;
    font.loadFromFile("Fonts/AppleFont/SF-Pro-Display-Medium.otf");
    // Создаём текст
    Text text(_symbol, font);
    FloatRect bounds = text.getLocalBounds();
    text.setPosition(_textOnButtonPosition.x - bounds.width / 2, _textOnButtonPosition.y);
    text.setCharacterSize(30);
    text.setFillColor(Color::White);
    // Рисуем это
    window.draw(text);
}

void CButton::ClickHandle()
{
    _handler(this);
    //usleep(10000);
}

bool CButton::PointIsMine(Vector2f position, Event event)
{
    _buttonClicked = false;

    if ((position.x >= _buttonPosition.x &&
        position.x <= _buttonPosition.x + _buttonSize.x * 2 &&
        position.y >= _buttonPosition.y &&
        position.y <= _buttonPosition.y + _buttonSize.y * 2) &&
        /*event.mouseButton.button == Mouse::Left*/
        event.type == Event::MouseButtonPressed)
    {
        _buttonClicked = true;
    }
    else if (event.type == Event::MouseButtonReleased)
    {
        //действия, когда отпустили
        _buttonClicked = false;
    }

    return _buttonClicked;
}