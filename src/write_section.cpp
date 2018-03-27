#include "write_section.hpp"

Write_section::Write_section(int startx, int starty, int height, int width) : Section(startx, starty, height, width)
{
}

Write_section::~Write_section()
{
    delwin(window);
}