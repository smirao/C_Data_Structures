#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct QueueStruct {
    struct Qnode* startNode;
    struct Qnode* endNode;
    int numOfNodes;
    int MAXLEN;
};

typedef struct QueueStruct Queue;

struct Qnode {
    struct Qnode* previousNode;
    struct Qnode* nextNode;
    long long value;
};

struct QueueStruct* newQueue(int queueLength) {
    struct QueueStruct* newQueue = (struct QueueStruct*)malloc(sizeof(struct QueueStruct));
    newQueue -> MAXLEN = queueLength;
    newQueue -> numOfNodes = 0;
    newQueue -> startNode = NULL;
    newQueue -> endNode = NULL;
    return newQueue;
}

void Qenqueue(struct QueueStruct* queue, long long value){
    if (queue -> numOfNodes != queue -> MAXLEN){
        if (queue -> numOfNodes == 0) {
            struct Qnode* firstNode = (struct Qnode*)malloc(sizeof(struct Qnode));
            firstNode -> nextNode = NULL;
            firstNode -> previousNode = NULL;
            firstNode -> value = value;

            queue -> numOfNodes++;
            queue -> startNode = firstNode;
            queue -> endNode = firstNode;
        } else {
            struct Qnode* newNode = (struct Qnode*)malloc(sizeof(struct Qnode));
            newNode -> nextNode = NULL;
            newNode -> previousNode = queue -> endNode;
            queue -> endNode -> nextNode = newNode;
            newNode -> value = value;

            queue -> numOfNodes++;
            queue -> endNode = newNode;
        }
    }
}

void Qdequeue(struct QueueStruct* queue){
    //Execute as long as nodes exist
    if (queue -> numOfNodes != 0){
        if (queue -> numOfNodes >= 2){
            //get ptr to last node then set next node's previousNode ptr to NULL
            //also set Queue struct endNode ptr to the previous node's ptr
            struct Qnode* toBeFreed = queue -> startNode;
            queue -> startNode -> nextNode -> previousNode = NULL;
            queue -> startNode = queue -> startNode -> nextNode;
            queue -> numOfNodes--;
            free(toBeFreed);
        } else {
            free(queue -> endNode);
            queue -> startNode = NULL;
            queue -> endNode = NULL;
            queue -> numOfNodes--;
        }
    }
}

bool QisFull(struct QueueStruct* queue){
    return (queue -> numOfNodes == queue -> MAXLEN) ? true : false;
}

bool QisEmpty(struct QueueStruct* queue){
    return (queue -> numOfNodes == 0) ? true : false;
}

long long Qpeek(struct QueueStruct* queue){
    if (!(QisEmpty(queue))) {
        return queue -> startNode -> value;
    } else {
        return 0;
    }
}
