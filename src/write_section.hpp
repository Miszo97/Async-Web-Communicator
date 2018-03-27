#ifndef WRITE_SECTION_HPP
#define WRITE_SECTION_HPP

#include <curses.h>
#include "section.hpp"

class Write_section : public Section
{
public:
    Write_section(int, int, int, int);
    Write_section(Write_section &&) = default;
    Write_section(const Write_section &) = default;
    Write_section &operator=(Write_section &&) = default;
    Write_section &operator=(const Write_section &) = default;
    ~Write_section();

private:
};
#endif // !1 write_section_hpp