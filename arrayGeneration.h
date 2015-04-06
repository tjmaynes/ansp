// Author: TJ Maynes
// File: arrayGeneration.h

#ifndef ARRAYGENERATION_H
#define ARRAYGENERATION_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class arrayGeneration{
 public:
  int* generateIncreasingArray(const int& size);
  int* generateDecreasingArray(const int& size);
  int* generateRandomArray(const int& size);
  template<typename T> T* generateConstArray(T value, const int& size);
  template<typename T> void prettyPrint(T* items, const int& size);
};
#endif

/*
 * generates an array of increasing values of an input size 
 *
 * const int& items = size of the array
 *
 * Worst-Case Time Complexity: Θ(n)
 */
int* arrayGeneration::generateIncreasingArray(const int& size){
  int* increasingArray = new int[size];
  for (int i = 0; i < size; i++){
    increasingArray[i] = i;
  }
  return increasingArray;
}

/*
 * generates an array of decreasing values of an input size
 *
 * const int& items = size of the array
 *
 * Worst-Case Time Complexity: Θ(n)
 */
int* arrayGeneration::generateDecreasingArray(const int& size){
  int* decreasingArray = new int[size];
  for (int i = size-1; i >= 0; --i){
    decreasingArray[size - i -1] = i;
  }
  return decreasingArray;
}

/*
 * generates an array of random values of an input size
 *
 * const int& items = size of the array
 *
 * Worst-Case Time Complexity: Θ(n + n) = Θ(2n) = Θ(n)
 */
int* arrayGeneration::generateRandomArray(const int& size){
  // first, generate an increasing array (unique numbers ranging from 0 to 9).
  int* randomArray = generateIncreasingArray(size);
  int randomNumber;
  // second, randomly swap values (random number has range from 0 to 9)
  for (int i = 0; i < size; i++){
    randomNumber = (rand() % size);
    swap(randomArray[randomNumber], randomArray[i]);
  }
  return randomArray;
}

/*
 * generates an array of constant T values of an input size
 *
 * const int& items = size of the array
 *
 * Worst-Case Time Complexity: Θ(n)
 */
template<typename T>
T* arrayGeneration::generateConstArray(T value, const int& size){
  T* constantArray = new T[size];
  for (int i = 0; i < size; i++){
    constantArray[i] = value;
  }
  return constantArray;
}

/*
 * prettyPrint - used to print array this was used earlier in the project for testing 
 * if I had unique values or not in smaller sets such as 10 or 20 items in array.
 *
 * T* items = array of items to be sorted
 * const int& items = size of the array
 *
 * Worst-Case Time Complexity: Θ(n)
 */
template<typename T>
void arrayGeneration::prettyPrint(T* items, const int& size){
  for (int i = 0; i < size; i++){
    cout << items[i] << " ";
  }
  cout << " " << endl;
}
