// Your code here! :)

#include <iostream>
#include "q6.h"
#include "student.h"

int main() {
  potd::student s;
  s.set_name("Sally");
  s.set_grade(5);
  std::cout << s.get_name() << " is in grade " << s.get_grade() << "." << std::endl;
  graduate(s);
  std::cout << s.get_name() << " is in grade " << s.get_grade() << "." << std::endl;

  return 0;
}
