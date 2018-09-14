//Name - Gayal Hewakuruppu
//OOP program 1
//File - main.cpp

#include <iostream>
#include "myVector.h"

using namespace std;

int main() {
  
  //Create instance of myVector of size 10 
  myVector V(10);
  //immediately attempt to remove from empty vector.
  V.pop_back();
  //Insert 13,31,73 into the vector and print it.
  V.push_back(13);
  V.push_back(31);
  V.push_back(73);
  V.print();
  //Clearing the vector
  V.pop_back();
  V.pop_back();
  V.pop_back();
  //Insert 10000 items into vector & print the size
  for(int i=0;i<1000;i++){
    V.push_back(i%9);
  }
  cout<<V.size()<<endl;
  //Remove 998 items into vector & print the size
   for(int i=0;i<998;i++){
    V.pop_back();
  }
  cout<<V.size()<<endl;
  //Print out the vector
  V.print();

  return 0;
}
