#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10
#define INCREMENT_SIZE 5

typedef struct {
    int key;
} element;

typedef struct {
    element *heap;
    int capacity;
    int heap_size;
} HeapType;

HeapType* create() {
    HeapType *h = (HeapType *)malloc(sizeof(HeapType));
    h->heap = (element *)malloc(sizeof(element)*INITIAL_SIZE);
    h->capacity = INITIAL_SIZE;
    h->heap_size = 0;
    return h;
}

void resize(HeapType *h) {
    h->capacity += INCREMENT_SIZE;
    h->heap = (element *)realloc(h->heap, sizeof(element) * h->capacity);
}

void insert_min_heap(HeapType *h, element item) {
    if (h->heap_size + 1 == h->capacity) {
        resize(h);
    }
    int i = ++(h->heap_size);
    while((i != 1) && (item.key < h->heap[i/2].key)) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_min_heap(HeapType *h) {
    int parent, child;
    element item, temp;
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].key > h->heap[child+1].key))
            child++;
        if (temp.key <= h->heap[child].key) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void heap_sort(element a[], int n) {
    HeapType *h = create();
    for (int i = 0; i < n; i++) {
        insert_min_heap(h, a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        a[i] = delete_min_heap(h);
    }
    free(h->heap);
    free(h);
}


int main() {
    element list[8] = {{9}, {11}, {23}, {27}, {34}, {56}, {56}, {99}};
    int n = 8;
    
    heap_sort(list, n);
    for (int i = 0; i < n; i++) {
      if(i == n - 1) {
         printf("%d", list[i].key);
      } else {
         printf("%d ", list[i].key);
      }
    }
    return 0;
}
