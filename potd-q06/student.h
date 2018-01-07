// Your code here! :)

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

namespace potd {
class student {
  public:
    student();
    std::string get_name();
    void set_name(std::string);
    int get_grade();
    void set_grade(int);

  private:
    std::string name_;
    int grade_;
};
}  // namespace potd

#endif
