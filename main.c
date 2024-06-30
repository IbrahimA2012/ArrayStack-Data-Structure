#include <stdio.h>
#include <stdlib.h>
#include "Std_Types.h"
#include "Stack_BasedOn_DaynamicArray.h"

/** Initialize stack **/
uint32 Stack1_Size = 5 ;
StackDaynamic_t *stack1 ;

/** stack count variable **/
uint32 stack_count =0;

/** stack element variable **/
uint32 var1 = 10 ;
uint32 var2 = 25 ;
float32 var3 = 2.8 ;
uint32 var4 = 1 ;
uint32 var5 = 5 ;
char var6 = 'I' ;

/** stack top pointer **/
void *stackTopVar = NULL;

/** Pop stack variable **/
void *stackPOP = NULL ;

/** Status variable **/
stackStatus_t status = 0 ;
int main()
{
    /** Create Stack **/
    stackStatus_t stack1_status = STACK_NOK ;
    stack1 = createStack(Stack1_Size,&stack1_status);

    if(stack1_status == STACK_NOK)
    {
        printf("Error !\n");
    }else{
        printf("Stack created !\n");
    }


    printf("***************************************************************************\n");
    /** Push to the stack **/
    status = PushToStack(stack1,&var1);printf("stack status = %i\n",status);
    status = PushToStack(stack1,&var2);printf("stack status = %i\n",status);
    status = PushToStack(stack1,&var3);printf("stack status = %i\n",status);
    status = PushToStack(stack1,&var4);printf("stack status = %i\n",status);
    status = PushToStack(stack1,&var5);printf("stack status = %i\n",status);
    status = PushToStack(stack1,&var6);printf("stack status = %i\n",status);//Error stack is full


    printf("***************************************************************************\n");
    /** Number of element in the stack **/
    status = StackCount(stack1,&stack_count);("stack count status = %i\n",status);
    printf("Element count = %i \n",stack_count);


    printf("***************************************************************************\n");
    /** Return Top of the stack **/
    stackTopVar = StackTop(stack1,&stack1_status);
    printf("Top value in the stack :  %i \n",*((uint32 *)stackTopVar));


    printf("***************************************************************************\n");
    /** Pop from the stack **/
    stackPOP = PopStack(stack1,&stack1_status);printf("stack status = %i\n",stack1_status);
    printf("return value[1] from the stack :  %i \n",*((uint32 *)stackPOP));
    stackPOP = PopStack(stack1,&stack1_status);printf("stack status = %i\n",stack1_status);
    printf("return value[2] from the stack :  %i \n",*((uint32 *)stackPOP));
    stackPOP = PopStack(stack1,&stack1_status);printf("stack status = %i\n",stack1_status);
    printf("return value[3] from the stack :  %f \n",*((float32 *)stackPOP));
    stackPOP = PopStack(stack1,&stack1_status);printf("stack status = %i\n",stack1_status);
    printf("return value[4] from the stack :  %i \n",*((uint32 *)stackPOP));
    stackPOP = PopStack(stack1,&stack1_status);printf("stack status = %i\n",stack1_status);
    printf("return value[5] from the stack :  %i \n",*((uint32 *)stackPOP));

    /*
    stackPOP = PopStack(stack1,&stack1_status);printf("stack status = %i\n",stack1_status);//Error stack is empty print 3
    printf("return value[6] from the stack :  %i \n",*((uint32 *)stackPOP));*/


    printf("***************************************************************************\n");
    /** Number of element in the stack **/
    status = StackCount(stack1,&stack_count);("stack count status = %i\n",status);
    printf("Element count = %i \n",stack_count);


    printf("***************************************************************************\n");
    /** Destroy stack after finish **/
    DestroyStack(stack1,&stack1_status);
    if(stack1_status == STACK_NOK)
    {
        printf("Error !\n");
    }else{
        printf("Stack Destroyed !\n");
    }

    return 0;
}
