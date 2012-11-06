#ifndef _NEWORDER_H_
#define _NEWORDER_H_

#include <stdint.h>                    //for uint64_t

extern void newOrder(int w_id, int d_id, int c_id, int items, long int supware[15], long int itemid[15], long int qty[15], uint64_t datetime);
extern void delivery(int w_id, int o_carrier_id, uint64_t datetime);

#endif //_NEWORDER_H_