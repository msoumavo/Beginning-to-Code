#include <iostream>
#define MAX_ARRLEN 100
#define INF 999999

void mergeSortUtil(int* arr, int start, int mid, int end) {
	int nLeft = (mid - start + 1);
	int nRight = (end - mid);
	int leftArr[MAX_ARRLEN/2];
	int rightArr[MAX_ARRLEN/2];
	int finalArr[MAX_ARRLEN];
	int i, j, k;
	for (i = 0; i < nLeft; ++i) {
		leftArr[i] = arr[start + i];
	}
	//this is sentinel code which prevents from writing extra loops
	//to fill in the remaining elements in the other sorted array
	//when the current array is traversed to its full length
	leftArr[i] = INF;
	for (i = 0; i < nRight; ++i) {
		rightArr[i] = arr[mid + i +1];
	}
	//this is sentinel code which prevents from writing extra loops
	//to fill in the remaining elements in the other sorted array
	//when the current array is traversed to its full length
	rightArr[i] = INF;

	i = 0, j = 0, k = start;
	while (k < end + 1) {
		if (leftArr[i] < rightArr[j]) {
			arr[k] = leftArr[i];
			k++;
			i++;
		}
		else {
			arr[k] = rightArr[j];
			k++;
			j++;
		}
	}
}

void mergeSort(int* arr, int start, int end) {
	if (start < end) {
		//to prevent overflow for high values of start and end
		int mid = start + (end - start) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		mergeSortUtil(arr, start, mid, end);
	}
}

void display(int* arr, int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << "\t";
	}
	std::cout << "\n";
}

int main() {

	int arr[MAX_ARRLEN];
	int n;
	std::cout << "Enter number of unsorted array elements\n";
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	display(arr, n);
	mergeSort(arr, 0, n-1);
	display(arr, n);
	std::cin.get();
}