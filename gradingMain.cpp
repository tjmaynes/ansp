#include "sorting.h"
#include "arrayGeneration.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// function prototypes
void testSortFunction(void (*f)(int*, const int&));
void smallTestSortFunction(void (*f)(int*, const int&));
void testSortFunctionWithString(void (*f)(string*, const int&));

template <class T> void outputArray(T*, const int&, ostream&);
template <class T> T* copyArray(T*, const int&);

int minValue = 1;
int maxValue = 1000;

int main() {
   // set up randomization
   srand(time(NULL));
   
   int size = 10;
   int* increasingArray = arrayGeneration::generateIncreasingArray(size);
   cout << "Increasing Array: ";
   outputArray(increasingArray, size, cout);
   cout << endl;
   if (!sorting::isSorted(sorting::increasingArray,size)) {
      cout << "ARRAY NOT SORTED!" << endl;
   }
   delete [] increasingArray;
  
   int* decreasingArray =  arrayGeneration::generateDecreasingArray(size);
   cout << "Decreasing Array: ";
   outputArray(decreasingArray, size, cout);
   cout << endl;
   if (sorting::isSorted(sorting::decreasingArray,size)) {
      cout << "ARRAY SORTED!" << endl;
   }
   delete [] decreasingArray;
   
   int* randomArray =  arrayGeneration::generateRandomArray(size);
   cout << "Random Array: ";
   outputArray(randomArray, size, cout);
   cout << endl;
   if (sorting::isSorted(randomArray,size)) {
      cout << "ARRAY SORTED!" << endl;
   }
   delete [] randomArray;
  
   int constIntValue = 1;
   int* constIntArray =  arrayGeneration::generateConstArray(constIntValue,size);
   cout << "Constant Integer Array: ";
   outputArray(constIntArray, size, cout);
   cout << endl;
   if (!sorting::isSorted(sorting::constIntArray,size)) {
      cout << "ARRAY NOT SORTED!" << endl;
   }
   delete [] constIntArray;
   
   string constStrValue = "abc";
   string* constStrArray =  arrayGeneration::generateConstArray(constStrValue,size);
   cout << "Constant String Array: ";
   outputArray(constStrArray, size, cout);
   cout << endl;
   if (!sorting::isSorted(sorting::constStrArray,size)) {
      cout << "ARRAY NOT SORTED!" << endl;
   }
   delete [] constStrArray;
   
   
   
   cout << "********************* Insertion Sort **************************" << 
endl;
   testSortFunction(sorting::insertionsort);
   smallTestSortFunction(sorting::insertionsort);
   testSortFunctionWithString(sorting::insertionsort);
   cout << "***************************************************************" << 
endl<<endl;
   
   cout << "********************* Quick Sort, pivot last element **********" << 
endl;
   isRandomPivot = false;
   testSortFunction(sorting::quicksort);
   smallTestSortFunction(sorting::quicksort);
   testSortFunctionWithString(sorting::quicksort);
   cout << "***************************************************************" << 
endl<<endl;

   cout << "********************* Quick Sort, pivot random element ********" << 
endl;
   isRandomPivot = true;
   testSortFunction(sorting::quicksort);
   smallTestSortFunction(sorting::quicksort);
   testSortFunctionWithString(sorting::quicksort);
   cout << "***************************************************************" << 
endl<<endl;
   
   cout << "********************* Merge Sort ******************************" << 
endl;
   testSortFunction(sorting::mergesort);
   smallTestSortFunction(sorting::mergesort);
   testSortFunctionWithString(sorting::quicksort);
   cout << "***************************************************************" << 
endl<<endl;
   
   return 0;
}

void smallTestSortFunction(void (*f)(int*, const int&)) {
   // testing variables
   int testSize = 10;

   // timing variables  
   clock_t start;
   clock_t finish;
   
   // increasing array tests
   // create the array
   int* increasing =  arrayGeneration::generateIncreasingArray(testSize);
   cout << "Increasing Array: ";
   outputArray(increasing,testSize,cout);
   cout << endl;
   // sort the array
   start=clock();
   f(increasing,testSize);
   finish=clock();
   // compute and output the time
   double sortTime = (finish-start)/((double)(CLOCKS_PER_SEC / 1000));
   cout << "Sorted (" << sortTime << "): ";
   outputArray(increasing,testSize,cout);
   cout << endl;
   if (!sorting::isSorted(increasing,testSize)) {
      cout << "NOT SORTED" << endl;
   }
   // delete the array
   delete [] increasing;
   cout << endl;
   
   
   // decreasing array tests
   // create the array
   int* decreasing =  arrayGeneration::generateDecreasingArray(testSize);
   cout << "Decreasing Array: ";
   outputArray(decreasing,testSize,cout);
   cout << endl;
   // sort the array
   start=clock();
   f(decreasing,testSize);
   finish=clock();
   // compute and output the time
   sortTime = (finish-start)/((double)(CLOCKS_PER_SEC / 1000));
   cout << "Sorted (" << sortTime << "): ";
   outputArray(decreasing,testSize,cout);
   cout << endl;
   if (!sorting::isSorted(decreasing,testSize)) {
      cout << "NOT SORTED" << endl;
   }
   // delete the array
   delete [] decreasing;
   cout << endl;
   
   // random array tests
   // create the array
   int* random =  arrayGeneration::generateRandomArray(testSize);
   cout << "Random Array: ";
   outputArray(random,testSize,cout);
   cout << endl;
   // sort the array
   start=clock();
   f(random,testSize);
   finish=clock();
   // compute and output the time
   sortTime = (finish-start)/((double)(CLOCKS_PER_SEC / 1000));
   cout << "Sorted (" << sortTime << "): ";
   outputArray(random,testSize,cout);
   cout << endl;
   if (!sorting::isSorted(random,testSize)) {
      cout << "NOT SORTED" << endl;
   }
   // delete the array
   delete [] random;
   cout << endl;
   
   // constant integer array tests
   // create the array
   int intConstantValue = 1;
   int* constantIntArray =  arrayGeneration::generateConstArray(intConstantValue, testSize);
   cout << "Constant Array: ";
   outputArray(constantIntArray,testSize,cout);
   cout << endl;
   // sort the array
   start=clock();
   f(constantIntArray,testSize);
   finish=clock();
   // compute and output the time
   sortTime = (finish-start)/((double)(CLOCKS_PER_SEC / 1000));
   cout << "Sorted (" << sortTime << "): ";
   outputArray(constantIntArray,testSize,cout);
   cout << endl;
   if (!sorting::isSorted(constantIntArray,testSize)) {
      cout << "NOT SORTED" << endl;
   }
   // delete the array
   delete [] constantIntArray;  
   cout << endl;
}

void testSortFunction(void (*f)(int*, const int&)) {
   // testing variables
   int testSize = 10000;

   // timing variables  
   clock_t start;
   clock_t finish;
   
   // increasing array tests
   // create the array
   int* increasing =  arrayGeneration::generateIncreasingArray(testSize);
   // sort the array
   start=clock();
   f(increasing,testSize);
   finish=clock();
   // compute and output the time
   double sortTime = (finish-start)/((double)(CLOCKS_PER_SEC / 1000));
   cout << "Increasing Array: " << sortTime << endl;
   if (!sorting::isSorted(increasing,testSize)) {
      cout << "NOT SORTED" << endl;
   }
   // delete the array
   delete [] increasing;
   
   
   // decreasing array tests
   // create the array
   int* decreasing =  arrayGeneration::generateDecreasingArray(testSize);
   // sort the array
   start=clock();
   f(decreasing,testSize);
   finish=clock();
   // compute and output the time
   sortTime = (finish-start)/((double)(CLOCKS_PER_SEC / 1000));
   cout << "Decreasing Array: " << sortTime << endl;
   if (!sorting::isSorted(decreasing,testSize)) {
      cout << "NOT SORTED" << endl;
   }
   // delete the array
   delete [] decreasing;
   
   // random array tests
   // create the array
   int* random =  arrayGeneration::generateRandomArray(testSize);
   // sort the array
   start=clock();
   f(random,testSize);
   finish=clock();
   // compute and output the time
   sortTime = (finish-start)/((double)(CLOCKS_PER_SEC / 1000));
   cout << "Random Array: " << sortTime << endl;
   if (!sorting::isSorted(random,testSize)) {
      cout << "NOT SORTED" << endl;
   }
   // delete the array
   delete [] random;
   
   // constant integer array tests
   // create the array
   int intConstantValue = 1;
   int* constantIntArray =  arrayGeneration::generateConstArray(intConstantValue, testSize);
   // sort the array
   start=clock();
   f(constantIntArray,testSize);
   finish=clock();
   // compute and output the time
   sortTime = (finish-start)/((double)(CLOCKS_PER_SEC / 1000));
   cout << "Constant Integer Array: " << sortTime << endl;
   if (!sorting::isSorted(constantIntArray,testSize)) {
      cout << "NOT SORTED" << endl;
   }
   // delete the array
   delete [] constantIntArray;  
}

void testSortFunctionWithString(void (*f)(string*, const int&)) {
   // testing variables
   int testSize = 10000;

   // timing variables  
   clock_t start;
   clock_t finish;
   
   // constant string array tests
   // create the array
   string strConstValue = "abc";
   string* constantStrArray =  arrayGeneration::generateConstArray(strConstValue, testSize);
   // sort the array
   start=clock();
   f(constantStrArray,testSize);
   finish=clock();
   // compute and output the time
   double sortTime = (finish-start)/((double)(CLOCKS_PER_SEC / 1000));
   cout << "Constant String Array: " << sortTime << endl;
   if (!sorting::isSorted(constantStrArray,testSize)) {
      cout << "NOT SORTED" << endl;
   }
   // delete the array
   delete [] constantStrArray;
  
}

/*****************************************************************************/
/***************** Array Utils ***********************************************/
/*****************************************************************************/

template <class T>
void outputArray(T* items, const int& size, const int& firstIndex, ostream& out) 
{
   out << "[";
   for (int i=0; i<size; ++i) {
      out << items[i+firstIndex];
      if (i+1<size) {
         out << ", ";
      }
   }
   out << "]";
}

template <class T>
void outputArray(T* items, const int& size, ostream& out) {
   outputArray(items,size,0,cout);
}

template <class T>
T* copyArray(T* items, const int& size) {
   T* result = new T[size];
   
   for (int i=0; i<size; ++i) {
      result[i] = items[i];
   }
   
   return result;
}
