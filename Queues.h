#include <stdio.h>
#include <stdlib.h>
typedef struct Info Info;

typedef struct {
Info *info;
} PQueue;
//-1
// O(1)
int pqGetErrorCode(PQueue q);
//-2
// O(1)
PQueue pqInit();
//-3
// O(n)
int pqInsert(void *data, int priority, PQueue q);
//-4
// O(1)
void * pqRemoveMax(PQueue q);
//-5
// O(1)
void * pqPeek(PQueue q);
//-6
// O(1)
int pqGetSize(PQueue q);
//-7
// O(n)
void pqFree(PQueue q);