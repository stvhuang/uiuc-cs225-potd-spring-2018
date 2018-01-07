// your code here

#ifndef BAR_H_
#define BAR_H_

#include "Foo.h"
#include <string>

using namespace std;

namespace potd {
class Bar {
  public:
    Bar(string);
    Bar(const Bar &);
    ~Bar();
    Bar &operator=(const Bar &);
    string get_name() const;

  private:
    Foo *f_;
};
}  // namespace potd

#endif
