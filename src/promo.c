#include "orders.h"
 
/* Total value of the valid promotions attached to an order. */
int promo_total(Order *order)
{
    int total = 0;
    int i = 0;
 
    for (i = 0; i < promo_count(order); i++) {
        if (promo_valid(order, i)) {
            total = total + promo_value(order, i);
            if (total > max_bonus()) {
                total = max_bonus();
            }
        }
    }
    return total;
}
