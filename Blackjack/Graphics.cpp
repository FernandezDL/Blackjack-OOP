#include "Graphics.h"
#include "Utils.h"
#include <string>

void Graphics::PrintCardBack(std::ostream& os) const
{
    os << "---------\n";
    os << "|#######|\n";
    os << "|#######|\n";
    os << "|#######|\n";
    os << "|#######|\n";
    os << "|#######|\n";
    os << "---------\n";
}

void Graphics::PrintCardFace(std::ostream& os, int value) const
{
    std::string v = std::to_string(value);

    int innerWidth = 7; // espacio entre |       |
    int left = (innerWidth - (int)v.size()) / 2;
    int right = innerWidth - (int)v.size() - left;

    os << "+-------+\n";
    os << "|       |\n";
    os << "|       |\n";
    os << "|" << std::string(left, ' ') << v << std::string(right, ' ') << "|\n";
    os << "|       |\n";
    os << "|       |\n";
    os << "+-------+\n";
}
