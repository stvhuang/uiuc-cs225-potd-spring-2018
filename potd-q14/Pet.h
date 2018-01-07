// Pet.h

#ifndef PET_H_
#define PET_H_

#include "Animal.h"

class Pet : public Animal {
  public:
    Pet();
    Pet(string type, string food, string name, string owner_name);
    void setFood(string food);
    string getFood();
    void setName(string name);
    string getName();
    void setOwnerName(string owner_name);
    string getOwnerName();
    string print();

  private:
    string name_;
    string owner_name_;
};

#endif
