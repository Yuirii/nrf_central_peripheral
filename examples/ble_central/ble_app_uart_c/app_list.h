#ifndef _APP_LIST_H_
#define _APP_LIST_H_

#include <stdint.h>

/*define*/
#define LIST_INIT_SIZE  10
#define LIST_INCREMENT  5

typedef struct
{
    uint8_t     *peripheral;
    uint16_t    len;
    uint16_t    listsize;    
}QList;






#endif 