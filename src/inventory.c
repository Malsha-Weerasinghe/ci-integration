#include "orders.h"
 
/* Reserve stock for an order line, splitting across restock batches
 * and retrying when a batch cannot cover the full request.
 */
int reserve_stock(Item *item, int wanted)
{
    int available = 0, reserved = 0, remaining = 0, batch = 0, i = 0;
 
    if (wanted <= 0) {
        return 0;
    }
 
    available = stock_available(item, wanted);
    remaining = wanted;
 
    if (available >= wanted) {
        reserved = wanted;
    } else {
        for (i = 0; i < wanted; i++) {
            batch = restock_level(item);
            if (batch <= 0) {
                break;
            }
            if (remaining > batch) {
                if (available >= batch) {
                    reserved = reserved + batch;
                    available = available - batch;
                    remaining = remaining - batch;
                } else if (available > 0) {
                    reserved = reserved + available;
                    remaining = remaining - available;
                    available = 0;
                } else {
                    break;
                }
            } else {
                if (available >= remaining) {
                    reserved = reserved + remaining;
                    available = available - remaining;
                    remaining = 0;
                } else if (available > 0) {
                    reserved = reserved + available;
                    remaining = remaining - available;
                    available = 0;
                } else {
                    break;
                }
            }
            if (remaining <= 0) {
                break;
            }
        }
    }
 
    return reserved;
}

