#include "Graphics.h"
#include "Utils.h"
#include <string>

void Graphics::PrintCardBack() const
{
    LOG_LN("---------");
    LOG_LN("|#######|");
    LOG_LN("|#######|");
    LOG_LN("|#######|");
    LOG_LN("|#######|");
    LOG_LN("|#######|");
    LOG_LN("---------");
}

void Graphics::PrintCardFace(int value) const
{
    STRING v = std::to_string(value);

    int innerWidth = 7;
    int left = (innerWidth - (int)v.size()) / 2;
    int right = innerWidth - (int)v.size() - left;

    LOG_LN("---------");
    LOG_LN("|       |");
    LOG_LN("|       |");
    LOG_LN("|" << STRING(left, ' ') << v << STRING(right, ' ') << "|");
    LOG_LN("|       |");
    LOG_LN("|       |");
    LOG_LN("---------");
}