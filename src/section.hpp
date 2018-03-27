#ifndef section_hpp
#define section_hpp

#include <ncurses.h>
class Section

{
public:
Section(int, int, int, int);
Section(Section &&) = default;
Section(const Section &) = default;
Section &operator=(Section &&) = default;
Section &operator=(const Section &) = default;
virtual ~Section() = 0;

protected:
    WINDOW* window;    
};

#endif