// Task: Implement the 'sortIntegers' function below

// =================== Libraries ==================
#include <stdio.h> // Include file for standart input/output

// =============== Helper Functions ===============

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) {
  //TODO: implement merge.
	int low[m - l +1];
	int high[r -m];
	int i = 0;
	int j = 0;
	for(int p = l; p <= m; p++, i++){
		low[i] = arr[p];
	}
	for(int q = m + 1; q <= r; q++, j++){
		high[j] = arr[q];
	}
	
	i = 0;
	j = 0;
	int k = l;

	while(i < (m - l + 1) && j < (r - m)){
		if (low[i] < high[j]){
			arr[k] = low[i];
			i ++;
		}
		else{
			arr[k] = high[j];
			j++;
		}
		k++;
	}
	while(i < (m - l + 1)){
		arr[k] = low[i];
		k ++;
		i ++;
	}
	while(j < (r - m)){
		arr[k] = high[j];
		j ++;
		k ++;
	}

}

// Provided below is a sort function. We have also
// provided a template for how to document functions
// to help organize your code.
// Name: sortIntegers
// Input(s):
//          (1) 'array' is a pointer to an integer address. 
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'size' tells us how big the array of data is we are sorting.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void mergeSort(int arr[], int l, int r){
	if(r > l){
		mergeSort(arr, l, (l + r) / 2);
		mergeSort(arr, (l + r) / 2 + 1, r);

		merge(arr, l, (l + r) / 2, r);
	}
}
void sortIntegers(int* array, unsigned int size){
    // TODO: Implement merge sort
	mergeSort(array, 0, size - 1);
}


// Input: A pointer to an array (i.e. the array itself points to the first index)
//        The size of the array (Because we do not know how big the array is automatically)
void printIntArray(int* array, unsigned int size){
  unsigned int i; // Note: 'unsigned int' is a datatype for storing positive integers.
  for(i = 0; i < size; i=i+1){
    printf("%d ",array[i]);
  }
  printf("\n");
}

int main(){
  
  // Some test data sets.
  int dataset1[] = {0,1,2,3,4,5,6,7,8,9,10};
  int dataset2[] = {10,9,8,7,6,5,4,3,2,1,0};
  int dataset3[] = {0,3,2,1,4,7,6,5,8,9,10};
  int dataset4[] = {2,1,1,1,1,1,1,1,1,1,1};
  int dataset5[] = {100,201,52,3223,24,55,623,75,8523,-9,150};
  int dataset6[] = {-1,1,2,-3,4,5,-6,7,8,-9,10};
  
  // Sort our integer array
  sortIntegers(dataset1, 11);
  sortIntegers(dataset2, 11);
  sortIntegers(dataset3, 11);
  sortIntegers(dataset4, 11);
  sortIntegers(dataset5, 11);
  sortIntegers(dataset6, 11);
  
  // Print out an array
  printIntArray(dataset1, 11);
  printIntArray(dataset2, 11);
  printIntArray(dataset3, 11);
  printIntArray(dataset4, 11);
  printIntArray(dataset5, 11);
  printIntArray(dataset6, 11);
  
  return 0;
}
