#include "linked_list.c"
#include <stdio.h>
#include <stdlib.h>

int main() {

    /*-------------
    # Linked List #
    -------------*/
    
    int intArray[] = {1,2,3,4,5,6,7,8,9,10};
    int intArrayLen = sizeof(intArray)/sizeof(int);


    LinkedList* intListPtr = LLcreateFromArray(intArray, intArrayLen, INT);

    LLpop(intListPtr);

    LLappend(intListPtr, 999);

    LLinsert(intListPtr, 7, 777);

    LLremoveIndex(intListPtr, 3);


    int length = LLlength(intListPtr);

    for (int i = 0; i < length; i++){
        printf("%d => %d\n", i, (int)LLvalueAt(intListPtr, i));
    }



    /*-------
    # Stack #
    -------*/
    return 0;
}