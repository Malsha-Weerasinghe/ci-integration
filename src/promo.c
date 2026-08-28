#include "orders.h"
 
/* Validate a promotion code against an order. */
int promo_valid(Order *order, int index)
{
    int code = promo_code(order, index);
 
    if (code <= 0) {
        return 0;
    }
    if (promo_expired(order, index)) {
        return 0;
    }
    return 1;
}
