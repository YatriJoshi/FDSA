#include <iostream>
#include <vector>

using namespace std;

// Dutch National Flag Algorithm (1 Pass, O(1) Extra Space)
void sortColors(vector<int>& arr) {
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of paint buckets: ";
    cin >> n;

    vector<int> colors(n);
    cout << "Enter color codes (0, 1, or 2): ";
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    sortColors(colors);

    cout << "\nSorted Bucket Order: ";
    for (int color : colors) {
        cout << color << " ";
    }
    cout << endl;

    return 0;
}