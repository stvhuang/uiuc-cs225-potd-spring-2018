// Your code here! :)

#include "student.h"

potd::student::student() {}

std::string potd::student::get_name() {
  return name_;
}

void potd::student::set_name(std::string n) {
  name_ = n;
  return;
}

int potd::student::get_grade() {
  return grade_;
}

void potd::student::set_grade(int g) {
  grade_ = g;
}
