#include <cmath>
#include "function.h"

using namespace std;

bool is_same_point(Point &p1, Point &p2) {
    int sum(0);

    sum = fabs(p1.get_x() - p2.get_x()) +
          fabs(p1.get_y() - p2.get_y());

    /*
     * Is the sum equals zero, then they are equal. By casting
     * into an bool we get false since 0 = false. We have to
     * flip the bit in order to make it true.
     */
    return !(bool)sum;
}

double rad_to_deg(double rad) {
    return (rad*180)/M_PI;
}
