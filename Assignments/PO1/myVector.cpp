//Name - Gayal Hewakuruppu
//OOP program 1
//File - myVector.cpp

#include <iostream>
#include "myVector.h"

using namespace std;

myVector::myVector(int size){
  vSize = size;
  theVector = new int[vSize];
  //initialize all the values to 0
  for(int i=0;i<vSize;i++){
    theVector[i] = 0;
  }
  //Index =0 since array is empty
  index=0;
}

int myVector::size(){
  return vSize;
}

double myVector::percentFull(){
  return (index/vSize);
}

void myVector::push_back(int x){
  //If vector is full,the array size  will be increased
  if(index==vSize){
    //the original array points to the larger array
    theVector=increase_vec();
  }
  
  //Inserts the value at the next space
  theVector[index]=x;
  index++;
}

void myVector::pop_back(){
  //Sends error message if array is empty
  if(index==0){
    cout<<"ERROR:EMPTY LIST"<<endl;
  }

  else{
    //Changes last element to zero
    index--;
    theVector[index]=0;

    //Shrinks the array in half if it is only 40% full.
    if((percentFull())<0.4){
      //the original array points to the smaller array
      theVector=decrease_vec();
  }
  }

}

int* myVector::increase_vec(){
  int *big_vec; //Create new pointer
  vSize=vSize*1.5;
  big_vec=new int[vSize]; //Create larger array 

  //Fill new array with zeros
  for(int i=0;i<vSize;i++){
    big_vec[i]=0;
  }

  //Copy original array to larger array
  for(int i=0;i<index;i++){
    big_vec[i]=theVector[i];
  }
  //Return larger array
  return big_vec;
}

int* myVector::decrease_vec(){
  int *small_vec; //Create new pointer
  vSize=vSize/2;
  small_vec=new int[vSize]; //Create smaller array

  //Fill new array with zeros
  for(int i=0;i<vSize;i++){
    small_vec[i]=0;
  }
  //Copy original array to smaller array
  for(int i=0;i<index;i++){
    small_vec[index]=theVector[index];
  }
  //Return smaller array
  return small_vec;
}

void myVector::print(){
  for(int i=0;i<vSize;i++){
    cout<<theVector[i]<<" ";
  }
  cout<<endl;
}
