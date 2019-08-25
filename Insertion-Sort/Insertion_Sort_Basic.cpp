#include <iostream>
#define MAX 10

void print(int arr[MAX], int n) {

	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << "\n";
	}
}

void insertionSort(int arr[MAX], int n) {

	int key = -1,  i = -1;
	for (int j = 1; j < n; ++j) {
		key = arr[j];
		for (i = j - 1; i > -1 && arr[i] > key; --i) {
			arr[i + 1] = arr[i];
		}
		arr[i + 1] = key;
	}
	print(arr, n);
}

int main() {

	int arr[10];
	int n;
	std::cout << "Enter the number of unsorted array elements\n";
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	insertionSort (arr, n);
	std::cin.get();
}