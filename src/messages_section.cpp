#include "messages_section.hpp"

Messages_section::Messages_section(int startx, int starty, int height, int width) : Section(startx, starty, height, width)
{
    
}

Messages_section::~Messages_section()
{
   delwin(window); 
}