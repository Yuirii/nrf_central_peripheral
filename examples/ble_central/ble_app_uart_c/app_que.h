#ifndef _APP_QUE_H_
#define _APP_QUE_H_

#include <stdint.h>

/*DEFINE*/
#define MAX_QSIZE   10
typedef struct  
{
    uint8_t     *base;
    uint16_t    front;
    uint16_t    rear;
}Qque;


/*FUNCTION*/
int que_init(Qque *que);
int qlen_get(Qque *que);
int que_ent(Qque *que, uint8_t elem);
int que_del(Qque *que, uint8_t elem);



#endif