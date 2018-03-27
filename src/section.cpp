#include "section.hpp"
#include <ncurses.h>

Section::Section(int startx, int starty, int height, int width)
{
    //creating new window
    window = newwin(starty,startx,height, width);
    wrefresh(window);
}

Section::~Section()
{
   delwin(window); 
}