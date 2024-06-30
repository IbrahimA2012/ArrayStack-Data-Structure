#include "Stack_BasedOn_DaynamicArray.h"

static uint8 stackIsEmpty(StackDaynamic_t *stack_Obj);
static uint8 stackIsFull(StackDaynamic_t *stack_Obj);


StackDaynamic_t *createStack(uint32 MaxSize , stackStatus_t *ret_status){
    StackDaynamic_t *my_stack = NULL ;
    if(NULL == ret_status)
    {
        *ret_status = STACK_NULL_POINTER ;
         my_stack   = NULL ;
    }else{
         my_stack   = (StackDaynamic_t *)malloc(sizeof(StackDaynamic_t));
         if(!my_stack)
         {
             *ret_status = STACK_NOK ;
             my_stack    = NULL ;
         }else{
             my_stack->stackTop     = -1 ;
             my_stack->elementCount =  0 ;
             my_stack->stackMaxSize = MaxSize ;
             my_stack->stackArray   = (void **)calloc(my_stack->stackMaxSize,sizeof(void *));
             if(!my_stack->stackArray)
             {
                 free(my_stack);
                 *ret_status = STACK_NOK ;
             }else{
                 *ret_status = STACK_OK ;
             }
         }
    }
    return my_stack;
}

StackDaynamic_t *DestroyStack(StackDaynamic_t *stack_Obj , stackStatus_t *ret_status){
    if((NULL == ret_status) || (NULL == stack_Obj))
    {
        *ret_status = STACK_NULL_POINTER ;
    }else{
        free(stack_Obj->stackArray);
        free(stack_Obj);
        *ret_status = STACK_OK;
    }
    return NULL;
}

stackStatus_t PushToStack(StackDaynamic_t *stack_Obj ,void *itemPtr){
    stackStatus_t retStatus = STACK_NOK;
    if((NULL == itemPtr) || (NULL == stack_Obj))
    {
        retStatus = STACK_NULL_POINTER ;

    }else{
        if(stackIsFull(stack_Obj))
        {
            retStatus = STACK_FULL ;
        }else
        {
            (stack_Obj->stackTop)++;
            (stack_Obj->stackArray[stack_Obj->stackTop] = itemPtr);
            (stack_Obj->elementCount)++;
            retStatus = STACK_OK ;
        }
    }
  return retStatus ;
}

void* PopStack(StackDaynamic_t *stack_Obj ,stackStatus_t *ret_status){
    void *dataPtrOut = NULL ;
    if((NULL == ret_status) || (NULL == stack_Obj))
    {
        *ret_status = STACK_NULL_POINTER ;
    }else{
        if(stackIsEmpty(stack_Obj))
        {
            *ret_status = STACK_EMPTY ;
        }
        else
        {
          dataPtrOut = stack_Obj->stackArray[stack_Obj->stackTop];
          (stack_Obj->stackTop)--;
          (stack_Obj->elementCount)--;
          *ret_status = STACK_OK;
        }
    }
    return dataPtrOut ;
}

void* StackTop(StackDaynamic_t *stack_Obj ,stackStatus_t *ret_status)
{
    void *dataPtrOut = NULL ;
    if((NULL == ret_status) || (NULL == stack_Obj))
    {
        *ret_status = STACK_NULL_POINTER ;
        dataPtrOut =NULL;
    }else{
        if(stackIsEmpty(stack_Obj))
        {
            *ret_status = STACK_EMPTY ;
            dataPtrOut =NULL;
        }
        else
        {
          dataPtrOut = stack_Obj->stackArray[stack_Obj->stackTop];
          *ret_status = STACK_OK;
        }
    }
    return dataPtrOut ;
}

stackStatus_t StackCount(StackDaynamic_t *stack_Obj ,uint32 *stack_count){
    stackStatus_t retStatus = STACK_NOK;
    if((NULL == stack_count) || (NULL == stack_Obj))
    {
        retStatus = STACK_NULL_POINTER;
    }else{
        *stack_count = stack_Obj->elementCount ;
        retStatus = STACK_OK;
    }
    return retStatus;
}

static uint8 stackIsEmpty(StackDaynamic_t *stack_Obj){
    return(stack_Obj->elementCount == 0) ;
}
static uint8 stackIsFull(StackDaynamic_t *stack_Obj){
    return(stack_Obj->elementCount == stack_Obj->stackMaxSize) ;
}
