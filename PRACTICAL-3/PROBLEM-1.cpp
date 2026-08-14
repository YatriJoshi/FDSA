#include <iostream>
#include <vector>

using namespace std;

// Method 1: Bubble Sort (Repeatedly compares adjacent elements and swaps them)
void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped, array is already sorted
        if (!swapped) break; 
    }
    cout << "[Bubble Sort Output]: ";
    for (int mark : arr) cout << mark << " ";
    cout << endl;
}

// Method 2: Selection Sort (Finds lowest element and places it at the front)
void selectionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    cout << "[Selection Sort Output]: ";
    for (int mark : arr) cout << mark << " ";
    cout << endl;
}

// Method 3: Insertion Sort (Picks each element and inserts into sorted position)
void insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    cout << "[Insertion Sort Output]: ";
    for (int mark : arr) cout << mark << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of answer sheets: ";
    cin >> n;

    vector<int> marks(n);
    cout << "Enter marks: ";
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }

    cout << "\n--- SORTING RESULTS ---" << endl;
    bubbleSort(marks);
    selectionSort(marks);
    insertionSort(marks);

    return 0;
}
