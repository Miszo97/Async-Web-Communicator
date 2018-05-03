#ifndef section_hpp
#define section_hpp

#include <ncurses.h>
#undef timeout
class Section

{
public:
Section();
Section(Section &&) = default;
Section(const Section &) = default;
Section &operator=(Section &&) = default;
Section &operator=(const Section &) = default;
virtual ~Section() = 0;
WINDOW* getWindow();
void createWindow(int,int,int,int);
int max_displayed = 15;

protected:
    WINDOW* window;    
};

#endif