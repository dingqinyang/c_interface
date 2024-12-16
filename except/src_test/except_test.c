#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "except.h"

int Allocation_handled = 0;
Except_T Allocate_Failed = {"Allocation failed"};
void *allocate(unsigned n)
{
    void *new = malloc(n);

    if (new && 0) { //用于制造错误情况，正常不加 &&0 语句
        return new;
    }
    RAISE(Allocate_Failed);
    assert(0);
}

int main(){
    char *buf = NULL;
    Allocation_handled = 1;
    extern Except_T Allocate_Failed;
    TRY
        buf = allocate(1024);
    EXCEPT(Allocate_Failed)
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    END_TRY;

    return 0;
}