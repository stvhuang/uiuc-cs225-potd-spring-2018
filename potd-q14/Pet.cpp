// Pet.cpp

#include "Pet.h"

Pet::Pet() : Animal("cat", "fish"), name_("Fluffy"), owner_name_("Cinda") {}

Pet::Pet(string type, string food, string name, string owner_name)
    : Animal(type, food), name_(name), owner_name_(owner_name) {}

void Pet::setFood(string food) {
    food_ = food;
    return;
}

string Pet::getFood() { return food_; }

void Pet::setName(string name) {
    name_ = name;
    return;
}

string Pet::getName() { return name_; }

void Pet::setOwnerName(string owner_name) {
    owner_name_ = owner_name;
    return;
}

string Pet::getOwnerName() { return owner_name_; }

string Pet::print() { return "My name is " + name_; }
