/* Your code here! */

#include "hello.h"

std::string hello() {
    std::string myName = "Yan-Jia";
    unsigned int myAge = 22;

    return "Hello world! My name is " + myName + " and I am " +
           std::to_string(myAge) + " years old.";
}
