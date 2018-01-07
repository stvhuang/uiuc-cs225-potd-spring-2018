/* Your code here! */
#include "epoch.h"

int hours(time_t t) { return t / (60 * 60); }

int days(time_t t) { return hours(t) / 24; }

int years(time_t t) { return days(t) / 365; }
