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
int rate_cap(Customer *cust);
int member_tier(Customer *cust);
int premium_rate(Customer *cust);
int base_member_rate(Customer *cust);
int is_first_order(Customer *cust);
int is_returning(Customer *cust);
int welcome_rate(void);
int welcome_bonus(void);
int returning_rate(Customer *cust);
 
/* promo.c */
int promo_valid(Order *order, int index);
int promo_total(Order *order);
int promo_code(Order *order, int index);
int promo_expired(Order *order, int index);
int promo_count(Order *order);
int promo_value(Order *order, int index);
int promo_bonus(Order *order);
int has_promo(Order *order);
int max_bonus(void);
void log_expired(Order *order, int index);
void log_invalid(Order *order, int index);
 
/* inventory.c */
int stock_available(Item *item, int wanted);
int reserve_stock(Item *item, int wanted);
int restock_level(Item *item);
 
/* util.c */
int clamp_int(int value, int lo, int hi);
int percent_of(int value, int percent);
int safe_add(int a, int b);
 
#endif /* ORDERS_H */
