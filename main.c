#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void swap(int* a, int* b){
    int t=*a;
    *a=*b;
    *b=t;
}

typedef struct node{
    int array[MAX];
    int currsize;
}minheap;

void bubbleup(minheap* heap, int i){
    if(!i) return;
    int parent=(i-1)/2;
    if(heap->array[parent]>heap->array[i]){
        swap(&heap->array[i], &heap->array[parent]);
        bubbleup(heap, parent);
    }
}

void insert(minheap* heap, int val){
    if(heap->currsize== MAX) return;
    heap->array[heap->currsize]=val;
    bubbleup(heap, heap->currsize);
    heap->currsize++;
}

int delmax(minheap* heap){
    if(!heap->currsize) return -1;
    int leafstart=heap->currsize/2;
    int maxindex=leafstart;
    for(int i=leafstart; i<heap->currsize; i++)
    maxindex= heap->array[maxindex]<heap->array[i] ? i : maxindex;
    int temp=heap->array[maxindex];
    heap->currsize--;
    heap->array[maxindex]=heap->array[heap->currsize];
    return temp;
}

void sinkmax(minheap* heap, int i){
    int left=2*i+1;
    int right=2*i+2;
    int bigchild=i;
    if(left<heap->currsize && right<heap->currsize)
        bigchild = heap->array[left] > heap->array[right] ? left : right;
    else if(left<heap->currsize || right<heap->currsize)
        bigchild = left<heap->currsize ? left : right;

    if(heap->array[bigchild] > heap->array[i]){
        swap(&heap->array[i], &heap->array[bigchild]);
        sinkmax(heap, bigchild);
    }
}