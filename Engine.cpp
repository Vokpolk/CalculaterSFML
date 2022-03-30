#include "Engine.h"
#include "Window.h"
#include "Button.h"

CEngine::CEngine()
{
    _koef = 40;
    _resolution.x = 9 * _koef;//VideoMode::getDesktopMode().width;
    _resolution.y = 19.5 * _koef;//VideoMode::getDesktopMode().height;
    _buttonSize.x = 40.f;
    _buttonSize.y = 40.f;
    _buttonPosition.x = 0.f;
    _buttonPosition.y = 0.f;
    _buttonColor = Color(50, 50, 50);
    _window.create(VideoMode(_resolution.x, _resolution.y), "CALCULATOR");    
    _value[0] = 0;
    _value[1] = 0;
    _tempValue = 0;
    Create();
}

CEngine::~CEngine()
{
    if (_programWindow != nullptr)
    {
        delete _programWindow;
        _programWindow = nullptr;
    }
    for (int i = 0; i < 20; i++)
    {
        if (_programButton != nullptr)
        {
            delete _programButton[i];
            _programButton[i] = nullptr;
        }
    }
}

void CEngine::Create()
{
    _programWindow = new CWindow(Vector2f(0, 0), Vector2f(_resolution.x, _resolution.y * 3 / 9), Color(0, 0, 0));

    _buttonColor = Color(165, 165, 165);
    _buttonPosition.x = 0 * _resolution.x / 4 + 5;
    _buttonPosition.y = 3 * _resolution.y / 9 + 10;
    _programButton[0] = new CButton(_buttonPosition, _buttonSize, _buttonColor, "AC", CButtonHandler::OnSetAC);
    _buttonPosition.x = 1 * _resolution.x / 4 + 5;
    _buttonPosition.y = 3 * _resolution.y / 9 + 10;
    _programButton[1] = new CButton(_buttonPosition, _buttonSize, _buttonColor, "+/-", CButtonHandler::OnSetNegativeNumber);
    _buttonPosition.x = 2 * _resolution.x / 4 + 5;
    _buttonPosition.y = 3 * _resolution.y / 9 + 10;
    _programButton[2] = new CButton(_buttonPosition, _buttonSize, _buttonColor, "%", CButtonHandler::OnSetPercent);
    _buttonColor = Color(254, 148, 50);
    _buttonPosition.x = 3 * _resolution.x / 4 + 5;
    _buttonPosition.y = 3 * _resolution.y / 9 + 10;
    _programButton[3] = new CButton(_buttonPosition, _buttonSize, _buttonColor, "/", CButtonHandler::OnSetDividing);
    _buttonColor = Color(50, 50, 50);
    _buttonPosition.x = 0 * _resolution.x / 4 + 5;
    _buttonPosition.y = 4 * _resolution.y / 9 + 10;
    _programButton[4] = new CButton(_buttonPosition, _buttonSize, _buttonColor, to_string(7), CButtonHandler::OnSet7, 7);
    _buttonPosition.x = 1 * _resolution.x / 4 + 5;
    _buttonPosition.y = 4 * _resolution.y / 9 + 10;
    _programButton[5] = new CButton(_buttonPosition, _buttonSize, _buttonColor, to_string(8), CButtonHandler::OnSet8, 8);
    _buttonPosition.x = 2 * _resolution.x / 4 + 5;
    _buttonPosition.y = 4 * _resolution.y / 9 + 10;
    _programButton[6] = new CButton(_buttonPosition, _buttonSize, _buttonColor, to_string(9), CButtonHandler::OnSet9, 9);
    _buttonColor = Color(254, 148, 50);
    _buttonPosition.x = 3 * _resolution.x / 4 + 5;
    _buttonPosition.y = 4 * _resolution.y / 9 + 10;
    _programButton[7] = new CButton(_buttonPosition, _buttonSize, _buttonColor, "x", CButtonHandler::OnSetMultiplication);
    _buttonColor = Color(50, 50, 50);
    _buttonPosition.x = 0 * _resolution.x / 4 + 5;
    _buttonPosition.y = 5 * _resolution.y / 9 + 10;
    _programButton[8] = new CButton(_buttonPosition, _buttonSize, _buttonColor, to_string(4), CButtonHandler::OnSet4, 4);
    _buttonPosition.x = 1 * _resolution.x / 4 + 5;
    _buttonPosition.y = 5 * _resolution.y / 9 + 10;
    _programButton[9] = new CButton(_buttonPosition, _buttonSize, _buttonColor, to_string(5), CButtonHandler::OnSet5, 5);
    _buttonPosition.x = 2 * _resolution.x / 4 + 5;
    _buttonPosition.y = 5 * _resolution.y / 9 + 10;
    _programButton[10] = new CButton(_buttonPosition, _buttonSize, _buttonColor, to_string(6), CButtonHandler::OnSet6, 6);
    _buttonColor = Color(254, 148, 50);
    _buttonPosition.x = 3 * _resolution.x / 4 + 5;
    _buttonPosition.y = 5 * _resolution.y / 9 + 10;
    _programButton[11] = new CButton(_buttonPosition, _buttonSize, _buttonColor, "-", CButtonHandler::OnSetMinus);
    _buttonColor = Color(50, 50, 50);
    _buttonPosition.x = 0 * _resolution.x / 4 + 5;
    _buttonPosition.y = 6 * _resolution.y / 9 + 10;
    _programButton[12] = new CButton(_buttonPosition, _buttonSize, _buttonColor, to_string(1), CButtonHandler::OnSet1, 1);
    _buttonPosition.x = 1 * _resolution.x / 4 + 5;
    _buttonPosition.y = 6 * _resolution.y / 9 + 10;
    _programButton[13] = new CButton(_buttonPosition, _buttonSize, _buttonColor, to_string(2), CButtonHandler::OnSet2, 2);
    _buttonPosition.x = 2 * _resolution.x / 4 + 5;
    _buttonPosition.y = 6 * _resolution.y / 9 + 10;
    _programButton[14] = new CButton(_buttonPosition, _buttonSize, _buttonColor, to_string(3), CButtonHandler::OnSet3, 3);
    _buttonColor = Color(254, 148, 50);
    _buttonPosition.x = 3 * _resolution.x / 4 + 5;
    _buttonPosition.y = 6 * _resolution.y / 9 + 10;
    _programButton[15] = new CButton(_buttonPosition, _buttonSize, _buttonColor, "+", CButtonHandler::OnSetPlus);
    _buttonColor = Color(50, 50, 50);
    _buttonPosition.x = 0 * _resolution.x / 4 + 5;
    _buttonPosition.y = 7 * _resolution.y / 9 + 10;
    _programButton[16] = new CButton(_buttonPosition, _buttonSize, _buttonColor, to_string(0), CButtonHandler::OnSet0, 0);
    //_buttonPosition.x = 1 * _resolution.x / 4 + 5;
    //_buttonPosition.y = 7 * _resolution.y / 9 + 10;
    _programButton[17] = nullptr;//new CButton(_buttonPosition, _buttonSize, _buttonColor, to_string(0));
    _buttonPosition.x = 2 * _resolution.x / 4 + 5;
    _buttonPosition.y = 7 * _resolution.y / 9 + 10;
    _programButton[18] = new CButton(_buttonPosition, _buttonSize, _buttonColor, ",", CButtonHandler::OnSetPoint);
    _buttonColor = Color(254, 148, 50);
    _buttonPosition.x = 3 * _resolution.x / 4 + 5;
    _buttonPosition.y = 7 * _resolution.y / 9 + 10;
    _programButton[19] = new CButton(_buttonPosition, _buttonSize, _buttonColor, "=", CButtonHandler::OnSetEqualSign);
}

void CEngine::Start()
{
    while (_window.isOpen())
    {
        while (_window.pollEvent(_event))
            EventHandler();
        Draw();
    }
}

void CEngine::EventHandler()
{
    if (Keyboard::isKeyPressed(Keyboard::F1))
        _window.close();
    Time dt = clock.restart();
    float dtAsSeconds = dt.asSeconds();
    
    ButtonHandler();
}

void CEngine::ButtonHandler()
{
    Vector2f pos = Vector2f(Mouse::getPosition(_window));

    if (Keyboard::isKeyPressed(Keyboard::Escape) || _programButton[0]->Clicked())
    {
        _programButton[0]->SetSymbol("AC");
        _value[0] = 0;
        _tempValue = _value[0];
        _programWindow->ButtonValue(to_string(_value[0]));
    }
    for (size_t i = 0; i < 20; i++)
    {
        if (_programButton[i] != nullptr && _programButton[i]->PointIsMine(pos, _event))
        {
            _programButton[i]->ClickHandle();
            if (_programButton[i]->GetButtonValue() != -1 && _tempValue < 1000000) 
            {
                if (i == 0)
                    return;
                
                _tempValue += _programButton[i]->GetButtonValue();
                if (_programButton[i]->GetButtonValue() != 0 && _tempValue != 0)
                    _programButton[0]->SetSymbol("C");
                _programWindow->ButtonValue(to_string(_tempValue));
                cout << "_tempvalue: " << _tempValue << endl;
                _tempValue *= 10;
            }
        }
    }
}

void CEngine::Draw()
{
    //result window
    _programWindow->Draw(_window);
    //buttons
    for (size_t i = 0; i < 20; i++)
        if (_programButton[i] != nullptr)
            _programButton[i]->Draw(_window);

    _window.display();
    _window.clear(Color(0,0,0,0));
}