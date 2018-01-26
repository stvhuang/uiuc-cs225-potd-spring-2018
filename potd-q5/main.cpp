// your code here

#include <iostream>
#include "Food.h"
#include "q5.h"

int main() {
    Food food("apple", 5);

    std::cout << "You have " << food.get_quantity() << " " << food.get_name();
    if (food.get_quantity() > 1) {
        std::cout << "s." << std::endl;
    } else {
        std::cout << "." << std::endl;
    }

    increase_quantity(&food);

    std::cout << "You have " << food.get_quantity() << " " << food.get_name();
    if (food.get_quantity() > 1) {
        std::cout << "s." << std::endl;
    } else {
        std::cout << "." << std::endl;
    }

    return 0;
}
