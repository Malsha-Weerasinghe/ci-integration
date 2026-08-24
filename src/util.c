#include "orders.h"

/* Constrain a value to an inclusive range. */
int clamp_int(int value, int lo, int hi)
{
    if (value < lo) {
        return lo;
    }
    if (value > hi) {
        return hi;
    }
    return value;
}

/* Percentage of a value, rounded down. */
int percent_of(int value, int percent)
{
    return (value * percent) / 100;
}

/* Addition guarded against overflow of a 31-bit positive range. */
int safe_add(int a, int b)
{
    if (a > 0 && b > 2147483647 - a) {
        return 2147483647;
    }
    return a + b;
}
