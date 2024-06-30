#ifndef _Stack_BasedOn_DaynamicArray_H
#define _Stack_BasedOn_DaynamicArray_H

#include "Std_Types.h"

typedef struct {
void    **stackArray; /**Points to the array to allocated to the heap**/
sint32  elementCount; /**Has the actual number in the stack**/
uint32  stackMaxSize; /**Has the maximum number in the stck**/
sint32  stackTop;     /**Has the index of the top value in the stack**/
}StackDaynamic_t;

typedef enum{
STACK_NOK = 0,          /**Not performed successfully **/
STACK_OK,               /** performed successfully **/
STACK_FULL,             /**Stack is full **/
STACK_EMPTY,            /**stack is empty **/
STACK_NULL_POINTER      /**there is a null pointer passing as a parameter **/
}stackStatus_t;


/**
  * @brief  Create an Empty Stack by allocating the head structure
            and the array from the dynamic memory
  * @param  (MaxSize) Max number of element in the stack
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to the allocated stack in the heap
**/
StackDaynamic_t *createStack(uint32 MaxSize , stackStatus_t *ret_status);

/**
  * @brief  Destroy Stack by freeing allocating memmory
  * @param  (stack_Obj) pointer to stack object
  * @param  (ret_status) Status returned while performing this operation
  * @retval Pointer to the allocated stack in the heap
**/
StackDaynamic_t *DestroyStack(StackDaynamic_t *stack_Obj , stackStatus_t *ret_status);

/**
  * @brief  Push Element to the stack
  * @param  (stack_Obj) pointer to the created stack
  * @param  (itemPtr) Element that push to the stack
  * @retval status of function
**/
stackStatus_t PushToStack(StackDaynamic_t *stack_Obj ,void *itemPtr);

/**
  * @brief  POP Element from the stack
  * @param  (stack_Obj) pointer to the created stack
  * @param  (ret_status) Status returned while performing this operation
  * @retval void pointer to the element type
**/
void* PopStack(StackDaynamic_t *stack_Obj ,stackStatus_t *ret_status);

/**
  * @brief  Top Element in the stack
  * @param  (stack_Obj) pointer to the created stack
  * @param  (ret_status) Status returned while performing this operation
  * @retval void pointer to the element type
**/
void* StackTop(StackDaynamic_t *stack_Obj ,stackStatus_t *ret_status);

/**
  * @brief  Number of element in the stack
  * @param  (stack_Obj) pointer to the created stack
  * @param  (stack_count) pointer to the count value
  * @retval status of function
**/
stackStatus_t StackCount(StackDaynamic_t *stack_Obj ,uint32 *stack_count);

#endif // _Stack_BasedOn_DaynamicArray_H
