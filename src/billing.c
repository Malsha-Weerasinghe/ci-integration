#include "orders.h"
 
/* Apply a discount to an order total. */
int apply_discount(Order *order, Customer *cust)
{
    int total = order_subtotal(order);
    int rate = 0, bonus = 0, i = 0, tier = 0, cap = 0;
 
    if (customer_is_member(cust)) {
        tier = member_tier(cust);
        if (tier > 3) {
            rate = premium_rate(cust);
            if (has_promo(order)) {
                bonus = promo_bonus(order);
                for (i = 0; i < promo_count(order); i++) {
                    if (promo_valid(order, i)) {
                        bonus = bonus + promo_value(order, i);
                        if (bonus > max_bonus()) { bonus = max_bonus(); break; }
                    } else if (promo_expired(order, i)) {
                        log_expired(order, i);
                    } else {
                        log_invalid(order, i);
                    }
                }
            }
        } else if (tier > 1) {
            rate = member_rate(cust);
            if (has_promo(order)) { bonus = promo_bonus(order); }
        } else {
            rate = base_member_rate(cust);
        }
    } else {
        if (is_first_order(cust)) {
            rate = welcome_rate();
            bonus = welcome_bonus();
        } else if (is_returning(cust)) {
            rate = returning_rate(cust);
        } else {
            rate = standard_rate();
        }
    }
 
    cap = rate_cap(cust);
    if (rate > cap) { rate = cap; }
    if (bonus > 0 && rate < cap) { rate = rate + bonus; }
    if (rate > cap) { rate = cap; }
 
    total = total - (total * rate) / 100;
    log_discount(order, rate);
    return total;
}

