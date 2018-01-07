// Your code here

#ifndef FOOD_H_
#define FOOD_H_

#include <string>

class Food {
  public:
    Food(std::string name = "unknown", int quantity = 1);
    std::string get_name();
    void set_name(std::string);
    int get_quantity();
    void set_quantity(int);

  private:
    std::string name_;
    int quantity_;
};

#endif
