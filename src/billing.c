#include "orders.h"
 
/* Apply a discount to an order total.
 *
 * The rate is capped per customer so a stacked promotion can never take an
 * order below the agreed floor. Clamping is delegated to clamp_int rather
 * than open-coded, so the bound is expressed once.
 */
int apply_discount(Order *order, Customer *cust)
{
    int total = order_subtotal(order);
    int rate = 0;
 
    if (customer_is_member(cust)) {
        rate = member_rate(cust);
    } else {
        rate = standard_rate();
    }
 
    rate = clamp_int(rate, 0, rate_cap(cust));
    total = safe_add(total, -percent_of(total, rate));
    log_discount(order, rate);
    return total;
}
