//Name - GAYAL HEWAKURUPPU
//OOP PROGRAM 2
//File - myVector.h
//https://github.com/gayalhk/2143-OOP-Hewakuruppu/tree/master/Assignments/PO2

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class myVector {
private:
	T *vPtr;      // int pointer to array
	int maxSize;    // max size of array
	int minSize;    // min size of array
	int index;      // current location to insert or remove
	T* _resize(int);

public:
	myVector(int size);
	void pushBack(T item);
	void pushBack(T[], int size);
	T popBack();
	double percentFull();
	T* resize(double);
	T* resize(int);

	void print();
	int size();
	void size(int);
	int vSize();

	//Overloaded << operator
	//Prints the vector in a single line
	friend ostream& operator<<(ostream &cout, myVector<T> V) {
		for (int i = 0; i<V.size(); i++) {
			cout << V[i] << "  ";
		}
		cout << endl;
		return cout;
	}

	// Implementation of [] operator.  This function must return a 
	// refernce as array element can be put on left side 
	int& operator[](int i)
	{
		if (i >= maxSize)
		{
			cout << "Array index out of bound, exiting\n";
			exit(0);
		}
		else if (i >= index) {
			cout << "Warning: vector[" << i << "] is undefined ...\n";
		}
		return vPtr[i];
	}

	//Overloaded + operator
	//Adds the values of two vector Returns the result
	myVector<T> operator+(myVector<T> V) {
		myVector<T> V2(index);

		for (int i = 0; i<V.size(); i++) {
			V2[i] = vPtr[i] + V[i];
		}
		for (int j = V.size(); j<index; j++) {
			V2[j] = vPtr[j];
		}

		return V2;
	}

	//Overloaded - operator
	//Subtracts the values in two vectors.Returns the result
	myVector<T> operator-(myVector<T> V) {
		myVector<T> V2(index);

		for (int i = 0; i<V.size(); i++) {
			V2[i] = vPtr[i] - V[i];
		}
		for (int j = V.size(); j<index; j++) {
			V2[j] = vPtr[j];
		}

		return V2;
	}

	//Overloaded * operator
	//Multiplies the values in two vectors.Returns the result
	myVector<T> operator*(myVector<T> V) {
		myVector<T> V2(index);

		for (int i = 0; i<V.size(); i++) {
			V2[i] = vPtr[i] * V[i];
		}
		for (int j = V.size(); j<index; j++) {
			V2[j] = vPtr[j];
		}

		return V2;
	}

	//Overloaded / operator
	//Divides the values in two vectors.Returns the result
	myVector<T> operator/(myVector<T> V) {
		myVector<T> V2(index);

		for (int i = 0; i<V.size(); i++) {
			V2[i] = vPtr[i] / V[i];
		}
		for (int j = V.size(); j<index; j++) {
			V2[j] = vPtr[j];
		}

		return V2;
	}

	//Overloaded == operator
	//Checks and returns true if two vectors are equal
	bool operator==(myVector<T> V) {
		bool equal = true;
		for (int i = 0; i<index; i++) {
			if (vPtr[i] == V[i]) {
				continue;
			}
			else {
				equal = false;
				break;
			}
		}
		return equal;
	}

	//Overloaded = operator
	//Makes one vector take the values of aother vector
	myVector<T> operator=(myVector<T> V) {
		myVector<T> V2(index);

		for (int i = 0; i<V.size(); i++) {
			V2[i] = V[i];
		}

		return V2;
	}

};
