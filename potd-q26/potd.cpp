// Your code here

#include "potd.h"

string getFortune(const string &s) {
    unsigned res = s.size() % 5;

    switch (res) {
    case 1:
        return "As you wish!";
    case 2:
        return "Nec spe nec metu!";
    case 3:
        return "Do, or do not. There is no try.";
    case 4:
        return "This fortune intentionally left blank.";
    default:
        return "Amor Fati!";
    }
}
