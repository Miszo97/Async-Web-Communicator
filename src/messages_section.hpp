#ifndef messages_section_hpp
#define messages_section_hpp


#include "section.hpp"

class Messages_section : public Section
{
public:
Messages_section(int, int, int, int);
Messages_section(Messages_section &&) = default;
Messages_section(const Messages_section &) = default;
Messages_section &operator=(Messages_section &&) = default;
Messages_section &operator=(const Messages_section &) = default;
~Messages_section();

private:

};


#endif