// Animal.h

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>

class Animal {
  public:
    Animal();
    Animal(std::string type, std::string food);
    std::string getType();
    void setType(std::string type);
    std::string getFood();
    void setFood(std::string food);
    virtual std::string print();

  protected:
    std::string type_;
    std::string food_;
};

#endif
