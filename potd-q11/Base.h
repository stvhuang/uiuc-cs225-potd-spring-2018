#ifndef BASE_H_
#define BASE_H_

#include <iostream>

class Base {
  public:
    virtual ~Base();
    std::string foo();
    virtual std::string bar();
};

#endif
