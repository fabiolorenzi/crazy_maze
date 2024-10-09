#include "UI.h"

UI::UI(int _x, int _y, int _width, int _height, int _life, int _time)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    life = _life;
    time = _time;
}

void UI::UpdateLife(int newValue)
{
    life = newValue;
}

void UI::UpdateTime(int newValue)
{
    time = newValue;
}