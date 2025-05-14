#include <iostream>
#include <vector>
using namespace std;

int longestBitonicSubsequence(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    vector<int> lis(n, 1), lds(n, 1);

    // Compute LIS for each index
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    // Compute LDS for each index (from right to left)
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j] && lds[i] < lds[j] + 1) {
                lds[i] = lds[j] + 1;
            }
        }
    }

    // Compute LBS by taking max(lis[i] + lds[i] - 1)
    int maxLBS = 0;
    for (int i = 0; i < n; i++) {
        maxLBS = max(maxLBS, lis[i] + lds[i] - 1);
    }

    return maxLBS;
}

int main() {
    vector<int> arr = {15, 7, 19, 1 ,12, 18};
    cout << "Length of Longest Bitonic Subsequence: " << longestBitonicSubsequence(arr) << endl;
    return 0;
}
