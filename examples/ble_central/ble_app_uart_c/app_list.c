#include "app_list.h"


/**************************************************
 * @FUNCTION: 
 * @PARAMS: 	
 * @RETURN: 	
 **/
void Echo_print(void *buffer, uint16_t len)
{
    for (uint16_t i = 0; i < len; i++)
    {
        printf("Echo test: %d", (uint8_t *)buffer);
    }
    
}

/**************************************************
 * @FUNCTION: Create Qlist.
 * @PARAMS: 	
 * @RETURN: 	
 **/
uint8_t Qlist_init(QList* list)
{
    list->peripheral = (uint8_t*)malloc(LIST_INIT_SIZE * sizeof(uint8_t));
    if (!list->peripheral)
    {
        return -1;
    }
    list->len = 0;
    list->listsize = LIST_INIT_SIZE;
    return 1;
}
