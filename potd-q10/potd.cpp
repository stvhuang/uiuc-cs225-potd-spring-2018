// your code here!

#include "potd.h"
#include <cmath>

namespace potd {
int *raise(int *arr) {
    int num_element = 0;
    for (int i = 0;; ++i) {
        ++num_element;
        if (arr[i] == -1) {
            break;
        }
    }

    int *result = new int[num_element];

    for (int i = 0; i < num_element - 1; ++i) {
        result[i] = std::pow(arr[i], arr[i + 1]);
    }

    result[num_element - 2] = arr[num_element - 2];
    result[num_element - 1] = arr[num_element - 1];

    return result;
}
}  // namespace potd
