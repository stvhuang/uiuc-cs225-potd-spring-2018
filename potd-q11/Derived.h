#ifndef DERIVED_H_
#define DERIVED_H_

#include "Base.h"

class Derived : public Base {
  public:
    virtual ~Derived();
    std::string foo();
    virtual std::string bar();
};

#endif
