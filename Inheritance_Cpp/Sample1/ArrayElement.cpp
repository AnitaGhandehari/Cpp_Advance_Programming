
#include "ArrayElement.h"
using namespace std;

ArrayElement::ArrayElement(std::string _key):Elements()
{
    element_type = ARRAY;
    key = _key;
    level = 0;
    id = id_head;
    id_head++;
};

void ArrayElement::print()
{
    if(key != NULL_KEY)
        cout << string(level * 4, ' ') << "\"" << key <<"\"" << ":" << ' ';
    cout << "[\n";
    for(int each_element = 0 ; each_element < container_elements.size() ; each_element++) {
        container_elements[each_element]->print();
        if(each_element != container_elements.size() - 1)
            cout << "," ;
        cout << "\n" ;
    }
    cout << string(level * 4, ' ') << "]";
}

bool ArrayElement::check_type_match(std::string _type)
{
    return _type == ARRAY;
}
