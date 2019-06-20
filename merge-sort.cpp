#include <iostream>
#include <vector>
#include <string>
using namespace std;
static int inversions = 0;
void merge(int *numberArray, int start, int mid, int end) {
    int leftPointer = 0, rightPointer = 0;
    int leftArraySize = mid - start, rightArraySize = end - mid;
    int leftArray[leftArraySize], rightArray[rightArraySize];
    for (int i = 0; i < leftArraySize; i++) {
        *(leftArray + i) = *(numberArray + start + i);
    }
    for (int i = 0; i < rightArraySize; i++) {
        *(rightArray + i) = *(numberArray + mid + i);
    }
    while (leftPointer < leftArraySize && rightPointer < rightArraySize) {
        int leftElement = *(leftArray + leftPointer);
        int rightElement = *(rightArray + rightPointer);
        if (leftElement < rightElement) {
            *(numberArray + start + leftPointer + rightPointer) = leftElement;
            leftPointer++;
        } else {
            *(numberArray + start + leftPointer + rightPointer) = rightElement;
            rightPointer++;
            inversions++;
        }
    }
    while (leftPointer < leftArraySize) {
        *(numberArray + start + leftPointer + rightPointer) = *(leftArray + leftPointer);
        leftPointer++;
    }
    while (rightPointer < rightArraySize) {
        *(numberArray + start + leftPointer + rightPointer) = *(rightArray + rightPointer);
        rightPointer++;
    }
}

void mergeSort(int *numberArray, int start, int end) {
    if (end - start < 2) {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(numberArray, start, mid);
    mergeSort(numberArray, mid, end);
    merge(numberArray, start, mid, end);
}

int main() {
	// std::vector<int> numbers;
    // string temp;
    // cout << "Enter numbers: \n";
    // cin >> temp;
    // while (temp != "") {
    //     numbers.push_back(std::stoi(temp));
    //     cin >> temp;
    // }
    int numbers[] = {12, 10, 22};
	int n = sizeof(numbers) / sizeof(int);
    int sum = 32;
	mergeSort(&numbers[0], 0, n);
    int l = 0, r = n -1; 
	while (l <= r) {
	    if (numbers[l] + numbers[r] < sum) {
            l++;
        } else if (numbers[l] + numbers[r] > sum) {
            r--;
        } else {
            break;
        }
	}
    cout << "Elements: " << numbers[l] << " , " << numbers[r] << " "<< inversions <<endl;
	return 0;
}
