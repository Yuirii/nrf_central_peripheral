#include "app_que.h"
#include "stdlib.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

/**************************************************
 * @FUNCTION: 	
 * @PARAMS: 	
 * @RETURN: 	
 **/
int que_func(int (*func_ptr)(Qque*, uint8_t*), Qque* que, uint8_t *elem)
{
    return func_ptr(que, elem);
}


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
    que->front = 0;
	que->rear = 0;
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
 * @FUNCTION: Is full?
 * @PARAMS: 	
 * @RETURN: 	
 **/
int que_full(Qque *que)
{
    return (que->front == (que->rear+1) % MAX_QSIZE)?1:0;
}

/**************************************************
 * @FUNCTION: Is empty?
 * @PARAMS: 	
 * @RETURN: 	
 **/
int que_emp(Qque *que)
{
    return (que->front == que->rear)?1:0;
}

/**************************************************
 * @FUNCTION: Enter.
 * @PARAMS: 	
 * @RETURN: 	
 **/
int que_ent(Qque *que, uint8_t *elem)
{
	printf("1:%d  %d\n", que->front, que->rear);
    if (que_full(que))
    {
        return -1;
    }
    
    que->base[que->rear] = *elem;
    que->rear = (que->rear+1) % MAX_QSIZE;
    return 1;
}

/**************************************************
 * @FUNCTION: Delete.
 * @PARAMS: 	
 * @RETURN: 	
 **/
int que_del(Qque *que, uint8_t *elem)
{
    if (que->front == que->rear)    
    {
        return -1;
    }

    *elem = que->base[que->front];
    que->front = (que->front + 1) % MAX_QSIZE;

    return 1;
}

/**************************************************
 * @FUNCTION: 
 * @PARAMS: 	
 * @RETURN: 	
 **/
void que_print(Qque *que)
{
    if (que_emp(que))
    {
        NRF_LOG_INFO("Empty.");
        
    }else{
        for(uint8_t i = que->front; i < que->rear; i++)
        {
            NRF_LOG_INFO("Que is %d\n", que->base[i]);
        }
		
    }	    
}

