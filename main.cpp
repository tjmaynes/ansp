// Author: TJ Maynes
// File: main.cpp
#include "sorting.h"
#include <iomanip>
#include <time.h>

// instantiate classes
sorting s;
arrayGeneration ag;

/*
* This function prints the Averages from the tests after running through all the tests.
*
* float* increasing = array of increasing array averages.
* float* decreasing = array of decreasing array averages.
* float* random = array of random array averages.
* float* constant = array of constant array averages.
* const int& size = constant size of each array being passed in (size = 10)
* string set = string that contains tha name of 
*
* Worst-Case Time Complexity: Θ(n + n + n + n) = Θ(n)
*/
void printAverages(float* increasing, float* decreasing, float* random, float* constant, const int& size, string set){
	cout << "\n" << set << " averages." << endl;
	// start max_size back at 10000
	int max_size = 10000;

	cout << "\nIncreasing Array" << endl;
	for (int i = 0; i < size; i++){
		cout << "Instance Size (" << max_size << "): " << setw(4) << increasing[i] << " ms." << endl;
		max_size += 10000;
	}

	// start max_size back at 10000
	max_size = 10000;

	cout << "\nDecreasing Array" << endl;
	for (int i = 0; i < size; i++){
		cout << "Instance Size (" << max_size << "): " << setw(4) << decreasing[i] << " ms." << endl;
		max_size += 10000;
	}

	// start max_size back at 10000
	max_size = 10000;

	cout << "\nRandom Array" << endl;
	for (int i = 0; i < size; i++){
		cout << "Instance Size (" << max_size << "): " << setw(4) << random[i] << " ms." << endl;
		max_size += 10000;
	}

	// start max_size back at 10000
	max_size = 10000;

	cout << "\nConstant Array" << endl;
	for (int i = 0; i < size; i++){
		cout << "Instance Size (" << max_size << "): " << setw(4) << constant[i] << " ms." << endl;
		max_size += 10000;
	}
}

/*
* This function prints the Averages from the tests after running through all the tests.
*
* int max_size = maximum size that we want to test each sorting algorithm to
* int min_size = minimum size that we want to test each sorting algorithm to
* string theSort = string that contains tha name of the sorting algorithm we are testing.
*
* Worst-Case Time Complexity: Θ(n^2 + n^2 + n^2 + n^2) = Θ(n^2)
*/

void testing(int min_size, int max_size, string theSort){
	// making sure I know what the size of each tests I'm doing
	const int& tests = 5;
	const int& test_size = 10;

	// making sure each size of the array is a set value
	const int& array_size = 10;

	// average cpu_time arrays for each data set
	float* increasing_array_averages = new float[array_size];
	float* decreasing_array_averages = new float[array_size];
	float* random_array_averages = new float[array_size];
	float* constant_array_averages = new float[array_size];

	cout << "\nIncreasing Array using " << theSort << endl;

	// run 10 size instances (10000, 20000, 30000, etc.)
	for (int i = 0; i < test_size; i++){
		cout << max_size << " instances." << endl;

		// instantiate average value and sum value to zero on every new test.
		float average = 0.0;
		float sum = 0.0;

		// create new cpu_times array on every new test.
		float* cpu_times = new float[5];

		// run five tests
		for (int j = min_size; j < tests; j++){
			// set time to 0 before running the cpu times
			float time = 0.0;

			// instantiate new array for increasing ordered array.
			int* increasingArray = ag.generateIncreasingArray(max_size);
			if (theSort == "insertionsort"){
				clock_t c_start = clock();
				s.insertionsort(increasingArray, max_size);
				clock_t c_end = clock();
				time = 1000 * (float(c_end) - float(c_start)) / CLOCKS_PER_SEC;
			}
			else if (theSort == "quicksort"){
				clock_t c_start = clock();
				s.quicksort(increasingArray, max_size);
				clock_t c_end = clock();
				time = 1000 * (float(c_end) - float(c_start)) / CLOCKS_PER_SEC;
			}
			else {
				clock_t c_start = clock();
				s.mergesort(increasingArray, max_size);
				clock_t c_end = clock();
				time = 1000 * (float(c_end) - float(c_start)) / CLOCKS_PER_SEC;
			}
			//cout << "CPU Time (IncreasingArray): " << fixed << setprecision(3) << time << " ms." << endl;
			cout << fixed << setprecision(3) << time << " ms" << endl;

			// add cpu time to cpu_times array
			cpu_times[j] = time;

			// delete array at the end of each run to avoid memory leaks and faulty data
			delete[] increasingArray;
		}
		// add up the cpu_times values
		for (int j = 0; j < 5; j++){
			sum += cpu_times[j];
		}
		// find average value
		average = sum / 5.0;
		//cout << "Average time (" << max_size << " instances): " << average << "ms.\n" << endl;
		cout << fixed << setprecision(3) << average << " ms\n" << endl;

		// add average value to increasing_array_averages array per number of runs
		increasing_array_averages[i] = average;

		// once we pass our last instance (100000) break.
		if (max_size == 100000){
			break;
		}

		// go to the next instance (10000 to 20000)
		max_size += 10000;

		// delete cpu_times array to avoid memory leaks or faulty data
		delete[] cpu_times;
	}

	// start max_size back at 10000
	max_size = 10000;

	cout << "\nDecreasing Array using " << theSort << endl;

	// run 10 size instances (10000, 20000, 30000, etc.)
	for (int i = min_size; i < test_size; i++){
		cout << max_size << " instances." << endl;
		// instantiate average value and sum value to zero on every new test.
		float average = 0.0;
		float sum = 0.0;

		// create new cpu_times array on every new test.
		float* cpu_times = new float[5];

		// run five tests
		for (int j = min_size; j < tests; j++){
			// set time to 0 before running the cpu times
			float time = 0.0;

			// instantiate new decreasing order array every run.
			int* decreasingArray = ag.generateDecreasingArray(max_size);

			if (theSort == "insertionsort"){
				clock_t c_start = clock();
				s.insertionsort(decreasingArray, max_size);
				clock_t c_end = clock();
				time = 1000 * (float(c_end) - float(c_start)) / CLOCKS_PER_SEC;
			}
			else if (theSort == "quicksort"){
				clock_t c_start = clock();
				s.quicksort(decreasingArray, max_size);
				clock_t c_end = clock();
				time = 1000 * (float(c_end) - float(c_start)) / CLOCKS_PER_SEC;
			}
			else {
				clock_t c_start = clock();
				s.mergesort(decreasingArray, max_size);
				clock_t c_end = clock();
				time = 1000 * (float(c_end) - float(c_start)) / CLOCKS_PER_SEC;
			}

			//cout << "CPU Time (DecreasingArray): " << fixed << setprecision(3) << time << " ms." << endl;
			cout << fixed << setprecision(3) << time << " ms" << endl;

			// add cpu time to cpu_times array
			cpu_times[j] = time;

			// delete array at the end of each run to avoid memory leaks and faulty data
			delete[] decreasingArray;
		}
		// add up the cpu_times values
		for (int j = 0; j < 5; j++){
			sum += cpu_times[j];
		}
		// find average value
		average = sum / 5.0;
		//cout << "Average time (" << max_size << " instances): " << fixed << setprecision(3) << average << "ms.\n" << endl;
		cout << fixed << setprecision(3) << average << " ms\n" << endl;
		// add average value to decreasing_array_averages array per number of runs
		decreasing_array_averages[i] = average;

		// once we pass our last instance (100000) break.
		if (max_size == 100000){
			break;
		}

		// go to the next instance (10000 to 20000)
		max_size += 10000;

		// delete cpu_times array to avoid memory leaks or faulty data
		delete[] cpu_times;
	}

	// start max_size back at 10000
	max_size = 10000;

	cout << "\nRandom Array using " << theSort << endl;

	// run 10 size instances (10000, 20000, 30000, etc.)
	for (int i = min_size; i < test_size; i++){
		cout << max_size << " instances." << endl;
		// instantiate average value and sum value to zero on every new test.
		float average = 0.0;
		float sum = 0.0;

		// create new cpu_times array on every new test.
		float* cpu_times = new float[5];

		// run five tests
		for (int j = min_size; j < tests; j++){
			// set time to 0 before running the cpu times
			float time = 0.0;

			// instantiate new random order array every run.
			int* randomArray = ag.generateRandomArray(max_size);

			if (theSort == "insertionsort"){
				clock_t c_start = clock();
				s.insertionsort(randomArray, max_size);
				clock_t c_end = clock();
				time = 1000 * (float(c_end) - float(c_start)) / CLOCKS_PER_SEC;
			}
			else if (theSort == "quicksort"){
				clock_t c_start = clock();
				s.quicksort(randomArray, max_size);
				clock_t c_end = clock();
				time = 1000 * (float(c_end) - float(c_start)) / CLOCKS_PER_SEC;
			}
			else {
				clock_t c_start = clock();
				s.mergesort(randomArray, max_size);
				clock_t c_end = clock();
				time = 1000 * (float(c_end) - float(c_start)) / CLOCKS_PER_SEC;
			}

			//cout << "CPU Time (RandomArray): " << fixed << setprecision(3) << time << " ms." << endl;
			cout << fixed << setprecision(3) << time << " ms" << endl;

			// add cpu time to cpu_times array
			cpu_times[j] = time;

			// delete array at the end of each run to avoid memory leaks and faulty data
			delete[] randomArray;
		}
		// add up the cpu_times values
		for (int j = 0; j < 5; j++){
			sum += cpu_times[j];
		}
		// find average value
		average = sum / 5.0;
		//cout << "Average time (" << max_size << " instances): " << fixed << setprecision(3) << average << "ms.\n" << endl;
		cout << fixed << setprecision(3) << average << " ms\n" << endl;

		// add average value to random_array_averages array per number of runs
		random_array_averages[i] = average;

		// once we pass our last instance (100000) break.
		if (max_size == 100000){
			break;
		}

		// go to the next instance (10000 to 20000)
		max_size += 10000;

		// delete cpu_times array to avoid memory leaks or faulty data
		delete[] cpu_times;
	}

	// start max_size back at 10000
	max_size = 10000;

	cout << "\nConstant Array using " << theSort << endl;

	// run 10 size instances (10000, 20000, 30000, etc.)
	for (int i = 0; i < test_size; i++){
		cout << max_size << " instances." << endl;

		// instantiate average value and sum value to zero on every new test.
		float average = 0.0;
		float sum = 0.0;

		// create new cpu_times array on every new test.
		float* cpu_times = new float[5];

		// run five tests
		for (int j = 0; j < 5; j++){
			// set time to 0 before running the cpu times
			float time = 0.0;

			if (theSort == "insertionsort"){
				clock_t c_start = clock();
				s.insertionsort(ag.generateConstArray("Awesome", max_size), max_size);
				clock_t c_end = clock();
				time = 1000 * (float(c_end) - float(c_start)) / CLOCKS_PER_SEC;
			}
			else if (theSort == "quicksort"){
				clock_t c_start = clock();
				s.quicksort(ag.generateConstArray("Awesome", max_size), max_size);
				clock_t c_end = clock();
				time = 1000 * (float(c_end) - float(c_start)) / CLOCKS_PER_SEC;
			}
			else {
				clock_t c_start = clock();
				s.mergesort(ag.generateConstArray("Awesome", max_size), max_size);
				clock_t c_end = clock();
				time = 1000 * (float(c_end) - float(c_start)) / CLOCKS_PER_SEC;
			}

			//cout << "CPU Time (ConstantArray): " << fixed << setprecision(3) << time << " ms." << endl;
			cout << fixed << setprecision(3) << time << " ms" << endl;
			
			// add cpu time to cpu_times array
			cpu_times[j] = time;

			// delete array at the end of each run to avoid memory leaks and faulty data
			delete[] ag.generateConstArray("Awesome", max_size);
		}
		// add up the cpu_times values
		for (int j = 0; j < 5; j++){
			sum += cpu_times[j];
		}
		// find average value
		average = sum / 5.0;
		//cout << "Average time (" << max_size << " instances): " << fixed << setprecision(3) << average << " ms.\n" << endl;
        	cout << fixed << setprecision(3) << average << " ms\n" << endl;
		// add average value to constant_array_averages array per number of runs
		constant_array_averages[i] = average;

		// once we pass our last instance (100000) break.
		if (max_size == 100000){
			break;
		}

		// go to the next instance (10000 to 20000)
		max_size += 10000;

		// delete cpu_times array to avoid memory leaks or faulty data
		delete[] cpu_times;
	}

	// print averages of each array generated.
	printAverages(increasing_array_averages, decreasing_array_averages, random_array_averages, constant_array_averages, array_size, theSort);

	// delete each array we used to hold specific (generated arrays) of averages from each test.
	delete[] constant_array_averages;
	delete[] random_array_averages;
	delete[] decreasing_array_averages;
	delete[] increasing_array_averages;
}

/*
* This function prints the Averages from the tests after running through all the tests.
*
* Worst-Case Time Complexity: Θ(n)
*/

int main(){
	// seed time.
	srand(time(NULL));

	// starting size of 10000 instances
	const int& start_size = 10000;

	// set minimum size
	const int& min_size = 0;

	// set string array of sorting algorithms to perform
	string* tests = new string[3];
	tests[0] = "insertionsort";
	tests[1] = "quicksort";
	tests[2] = "mergesort";

	// run each one of the sorting algorithms
	for (int i = 0; i < 3; i++) {
	  if(tests[i] == "quicksort"){
	    // performing last element pivot first then set value to isRandomPivot to
	    // true and run quicksort again.
	     cout << "Now running isRandomPivot is false" << endl;
	     isRandomPivot = false;
	     testing(min_size, start_size, tests[i]);
	     cout << "Now running random value pivot" << endl;
	     isRandomPivot = true;
	  }
	     testing(min_size, start_size, tests[i]);
	}

	// run program again?
	for (int i = 0; i < 5; i++){
		string answer;
		cout << "\nWould you like to run the program again? (yes or no)" << endl;
		cin >> answer;
		if (answer == "y" || answer == "Y" || answer == "YES" || answer == "yes"){
			cout << " " << endl;
			main();
		}
		break;
	}

	return 0;
}
