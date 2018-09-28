//Name - GAYAL HEWAKURUPPU
//OOP PROGRAM 2
//File - myVector.cpp

#include <iostream>
#include <string>
#include "myVector.h"

using namespace std;

/**
* Function constructor
*   Sets up the vector
* param - {int} size : initial size of vector
* return - void
*/
template <typename T>
myVector<T>::myVector(int size) {
	maxSize = size;
	minSize = size;
	// create the array of vSize
	vPtr = new T[maxSize];
	index = 0;
}

/**
* Function print
*   Prints the current values in the vector
* param - void
* return - void
*/
template <typename T>
void myVector<T>::print() {
	for (int i = 0; i<index; i++) {
		cout << vPtr[i] << " ";
	}
	cout << endl;
}

/**
* Function pushBack
*   Adds value to vector
* param - {int} item : integer value
* return - void
*/
template <typename T>
void myVector<T>::pushBack(T item) {
	if (index >= maxSize) {
		vPtr = resize(1.5);
	}
	vPtr[index++] = item;
}

/**
* Function overloaded pushBack
*   Adds an array to end of vector
* param - T[] : array , int size :size of array
* return - void
*/
template <typename T>
void myVector<T>::pushBack(T arr[], int SIZE) {
	T* newArr = new T[index + SIZE];

	for (int i = 0; i<index; i++) {
		newArr[i] = vPtr[i];
	}

	for (int j = index; j<(index + SIZE); j++) {
		newArr[j] = arr[j - index];
	}

	index = index + SIZE;
	vPtr = newArr;
}

/**
* Function popBack
*   Returns value from vector
* param - none
* @return - {int} : last item on vector
*/
template <typename T>
T myVector<T>::popBack() {

	index--;

	if (index < 0) {
		//dammit
	}

	if (percentFull() <= .4) {
		vPtr = resize(.5);
	}

	return vPtr[index];
}

/**
* Function resize
*   Resizes our vector based on passed in ratio
* @param {double} ratio : new array size
* @return {int*} : pointer to new array
*/
template <typename T>
T* myVector<T>::resize(double ratio) {
	// figure out what our new size is, bigger or smaller
	int newSize = maxSize * ratio;

	return _resize(newSize);
}

template <typename T>
T* myVector<T>::resize(int size) {

	return _resize(size);

}

template <typename T>
T* myVector<T>::_resize(int newSize) {
	// Lets keep our vector above some minimum size
	if (newSize < minSize) {
		newSize = minSize;
	}

	// allocate new bigger vector
	T* vBigger = new T[newSize];

	//copy everything over
	for (int i = 0; i<index; i++) {
		vBigger[i] = vPtr[i];
	}

	// update new max size
	maxSize = newSize;

	// delete old memory
	delete[] vPtr;

	//return ptr to new memory
	return vBigger;
}

/**
* Function percentFull
*   helper function to calculate how full vector is
* @param none
* @return {double} : how full vector is
*/
template <typename T>
double myVector<T>::percentFull() {
	return double(index) / double(maxSize);
}

/**
* Function size
*    Returns number of current items in vector
* @param none
* @return {int} : num items
*/
template <typename T>
int myVector<T>::size() {
	return index;
}

/**
* Function size
*    Returns number of current items in vector
* @param none
* @return {int} : num items
*/
template <typename T>
void myVector<T>::size(int newSize) {
	vPtr = _resize(newSize);
}

/**
* Function vSize
*    Returns actual size of allocated memory
* @param none
* @return {int} : mem size
*/
template <typename T>
int myVector<T>::vSize() {
	return maxSize;
}
