// your code here

#include "Food.h"
#include "q5.h"

void increase_quantity(Food *f) {
    int currQuantity = f->get_quantity();
    f->set_quantity(currQuantity + 1);
    return;
}
