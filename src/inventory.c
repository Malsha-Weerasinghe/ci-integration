#include "orders.h"

/* Whether the requested quantity can be met from stock. */
int stock_available(Item *item, int wanted)
{
    int on_hand = restock_level(item);

    if (wanted <= 0) {
        return 0;
    }
    return on_hand >= wanted;
}

/* Reserve stock for an order, returning the quantity actually reserved. */
int reserve_stock(Item *item, int wanted)
{
    int on_hand = restock_level(item);

    if (!stock_available(item, wanted)) {
        return 0;
    }
    return clamp_int(wanted, 0, on_hand);
}
