#ifndef ORDERS_H
#define ORDERS_H

typedef struct Order    Order;
typedef struct Customer Customer;
typedef struct Item     Item;

/* billing.c */
int apply_discount(Order *order, Customer *cust);
int order_subtotal(Order *order);
int standard_rate(void);
int member_rate(Customer *cust);
int customer_is_member(Customer *cust);
void log_discount(Order *order, int rate);

/* inventory.c */
int stock_available(Item *item, int wanted);
int reserve_stock(Item *item, int wanted);
int restock_level(Item *item);

/* util.c */
int clamp_int(int value, int lo, int hi);
int percent_of(int value, int percent);
int safe_add(int a, int b);

#endif /* ORDERS_H */
