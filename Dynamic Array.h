/*
* Author: Jay Campbell
* File : Dynamic Array.h
* Date : 12/22/2023
* Description:
*/

#ifndef DATA_STRUCTURES_AND_ALGORITHMS_DYNAMIC_ARRAY_H
#define DATA_STRUCTURES_AND_ALGORITHMS_DYNAMIC_ARRAY_H

class DynamicArray {
private:
    //Pointer to store array created using new keyword
    int* dynamicArray = nullptr;
    //Size of the array
    int arraySize;
    //Container size
    int arrayCapacity;

public:
    //O(n) where n is capacity
    DynamicArray(int capacity) {
        this->arrayCapacity = capacity;
        this->arraySize = 0;
        dynamicArray = new int[capacity];
    }


    //Constant time operation O(1)
    int get(int i) {
        return dynamicArray[i];
    }

    //Constant time operation O(1)
    void set(int i, int n) {
        dynamicArray[i] = n;
    }

    //O(n) - avg case / Ammortized O(1)
    void pushback(int n) {
        //Check if the array has a proper size to store the element
        if(arraySize == arrayCapacity) {
            //If not, resize the array
            resize();
        }

        //Insert element
        dynamicArray[arraySize] = n;
        arraySize++;
    }

    //O(1)
    int popback() {
        //decrement the size of the array
        arraySize--;

        //return the resulting array after the removal of last item.
        //Size-- means, if we have 3 elements in an array when "--"
        //happens, size becomes 2. We know array indexes start at 0
        //which mean we return the value at index 2
        return dynamicArray[arraySize];
    }

    /*
    Increase the array size by 2 of current capacity
    O(n)
    */
    void resize() {
        //Create a new Array of double the size
        int* temp = new int[arrayCapacity * 2];

        arrayCapacity = arrayCapacity * 2;

        //Copy element of old array in newly created array
        for(int i = 0; i < arraySize; i++){
            temp[i] = dynamicArray[i];
        }

        //Delete old array
        delete[] dynamicArray;

        //Assign newly created array to the original array
        dynamicArray = temp;
    }

    /*
    Returns the size of the Array
    i.e. Total elements stored currently
    O(1)
    */
    int getSize() {
        return arraySize;
    }

    /*
    Returns the size of the container
    O(1)
    */
    int getCapacity() {
        return arrayCapacity;
    }
};

#endif //DATA_STRUCTURES_AND_ALGORITHMS_DYNAMIC_ARRAY_H
