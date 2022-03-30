#pragma once
#include "stdafx.h"
#include "DrawEngine.h"
#include <unistd.h>

class CButton : public CDrawEngine
{
public:
    CButton(Vector2f position, Vector2f size, Color color, string symbol, void(*handler)(CButton*), int buttonValue = -1);
    ~CButton() {};

    virtual void Draw(RenderWindow& window) override;
    void DrawText(RenderWindow& window);
    void DrawClickedButton(RenderWindow& window);
    void ClickHandle();
    bool Clicked() { return _buttonClicked; }
    bool PointIsMine(Vector2f position, Event event);
    void SetColor(Color color) { _buttonColor = color; }
    void SetClickedColor(Color color) { _buttonClickedColor = color; }
    void SetButtonValue(int value) { _buttonValue = value; }
    int GetButtonValue() const { return _buttonValue; }
    void SetSymbol(string symbol) { _symbol = symbol; }
    void (*_handler)(CButton*);
private:
    Vector2f _buttonPosition;
    Vector2f _textOnButtonPosition;
    Vector2f _buttonSize;
    Color _buttonColor;
    Color _buttonClickedColor;
    string _symbol;
    int _buttonValue;
    bool _buttonClicked;
};

class CButtonHandler
{
public:
    static void OnSet0(CButton* btn) {
        btn->SetClickedColor(Color(120, 120, 120));
    }
    static void OnSet1(CButton* btn) {
        btn->SetClickedColor(Color(120, 120, 120));
    }
    static void OnSet2(CButton* btn) {
        btn->SetClickedColor(Color(120, 120, 120));
    }
    static void OnSet3(CButton* btn) {
        btn->SetClickedColor(Color(120, 120, 120));
    }
    static void OnSet4(CButton* btn) {
        btn->SetClickedColor(Color(120, 120, 120));
    }
    static void OnSet5(CButton* btn) {
        btn->SetClickedColor(Color(120, 120, 120));
    }
    static void OnSet6(CButton* btn) {
        btn->SetClickedColor(Color(120, 120, 120));
    }
    static void OnSet7(CButton* btn) {
        btn->SetClickedColor(Color(120, 120, 120));
    }
    static void OnSet8(CButton* btn) {
        btn->SetClickedColor(Color(120, 120, 120));
    }
    static void OnSet9(CButton* btn) {
        btn->SetClickedColor(Color(120, 120, 120));
    }
    static void OnSetAC(CButton* btn) {
        btn->SetClickedColor(Color(200, 200, 200));
        btn->SetButtonValue(0);
    }
    static void OnSetNegativeNumber(CButton* btn) {
        btn->SetClickedColor(Color(200, 200, 200));
    }
    static void OnSetPercent(CButton* btn) {    
        btn->SetClickedColor(Color(200, 200, 200));    
    }
    static void OnSetDividing(CButton* btn) {
        btn->SetClickedColor(Color(254, 168, 120));
    }
    static void OnSetMultiplication(CButton* btn) {
        btn->SetClickedColor(Color(254, 168, 120));
    }
    static void OnSetMinus(CButton* btn) {
        btn->SetClickedColor(Color(254, 168, 120));
    }
    static void OnSetPlus(CButton* btn) {
        btn->SetClickedColor(Color(254, 168, 120));
    }
    static void OnSetEqualSign(CButton* btn) {
        btn->SetClickedColor(Color(254, 168, 120));
    }
    static void OnSetPoint(CButton* btn) {
        btn->SetClickedColor(Color(120, 120, 120));
    }
};