// your code here

#include "Bar.h"

namespace potd {
    Bar::Bar(string name) {
        f_ = new Foo(name);
    }

    Bar::Bar(const Bar &other) {
        f_ = new Foo(other.get_name());
    }

    Bar::~Bar() {
        delete f_;
    }

    Bar & Bar::operator=(const Bar &other) {
        delete f_;
        f_ = new potd::Foo(other.get_name());
        return *this;
    }

    string Bar::get_name() const {
        return f_->get_name();
    }
}
