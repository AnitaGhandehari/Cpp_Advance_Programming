

#ifndef A6_ELEMENTS_H
#define A6_ELEMENTS_H

#include <string>
#include <vector>
#include <iostream>
#define NULL_KEY " "

class Elements{
protected:
    static int id_head;
    int level;
    std::string element_type;
    std::string key;
    std::vector<Elements*> container_elements;
public:
    void add_to_container_elements(Elements *new_element);
    void set_element_level(int parent_level);
    int get_element_level();
    std::string get_element_key(){ return key; };
    bool check_element_key(std::string _key);
    virtual bool check_type_match(std::string _type) = 0;
    virtual void print() = 0;
};

#endif //A6_ELEMENTS_H
