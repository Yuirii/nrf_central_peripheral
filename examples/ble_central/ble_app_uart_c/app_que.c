#include "app_que.h"
#include "stdlib.h"

/**************************************************
 * @FUNCTION: Creation. 
 * @PARAMS: 	
 * @RETURN: 	
 **/
int que_init(Qque *que)
{
    que->base = (uint8_t *)malloc(MAX_QSIZE * sizeof(uint8_t));
    if (!que->base)
    {
        return -1;  
    }

    que->front = que->rear = 0;
    return 1;
}

/**************************************************
 * @FUNCTION: Length.
 * @PARAMS: 	
 * @RETURN: 	
 **/
int qlen_get(Qque *que)
{
    return (que->rear - que->front + MAX_QSIZE) % MAX_QSIZE;
}

/**************************************************
 * @FUNCTION: Enter.
 * @PARAMS: 	
 * @RETURN: 	
 **/
int que_ent(Qque *que, uint8_t elem)
{
    if ((que->rear + 1) % MAX_QSIZE == que->front)
    {
        return -1;
    }

    que->base[que->rear] = elem;
    que->rear = (que->rear+1) % MAX_QSIZE;
    return 1;    
}

/**************************************************
 * @FUNCTION: Delete.
 * @PARAMS: 	
 * @RETURN: 	
 **/
int que_del(Qque *que, uint8_t elem)
{
    if (que->front == que->rear)    
    {
        return -1;
    }

    elem = que->base[que->front];
    que->front = (que->front + 1) % MAX_QSIZE;

    return 1;
}
