#include "orders.h"
 
/* Extra bonus granted on top of a customer's individual promotions. */
int promo_bonus(Order *order)
{
    int bonus = 0;
 
    if (!has_promo(order)) {
        return 0;
    }
    if (promo_count(order) > 1) {
        bonus = percent_of(promo_total(order), 10);
    } else {
        bonus = percent_of(promo_total(order), 5);
    }
    if (bonus > max_bonus()) {
        bonus = max_bonus();
    }
    return bonus;
}
