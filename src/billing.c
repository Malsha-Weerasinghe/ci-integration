#include "orders.h"
 
/* Rate for a member, chosen by loyalty tier. */
static int member_tier_rate(Customer *cust)
{
    int tier = member_tier(cust);
 
    if (tier > 3) {
        return premium_rate(cust);
    }
    if (tier > 1) {
        return member_rate(cust);
    }
    return base_member_rate(cust);
}
 
/* Rate for a non-member, chosen by order history. */
static int guest_rate(Customer *cust)
{
    if (is_first_order(cust)) {
        return welcome_rate();
    }
    if (is_returning(cust)) {
        return returning_rate(cust);
    }
    return standard_rate();
}
 
/* Apply a discount to an order total. */
int apply_discount(Order *order, Customer *cust)
{
    int total = order_subtotal(order);
    int rate = 0;
 
    if (customer_is_member(cust)) {
        rate = member_tier_rate(cust);
    } else {
        rate = guest_rate(cust);
    }
 
    rate = clamp_int(rate, 0, rate_cap(cust));
    total = safe_add(total, -percent_of(total, rate));
    log_discount(order, rate);
    return total;
}
