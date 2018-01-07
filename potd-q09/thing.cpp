// Your code here!

#include "thing.h"

namespace potd {
Thing::Thing(int size)
    : properties_(new std::string[size]), values_(new std::string[size]),
      props_ct_(0), props_max_(size) {}

Thing::Thing(const Thing &other) {
    props_ct_ = other.props_ct_;
    props_max_ = other.props_max_;
    properties_ = new std::string[other.props_max_];
    values_ = new std::string[other.props_max_];
    for (int i = 0; i < other.props_ct_; ++i) {
        properties_[i] = other.properties_[i];
        values_[i] = other.values_[i];
    }
}

Thing &Thing::operator=(const Thing &other) {
    props_ct_ = other.props_ct_;
    props_max_ = other.props_max_;
    delete[] properties_;
    delete[] values_;
    properties_ = new std::string[other.props_max_];
    values_ = new std::string[other.props_max_];
    for (int i = 0; i < other.props_ct_; ++i) {
        properties_[i] = other.properties_[i];
        values_[i] = other.values_[i];
    }
    return *this;
}

Thing::~Thing() {
    if (properties_ != NULL) {
        delete[] properties_;
        properties_ = NULL;
    }

    if (values_ != NULL) {
        delete[] values_;
        values_ = NULL;
    }
}

int Thing::set_property(std::string name, std::string value) {
    for (int i = 0; i < props_ct_; ++i) {
        if (properties_[i] == name) {
            values_[i] = value;
            return i;
        }
    }

    if (props_ct_ != props_max_) {  // not full
        properties_[props_ct_] = name;
        values_[props_ct_] = value;
        return props_ct_++;
    }

    return -1;
}

std::string Thing::get_property(std::string name) {
    for (int i = 0; i < props_ct_; ++i) {
        if (properties_[i] == name) {
            return values_[i];
        }
    }

    return "";
}
}  // namespace potd
