

#ifndef A6_ARRAYELEMENT_H
#define A6_ARRAYELEMENT_H

#include "Elements.h"
#include <iostream>
#define ARRAY "array"
class ArrayElement: public Elements{
private:
    int id;
public:
    ArrayElement(std::string _key);
    void print() override;
    bool check_type_match(std::string _type);
};

#endif //A6_ARRAYELEMENT_H
