
#include "Elements.h"

int Elements::id_head = 0;



void Elements::add_to_container_elements(Elements *new_element)
{
    container_elements.push_back(new_element);
}


int Elements::get_element_level() { return level; }

void Elements::set_element_level(int parent_level)
{
    level = parent_level + 1;
}

bool Elements::check_element_key(std::string _key)
{
    for(int each_element = 0 ; each_element < container_elements.size() ; each_element++)
    {
        if (_key == container_elements[each_element]->get_element_key())
            return false;
    }
    return true;
}