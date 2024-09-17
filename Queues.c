#include "lab8.h"

typedef struct node{
    void * data;
    int priority;
    struct node * next;
}Node;

struct Info{
    int errorcode;
    int size;
    struct node * front, * rear;
};

/*This function returns the error code of a queue that was passed*/
int pqGetErrorCode(PQueue q)
{
    return q.info->errorcode;
}

/*This function initializes a PQueue variable*/
PQueue pqInit()
{
    PQueue q;
    q.info=malloc(sizeof(Info));
    //if malloc works it will set things to NULL or zero
    if(q.info)
    {
        q.info->front=NULL;
        q.info->rear=NULL;
        q.info->errorcode=0;
        q.info->size=0;
        return q;
    }
    q.info=NULL;
    return q;
}

/*This fuction inserts data along with its priority and the errorcode 
of the Queue is returned*/
int pqInsert(void *data, int priority, PQueue q)
{
    Node * p=malloc(sizeof(Node));
    Info * temp=q.info;
    if(p)
    {
        p->data=data;
        p->priority=priority;
        p->next=NULL;
    }
    if(pqGetSize(q)==0)
    {
        q.info->front=p;
        q.info->rear=p;
        q.info->errorcode=0;
        q.info->size++;
        return q.info->errorcode;
    }
    if(pqGetSize(q)>0)
    {
        int i;
        for(i=1;i<(priority-1);i++)
        {
            temp->front=temp->front->next;
        }
        p->next=temp->front->next;
        temp->front->next=p;
        q.info->errorcode=0;
        return q.info->errorcode;
    }
    q.info->errorcode=1;
    return q.info->errorcode;

}

/*This function removes the node with the highest priority*/
void * pqRemoveMax(PQueue q)
{
    void * temp;
    Node * node;
    if(q.info->size==0)
    {
        q.info->errorcode=2;
        return NULL;
    }
    if(q.info->size==1)
    {
        temp=q.info->front->data;
        node=q.info->front;
        q.info->front=NULL;
        q.info->rear=NULL;
        free(node);
        q.info->size--;
        q.info->errorcode=0;
        return temp;
    }
    temp=q.info->front->data;
    node=q.info->front;
    q.info->front=q.info->front->next;
    free(node);
    q.info->errorcode=0;
    q.info->size--;
    return temp;

}

/*This function returns the object with the highest priority*/
void * pqPeek(PQueue q)
{
    //checks to see if the queue is empty
    if(pqGetSize(q)==0)
    {
        q.info->errorcode=2;
        return NULL;
    }
    return q.info->front->data;

}


/*This function returns the size of the Queue that was passed*/
int pqGetSize(PQueue q)
{
    return q.info->size;
}

/*This function frees the PQueue that was passed*/
void pqFree(PQueue q)
{
 while(q.info->size!=0)
    {
        Node *temp=q.info->front;
        q.info->front=q.info->front->next;
        q.info->size--;
        free(temp);
    }
    q.info->front=NULL;
    q.info->rear=NULL;
    q.info->errorcode=0;
    q.info->size=0;
    Info * qptr=q.info;
    q.info=NULL;
    free(qptr);
}