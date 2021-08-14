/*
Dynamic Array by Alon Ohana!
Dynamic Array has the benefits of array - continuity in the memory
Dynamic Array has the benefits of linked list - can be resized!
I did this implementation to learn a little bit more about the memory management in C.
My main language is Java which manages the memory for me, this time I had to do it on my own.
Simple generic dynamic array be me. It took me few hours to implement and test properly.
I tried to make everything as simply and understandable as possible.
*/

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

typedef struct
{
    unsigned int size;
    unsigned int capacity;
    void **list; //Double pointer because it represents Array
} DynamicArray;

typedef struct DynamicArray_iterator
{
    DynamicArray *list;
    unsigned int cur_idx;
} DynamicArray_iterator;

DynamicArray DynamicArray_init(unsigned int capacity);

void DynamicArray_add(DynamicArray *aList, void *element, unsigned int index);

void *DynamicArray_remove(DynamicArray *aList, unsigned int index);

void *DynamicArray_get(DynamicArray *aList, unsigned int index);

void *DynamicArray_set(DynamicArray *aList, unsigned int index, void *element);
/**generic iterators**/
void DynamicArray_iterate(DynamicArray *list, void (*visit)(void *element));

#define DynamicArray_createSpecificIterator(type)                                         \
    void DynamicArray_##type##_iterate(DynamicArray *list, void (*visit)(type * element)) \
    {                                                                               \
        for (unsigned int i = 0; i < list->size; i++)                               \
        {                                                                           \
            visit((type *)list->list[i]);                                           \
        }                                                                           \
    }


DynamicArray_iterator DynamicArray_iterator_new(DynamicArray *list);

void *DynamicArray_iterator_next(DynamicArray_iterator *it);

/***utils***/
//Those methods are used for right memory management of the dynamic array. Since it is my first project with C the implementation might not be good.
/*
* Resize makes the dynamic array bigger or smaller, according to a flag it gets in the implementation.
* When the flag==1 the dynamic array doubles its size.
* When the flag==0 the dynamic array shrinks its size.
*/
void resize(DynamicArray *aList, short flag);
/*
* A method to remove the list
*/
void freeArray(DynamicArray *aList);
#endif