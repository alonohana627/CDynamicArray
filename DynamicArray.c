#include "DynamicArray.h"
#include <stdlib.h>
#include <stdio.h>

DynamicArray DynamicArray_init(unsigned int capacity)
{   
    if (capacity <= 0){
        capacity = 1;
    }
    DynamicArray init;
    init.list = malloc(capacity * sizeof(void *));
    init.capacity = init.list ? capacity : 1;
    init.size = 0;

    return init;
}

void DynamicArray_add(DynamicArray *aList, void *element, unsigned int index)
{
    if (index > aList->size)
    {
        printf("boundry error - CANNOT ADD OUT OF RANGE");
        return;
    }

    if (aList->size == aList->capacity)
    {
        resize(aList, 1);
    }
    for (unsigned int i = aList->size; i > index; i--)
    {
        aList->list[i] = aList->list[i - 1];
    }
    aList->list[index] = element;
    aList->size++;
}

void *DynamicArray_remove(DynamicArray *aList, unsigned int index)
{
    if (index >= aList->size){
        printf("\n\nboundry error - CANNOT REMOVE OUT OF RANGE\n\n");
        return NULL;
    }

    void *temp = aList->list[index];
    for (unsigned int i = index + 1; i < aList->size; i++)
    {
        aList->list[i - 1] = aList->list[i];
    }
    aList->list[aList->size - 1] = NULL;
    aList->size--;
    if (aList->capacity / 2 > aList->size)
    {
        resize(aList, 0);
    }
}

void *DynamicArray_get(DynamicArray *aList, unsigned int index)
{
    if (index >= aList->size){
        printf("\n\nboundry error - CANNOT GET OUT OF RANGE\n\n");
        return NULL;
    }
    return aList->list[index];
}

void *DynamicArray_set(DynamicArray *aList, unsigned int index, void *element)
{
     if (index >= aList->size){
        printf("\n\nboundry error - CANNOT SET OUT OF RANGE\n\n");
        return NULL;
    }
    aList->list[index] = element;
}
////////////////////////////////
void DynamicArray_iterate(DynamicArray *list, void (*visit)(void *element))
{
    for (unsigned int i = 0; i < list->size; i++)
    {
        visit(list->list[i]);
    }
}

DynamicArray_iterator DynamicArray_iterator_new(DynamicArray *list)
{
    DynamicArray_iterator temp;
    temp.list = list;
    temp.cur_idx = 0;
    return temp;
}

void *DynamicArray_iterator_next(DynamicArray_iterator *it)
{
    return it->cur_idx < it->list->size ? it->list->list[it->cur_idx++] : NULL;
}
////////////////////////////////
void resize(DynamicArray *aList, short flag)
{
    if (flag == 1)
    {
        //new alloc
        void **newList = malloc(aList->capacity * 2 * sizeof(void *));
        //copy elements
        for (unsigned int i = 0; i < aList->size; i++)
        {
            newList[i] = aList->list[i];
        }
        free(aList->list);
        aList->list = newList;
        aList->capacity <<= 1;
    }
    if (flag == 0)
    {
        void **newList = malloc((aList->capacity / 2) * sizeof(void *));
        for (unsigned int i = 0; i < aList->size; i++)
        {
            newList[i] = aList->list[i];
        }
        free(aList->list);
        aList->list = newList;
        aList->capacity >>= 1;
    }
}

void freeArray(DynamicArray *aList)
{
    free(aList->list);
    aList->size = 0;
    aList->capacity = 0;
    aList->list = malloc(0);
}

/*End. Basic testings*/
void printArray(DynamicArray *arr)
{
    printf("[");
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d, ", *((int *)arr->list[i]));
    }
    printf("] ArrayList size in the memory: %d bytes\n",arr->capacity);
}

int main(int argc, char const *argv[])
{
    printf("Initilize Array List\n\n");
    DynamicArray arr = DynamicArray_init(1);
    int w = 9;
    int x = 10;
    int y = 11;
    int z = 13;
    DynamicArray_add(&arr, &x, 0);
    DynamicArray_add(&arr, &y, 0);
    DynamicArray_add(&arr, &z, 0);
    DynamicArray_add(&arr, &w, 0);
    DynamicArray_add(&arr, &x, 0);
    printf("The list after adding 4 elements (one of them twice!)\n");
    printArray(&arr);
    printf("\nLet's remove the first index\n");
    DynamicArray_remove(&arr, 0);
    printArray(&arr);
    printf("\nLet's remove the last index\n");
    DynamicArray_remove(&arr, 3);
    printArray(&arr);
    printf("\nIf we try to remove out of bound element the array won't resized\n");
    DynamicArray_remove(&arr, 3);
    void *cur = NULL;

    printArray(&arr);
    printf("\nThe memory allocation is actually dynamic and if we add a lot of elements the arraylist will grow up\n");
    DynamicArray_add(&arr, &x, 0);
    DynamicArray_add(&arr, &y, 0);
    DynamicArray_add(&arr, &z, 0);
    DynamicArray_add(&arr, &w, 0);
    DynamicArray_add(&arr, &x, 0);
    DynamicArray_add(&arr, &x, 0);
    DynamicArray_add(&arr, &y, 0);
    DynamicArray_add(&arr, &z, 0);
    DynamicArray_add(&arr, &w, 0);
    DynamicArray_add(&arr, &x, 0);
    printArray(&arr);

    printf("\nAnd if we remove elements the arraylist will shrink\n");
    DynamicArray_remove(&arr, 0);
    DynamicArray_remove(&arr, 0);
    DynamicArray_remove(&arr, 0);
    DynamicArray_remove(&arr, 0);
    DynamicArray_remove(&arr, 0);
    DynamicArray_remove(&arr, 0);
    DynamicArray_remove(&arr, 0);
    DynamicArray_remove(&arr, 0);
    DynamicArray_remove(&arr, 0);
    DynamicArray_remove(&arr, 0);
    printArray(&arr);
    printf("\nThis is why it called \"Dynamic Array\". It's in the name! Now lets delete it with freeArray: \n");
    freeArray(&arr);
    printArray(&arr);
    return 0;
}