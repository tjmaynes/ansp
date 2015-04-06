// Author: TJ Maynes
// File: algorithm.h

#ifndef SORTING_H
#define SORTING_H

#include "arrayGeneration.h"
#include <queue>

bool isRandomPivot;

class sorting{
  public:
    template<typename T> void insertionsort(T* items, const int& size);
    template<typename T> void bubblesort(T* items, const int& size);
    template<typename T> void selectionsort(T* items, const int& size);
    template<typename T> void quicksort(T* items, const int& size);
    template<typename T> void quick_sort(T* items, int low, int high);
    template<typename T> int partition(T* items, int low, int high);
    template<typename T> void mergesort(T* items, const int& size);
    template<typename T> void merge_sort(T* items, int low, int high);
    template<typename T> void merge(T* items, int low, int middle, int high);
    template<typename T> void heapsort(T* items, const int& size);
    template<typename T> void buildHeap(T* items, const int& size);
    template<typename T> void heapify(T* items, int low, const int& size);
    template<typename T> bool isSorted(T* items, const int& size);
    template<typename T> void prettyPrint(T* items, const int& size);
};

/*
 * Sort the input T* items using the insertion sort algorithm
 *
 * T* items = array of items to be sorted
 * const int& items = size of the array
 *
 * Worst-Case Time Complexity: Θ(n^2)
 */
template<typename T>
void sorting::insertionsort(T* items, const int& size){
  //prettyPrint(items, size, "Before, insertion sort: ");

  // instantiate a counter
  int j;
  for (int i = 0; i < size; i++){
    // counter to equal i-th value
    j = i;

    // loop until j is less or equal to zero or j-th index of items is greater
    // than jth minus one index of items.
    while ((j > 0) && (items[j] < items[j - 1])){
      swap(items[j], items[j - 1]);
      j -= 1;
    }
  }
  isSorted(items, size);
  //prettyPrint(items, size, "After, insertion sort: ");
}

/*
 * Sort the input T* items using the bubblesort algorithm
 *
 * T* items = array of items to be sorted
 * const int& items = size of the array
 *
 * Worst-Case Time Complexity: Θ(n^2)
 */
template<typename T>
void sorting::bubblesort(T* items, const int& size){
  T temp;
  for(int i = 0; i <= size; i++){
    for(int j = 0; j < size; j++){
      if(items[j] > items[j+1]){
        temp = items[j];
        items[j] = items[j+1];
        items[j+1] = temp;
      }
    }
  }
  isSorted(items, size);
}

/*
 * Sort the input T* items using the selection sort algorithm
 *
 * T* items = array of items to be sorted
 * const int& items = size of the array
 *
 * Worst-Case Time Complexity: Θ(n^2)
 */
template<typename T>
void sorting::selectionsort(T* items, const int& size){
  int low;
  T temp;
  for(int i = 0; i < size - 1; i++){
    low = i;
    for(int j = i+1; j < size; j++){
      if(items[j] < items[low]){
        low = j;
      }
    }
    if(low != i){
      temp = items[i];
      items[i] = items[low];
      items[low] = temp;
    }
  }
  isSorted(items, size);
}

/*
 * Sort the T* input items using the quick sort algorithm
 *
 * T* items = array of items to be sorted
 * const int& items = size of the array
 *
 * Worst-Case Time Complexity: Θ(n^2)
 */
template<typename T>
void sorting::quicksort(T* items, const int& size){
  //prettyPrint(items, size, "Before, quick sort: ");

  // set low value to zero.
  int low = 0;

  // set high to size of array minus one.
  int high = size - 1;

  // start quicksorting algorithm
  quick_sort(items, low, high);

  //check for sortedness
  isSorted(items, size);
  //prettyPrint(items, size, "After, quick sort: ");
}

/*
 * Sort the T* input items using the quick sort algorithm
 *
 * T* items = array of items to be sorted
 * int low = the lowest index of the array to consider (inclusive)
 * int high = the highest index of the array to consider (exclusive)
 *
 * Worst-Case Time Complexity: Θ(n^2)
 */
template<typename T>
void sorting::quick_sort(T* items, int low, int high){
  if ((high - low) > 0) {
    // let p equal the partition function
    int p = partition(items, low, high);

    // recursive call on quick_sort for items from low to returned
    // value from partition minus 1.
    quick_sort(items, low, p - 1);

    // recursive call on quick_sort for items from returned
    // partition value (plus 1) to high value item.
    quick_sort(items, p + 1, high);
  }
}

/*
 * Partition the input items of array T 
 *
 * T* items = array of items to be sorted
 * int low = the lowest index of the array to consider (inclusive)
 * int high = the highest index of the array to consider (exclusive)
 *
 * Worst-Case Time Complexity: Θ(n)
 */
template<typename T>
int sorting::partition(T* items, int low, int high){
  // instantiate counter and pivot
  int i;
  int pivot;

  // chosen pivot
  if (isRandomPivot == true){
    pivot = (rand() % (high - low + 1));
  }
  else{
    pivot = high;
  }

  // instantiate firsthigh value to low value 
  int firsthigh = low;

  // loop from low to high
  for (i = low; i < high; i++) {

    // if the items are less than the pivot then swap that item with the 
    // firsthigh index and increment firsthigh.
    if (items[i] < items[pivot])
    {
      swap(items[i], items[firsthigh]);
      firsthigh++;
    }
  }

  // swap pivot with firsthigh value
  swap(items[pivot], items[firsthigh]);

  return firsthigh;
}

/*
 * Sort the T* input items using the mergesort algorithm
 *
 * T* items = array of items to be sorted
 * const int& items = size of the array
 *
 * Worst-Case Time Complexity: Θ(n lg n)
 */
template<typename T>
void sorting::mergesort(T* items, const int& size){
  //prettyPrint(items, size);
  isSorted(items, size);

  // set low value to zero.
  int low = 0;

  // set high to size of array minus one.
  int high = size - 1;

  // start mergesorting algorithm
  merge_sort(items, low, high);

  //check for sortedness
  isSorted(items, size);
  //prettyPrint(items, size);
}

/*
 * Mergesort the items between low (inclusive) and high (exclusive)
 *
 * T* items = array of items to be sorted
 * int low = the lowest index of the array to consider (inclusive)
 * int high = the highest index of the array to consider (exclusive)
 *
 * Worst-Case Time Complexity: Θ(n lg n)
 */
template<typename T>
void sorting::merge_sort(T* items, int low, int high){
  // we don't want to run out of the range of the array
  if (low < high){
    // find middle
    int middle = (high + low) / 2;

    // merge sort lower half
    merge_sort(items, low, middle);

    // merge sort upper half
    merge_sort(items, middle + 1, high);

    // merge elements together
    merge(items, low, middle, high);
  }
}

/*
 * Merge the sorted lower half of the array with the sorted upper half of the
 * array
 *
 * T* items = array of items to be sorted
 * int low = the lowest element of the array to consider (inclusive)
 * int middle = the middle element of the array (part of upper half)
 * int high = the largest element of the array to consider (exclusive)
 */
template<typename T>
void sorting::merge(T* items, int low, int middle, int high){
  // instantiate counter
  int i;

  // queues created to hold left and right values for sorting and merging
  queue <T> left, right;

  // push lower to middle items to left queue
  for (i = low; i <= middle; i++){
    left.push(items[i]);
  }
  // push middle to higher items to right queue
  for (i = middle + 1; i <= high; i++){
    right.push(items[i]);
  }

  i = low;

  // 
  while (!(left.empty() || right.empty())) { 
    if (left.front() <= right.front()) {
      // temp variable for the left front element
      T left_front = left.front();

      // add current left front value to items
      items[i++] = left_front;

      // pop left front element
      left.pop();
    }
    else {
      // temp variable for the right front element
      T right_front = right.front();

      // add current right front value to items
      items[i++] = right_front;

      // pop right front element
      right.pop();
    }
  }

  // if there are any leftovers from left queue we want to add them to items.
  // left queue will be empty after this.
  while (!left.empty()){
    T left_front = left.front();
    items[i++] = left_front;
    left.pop();
  }

  // if there are any leftovers from right queue we want to add them items.
  // right queue will be empty after this
  while (!right.empty()){
    T right_front = right.front();
    items[i++] = right_front;
    right.pop();
  }
}

/*
 * Sort the T* input items using the heapsort algorithm
 *
 * T* items = array of items to be sorted
 * const int& items = size of the array
 *
 * Worst-Case Time Complexity: Θ(n lg n)
 */
template<typename T>
void sorting::heapsort(T* items, const int& size){
  T temp;
  for(int i = size; i >= 2; i--){
    temp = items[i];
    items[i] = items[1];
    items[1] = temp;
    heapify(items, 1, i - 1);
  }
}

/*
 * buildHeap the items between low (inclusive) and high (exclusive)
 *
 * T* items = array of items to be sorted
 * int low = the lowest index of the array to consider (inclusive)
 * int high = the highest index of the array to consider (exclusive)
 *
 * Worst-Case Time Complexity: Θ(n lg n)
 */
template<typename T>
void sorting::buildHeap(T* items, const int& size){
  for(int i = size/2; i >= 1; i--){
    heapify(items, i, size);
  }
}

/*
 * heapify the items between low (inclusive) and high (exclusive)
 *
 * T* items = array of items to be sorted
 * int i = current index
 * const int& size - size of array
 *
 * Worst-Case Time Complexity: Θ(lg n)
 */
template<typename T>
void sorting::heapify(T* items, int i, const int& size){
  T temp = items[i];
  int j = 2*i;

  while(j <= size){
    if(j < size && items[j+1] > items[j])
      j += 1;
    if(temp > items[j])
      break;
    else if(temp <= items[j]){
      items[j/2] = items[j];
      j *= 2;
    }
  }
  items[j/2] = temp;
}


/*
 * isSorted - a boolean that checks whether the array of items is sorted or not.
 *
 * T* items = array of items to be sorted
 * const int& items = size of the array
 *
 * Worst-Case Time Complexity: Θ(n)
 */
template<typename T>
bool sorting::isSorted(T* items, const int& size) {
  for (int i = 1; i < size; i++){
    // if item from the item array being passed is less than the 
    // item before it, then items are not sorted (false).
    if (items[i] < items[i - 1]){
      // cout << "isSorted: false." << endl;
      return false;
    }
  }
  //cout << "isSorted: true." << endl;
  return true;
}

/*
 * prettyPrint - used to print array in sorting algorithm, this function was
 * used earlier in the project for smaller sets such as 10 or 20 items in array.
 *
 * T* items = array of items to be sorted
 * const int& items = size of the array
 *
 * Worst-Case Time Complexity: Θ(n)
 */
template<typename T>
void sorting::prettyPrint(T* items, const int& size){
  for (int i = 0; i < size; i++){
    cout << items[i] << " ";
  }
  cout << " " << endl;
}
#endif
