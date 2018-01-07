// Your code here

#include "Food.h"

Food::Food(std::string name, int quantity) {
    name_ = name;
    quantity_ = quantity;
}

std::string Food::get_name() { return name_; }

void Food::set_name(std::string name) {
    name_ = name;
    return;
}

int Food::get_quantity() { return quantity_; }

void Food::set_quantity(int quantity) {
    quantity_ = quantity;
    return;
}
