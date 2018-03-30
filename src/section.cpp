#include "section.hpp"
#include <ncurses.h>
#undef timeout(delay)

Section::Section()
{
   
}

WINDOW* Section::getWindow(){
    return window;
}

void Section::createWindow(int height, int  width,int  starty, int startx){
 //creating new window
    window = newwin(height, width, starty,startx);
    box(window, 1, 1);
    wrefresh(window);
}

Section::~Section()
{
   delwin(window); 
}
