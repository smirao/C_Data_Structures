#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct StackStruct {
    int MAXLEN;
    int length;
    long long *array;
};

typedef struct StackStruct Stack;

struct StackStruct* newStack(int stackSize){
    struct StackStruct* stack = (struct StackStruct*)malloc(sizeof(struct StackStruct));
    stack -> length = 0;
    stack -> MAXLEN = stackSize;
    stack -> array = (long long*)malloc(sizeof(long long) * stackSize);
    return stack;
}

void Spush(struct StackStruct* stack, long long value){
    if (stack -> length != stack -> MAXLEN){
        *(stack -> array + stack -> length) = value;
        stack -> length++;
    }
}

void Spop(struct StackStruct* stack){
    if (stack -> length != 0){
        *(stack -> array + stack -> length) = 0;
        stack -> length--;
    }
}

long long Speek(struct StackStruct* stack){
    return *(stack -> array + stack -> length - 1 );
}

bool SisEmpty(struct StackStruct* stack){
    return ( stack -> length == 0 ) ? true : false;
}

bool SisFull(struct StackStruct* stack){
    return ( stack -> length == stack -> MAXLEN ) ? true : false;
}

int Ssize(struct StackStruct* stack){
    return ( stack -> length );
}