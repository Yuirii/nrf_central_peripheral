#ifndef _APP_QUE_H_
#define _APP_QUE_H_

#include <stdint.h>

/*DEFINE*/
#define MAX_QSIZE   10
typedef struct  
{
    uint8_t     *base;
    uint8_t    	front;
    uint8_t    	rear;
}Qque;


/*FUNCTION*/
int que_func(int (*func_ptr)(Qque*, uint8_t*), Qque* que, uint8_t *elem);
int que_init(Qque *que);
int qlen_get(Qque *que);
int que_emp(Qque *que);
int que_full(Qque *que);
int que_ent(Qque *que, uint8_t *elem);
int que_del(Qque *que, uint8_t *elem);
void que_print(Qque *que);



#endif
