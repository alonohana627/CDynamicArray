# Generic Dynamic Array in C

Simple implementation for ArrayList in Java or Vector in C++. This is a dynamic array - it can be resized as needed. I choose to implement this type of data structure in order to learn and understand how to manage memory in C and specifically using ``malloc`` and ``free`` in order to manage the memory.

I tried to make everything as clear and simple as possible. 

## How to use?
At first you need to create a dynamic array. The dynamic array is created by the the init command.
```c
DynamicArray DynamicArray_init(unsigned int capacity);
```
The method gets a number (which represents the wanted capacity of the array) and allocates properly.

This method gets only unsigned int so don't try to be smart and put -1. And if you put 0 it will simply allocate as if you input 1.

### add
```c
void DynamicArray_add(DynamicArray *aList, void *element, unsigned int index);
```
Can only used by referenced element.

### Remove
```c
void *DynamicArray_remove(DynamicArray *aList, unsigned int index);
```
Remove from certain index. If it is out of bound it prints error.

### Get
```c
void *DynamicArray_get(DynamicArray *aList, unsigned int index);
```
Gets an element from given index. Complexity: ``O(1)`` like in array.

### Remove
```c
void *DynamicArray_set(DynamicArray *aList, unsigned int index, void *element);
```
Removes an element from certain index. Complexity: ``O(n)`` (needs to allocate all of the elements to new array).
## Memory Management
The dynamic array shrinks and growth whenever needed. The dynamic array can be larger than it should be but only upto 2 times. If the dynamic array is twice as large in the memory - it shrinks with the method ``resize``.
## Iterators
The code includes generic (although not completely) iterators which you can use if you want to to create ``search`` methods and etc.

## TODO
Although I learned more than I thought I will learn there are many things I can implement to make this better:
* Create proper testings.
* Type safety instead of loosely void pointers.
* Improve iterators and make them simpler.
* Array to DynamicArray and DynamicArray to Array.