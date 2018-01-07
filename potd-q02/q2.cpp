/* Problem of the Day #2 */

#include "epoch.h"
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    time_t sec_since_epoch = time(nullptr);

    cout << "Hours: " << hours(sec_since_epoch) << endl;
    cout << "Days: " << days(sec_since_epoch) << endl;
    cout << "Years: " << years(sec_since_epoch) << endl;

    return 0;
}
