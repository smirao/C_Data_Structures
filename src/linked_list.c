

#include <stdio.h>
#include <stdlib.h>

typedef enum {INT, CHAR} types;

struct LinkedListStruct {
    struct LLnode* startNode;
    struct LLnode* endNode;
    int numOfNodes;
} NewLinkedList = {NULL, NULL, 0};

typedef struct LinkedListStruct LinkedList;

struct LLnode {
    struct LLnode* previousNode;
    struct LLnode* nextNode;
    long long value;
};

void LLpop(struct LinkedListStruct* list){
    //Execute as long as elements exist
    if (list -> numOfNodes != 0){
        if (list -> numOfNodes >= 2){
            //get ptr to last node then set previous node's nextNode ptr to NULL
            //also set LinkedList struct endNode ptr to the previous node's ptr
            struct LLnode* toBeFreed = list -> endNode;
            list -> endNode -> previousNode -> nextNode = NULL;
            list -> endNode = list -> endNode -> previousNode;
            list -> numOfNodes--;
            free(toBeFreed);
        }
        
    }
}

void LLappend(struct LinkedListStruct* list, long long value){
    if (list -> numOfNodes == 0) {
        struct LLnode* firstNode = (struct LLnode*)malloc(sizeof(struct LLnode));
        firstNode -> nextNode = NULL;
        firstNode -> previousNode = NULL;
        firstNode -> value = value;

        list -> numOfNodes++;
        list -> startNode = firstNode;
        list -> endNode = firstNode;
    } else {
        struct LLnode* newNode = (struct LLnode*)malloc(sizeof(struct LLnode));
        newNode -> nextNode = NULL;
        newNode -> previousNode = list -> endNode;
        list -> endNode -> nextNode = newNode;
        newNode -> value = value;

        list -> numOfNodes++;
        list -> endNode = newNode;
    }
}

void LLinsert(struct LinkedListStruct* list, int index, long long value){
    struct LLnode* currentNode;
    if (index != list -> numOfNodes){
        if (list -> numOfNodes / 2 >= index && index >= 0){
            currentNode = list -> startNode;

            for (int i = 0; i < index; i++){
                currentNode = currentNode -> nextNode;
            }

        } else if (list -> numOfNodes / 2 <= index && index <= list -> numOfNodes - 1){

            currentNode = list -> endNode;

            for (int i = list -> numOfNodes - 1; i > index; i--){
                currentNode = currentNode -> previousNode;
            }
        }
        struct LLnode* newNode = (struct LLnode*)malloc(sizeof(struct LLnode));

        newNode -> value = value;
        newNode -> previousNode = currentNode -> previousNode;
        newNode -> nextNode = currentNode;
        currentNode -> previousNode -> nextNode = newNode;
        currentNode -> previousNode = newNode;
        list -> numOfNodes++;
    } else if (index == list -> numOfNodes){
        LLappend(list, value);
    }
}

void LLremoveIndex(struct LinkedListStruct* list, int index) {
    struct LLnode* currentNode;

    if (list -> numOfNodes / 2 >= index && index >= 0){
            currentNode = list -> startNode;

            for (int i = 0; i < index; i++){
                currentNode = currentNode -> nextNode;
            }


        } else if (list -> numOfNodes / 2 <= index && index <= list -> numOfNodes - 1){

            currentNode = list -> endNode;

            for (int i = list -> numOfNodes - 1; i > index; i--){
                currentNode = currentNode -> previousNode;
            }
        }

        currentNode -> previousNode -> nextNode = currentNode -> nextNode;
        currentNode -> nextNode -> previousNode = currentNode;
        list -> numOfNodes--;
}

long long LLvalueAt(struct LinkedListStruct* list, int index){
    if (list -> numOfNodes / 2 >= index && index >= 0){
        struct LLnode* currentNode = list -> startNode;

        for (int i = 0; i < index; i++){
            currentNode = currentNode -> nextNode;
        }
        return currentNode -> value;
    } else if (list -> numOfNodes / 2 <= index && index <= list -> numOfNodes - 1){

        struct LLnode* currentNode = list -> endNode;

        for (int i = list -> numOfNodes - 1; i > index; i--){
            currentNode = currentNode -> previousNode;
        }
        return currentNode -> value;
    }
    return -1;
}

int LLlength(struct LinkedListStruct* list){
    return list -> numOfNodes;
}

struct LinkedListStruct* LLcreateFromArray(void* arrayPtr, int arrayLen, types type){
    struct LinkedListStruct* newLinkedList = (struct LinkedListStruct*)malloc(sizeof(struct LinkedListStruct));
    
    switch (type){
        case INT:
            for (int i = 0; i < arrayLen; i++){
                LLappend(newLinkedList, *((int*)arrayPtr + i));
            }
            break;

        case CHAR:
            for (int i = 0; i < arrayLen; i++){
                LLappend(newLinkedList, *((char*)arrayPtr + i));
            }
            break;
    }
    
    return newLinkedList;
}