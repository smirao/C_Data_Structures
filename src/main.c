#include "linked_list.c"
#include "stack.c"
#include "queue.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void space(){
    printf("\n\n\n\n");
}

int main() {
    /*-------------
    # Linked List #
    -------------*/
    
    /*int intArray[] = {1,2,3,4,5,6,7,8,9,10};
    int intArrayLen = sizeof(intArray)/sizeof(int);


    LinkedList* intListPtr = LLcreateFromArray(intArray, intArrayLen, INT);

    LLpop(intListPtr);

    LLappend(intListPtr, 999);
    
    LLpopFront(intListPtr);

    LLappendFront(intListPtr, 888);

    LLinsert(intListPtr, 7, 777);

    LLremoveIndex(intListPtr, 3);


    int length = LLlength(intListPtr);

    for (int i = 0; i < length; i++){
        printf("%d => %d\n", i, (int)LLvalueAt(intListPtr, i));
    }*/



    /*-------
    # Stack #
    -------*/
    /*space();

    Stack* intStack = newStack(10);

    for (int i = 1; i <= 6; i++){
        Spush(intStack, i);
    }

    Spop(intStack);

    Spush(intStack, 777);

    bool isEmpty = SisEmpty(intStack);

    bool isFull = SisFull(intStack);

    int size = Ssize(intStack);

    int peeked = (int)Speek(intStack);

    printf("Is Empty: %s\nIs Full: %s\nLength: %d\nPeeked: %d\n", isEmpty ? "true" : "false", isFull ? "true" : "false", size, peeked);
    
    */

   /*-------
    # Queue #
    -------*/
    space();

    Queue* intQueue = newQueue(10);

    for (int i = 1; i <= 6; i++){
        Qenqueue(intQueue, i);
    }

    Qdequeue(intQueue);

    Qdequeue(intQueue);

    Qenqueue(intQueue, 111);

    Qenqueue(intQueue, 222);

    bool isEmpty = QisEmpty(intQueue);

    bool isFull = QisFull(intQueue);

    int peeked = (int)Qpeek(intQueue);

    printf("Is Empty: %s\nIs Full: %s\nPeeked: %d\n", isEmpty ? "true" : "false", isFull ? "true" : "false", peeked);


    return 0;
}