/**

+-------------------+
|    Binary Heap    |
+-------------------+

this file implement the common tree-base data structure `binary heap`.

binary heap must satisify two constraints:

- Shape property: a binary heap is a complete binary tree
- Heap property: the parent value must be larger or equal to its children if it is a max-heap
                  or less then or equal to its children if it is a min-heap

*/

#include<stdio.h>
#include "heap.h"

void swap(int*, int*);

void max_heapify(heap_ptr heap, int index){
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    int largest = index;
    if (left < heap->size && heap->element[left] > heap->element[largest]){
        largest = left;
    }

    if (right < heap->size && heap->element[right] > heap->element[largest]){
        largest = right;
    }

    if (largest != index){
        swap(&heap->element[index], &heap->element[largest]);
        max_heapify(heap, largest);
    }
}

Heap build_max_heap(int *arr, int size) {
    /* copy array into heap element */
    Heap heap;
    heap.size = size;
    for (int i = 0; i < size; i++) {
        heap.element[i] = arr[i];
    }

    for(int i = size / 2 - 1; i >= 0; i--){
        max_heapify(&heap, i);
    }

    return heap;
}

void heapify_up(heap_ptr heap, int index){
    int parent = (index - 1) / 2;

    if (parent >= 0 && heap->element[parent] < heap->element[index]){
        swap(&heap->element[index], &heap->element[parent]);
        heapify_up(heap, parent);
    }
}

void insert(heap_ptr heap, int val) {
    /* add the val to bottom the heap */
    heap->element[heap->size] = val;

    heapify_up(heap, heap->size);

    heap->size++;
}

int extract_max(heap_ptr heap){
    return heap->element[0];
}

int* heap_sort(int *arr, int size){
    Heap heap = build_max_heap(arr, size);

    for (int i = size - 1; i >= 0; i--){
        arr[i] = extract_max(&heap);
        swap(&heap.element[0], &heap.element[heap.size - 1]);
        heap.size--;
        max_heapify(&heap, 0);
    }

    return arr;
}

void print(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* x, int* y){
    int z = *x;
    *x = *y;
    *y = z;
}

int main(int argc, char const *argv[])
{
    int arr[] = {8, 7, 9, 3, 1, 2, 4, 10, 14, 16};
    int *ptr = heap_sort(arr, 10);
    print(ptr, 10);
    return 0;
}

