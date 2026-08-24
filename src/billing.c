#include "orders.h"

/* Apply a discount to an order total. */
int apply_discount(Order *order, Customer *cust)
{
    int total = order_subtotal(order);
    int rate = 0;

    if (customer_is_member(cust)) {
        rate = member_rate(cust);
    } else {
        rate = standard_rate();
    }

    total = total - (total * rate) / 100;
    log_discount(order, rate);
    return total;
}
