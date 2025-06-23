#include <iostream>
const int MAX_SIZE = 100000;
const int MAX_DIGIT = 10;

using namespace std;

int getDigit(int number, int pos) {
    while (pos--) {
        number /= 10;
    }
    return number % 10;
}

int getMaxDigit(int arr[], int size) {
    int max_val = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int digits = 0;
    while (max_val > 0) {
        max_val /= 10;
        digits++;
    }
    return digits;
}

void radix_sort(int arr[], int size, int k) {
    int buckets[MAX_DIGIT][MAX_SIZE];
    int bucket_count[MAX_DIGIT];

    for (int pos = 0; pos < k; ++pos) {
        for (int i = 0; i < MAX_DIGIT; ++i) {
            bucket_count[i] = 0;
        }

        for (int i = 0; i < size; ++i) {
            int digit = getDigit(arr[i], pos);
            buckets[digit][bucket_count[digit]++] = arr[i];
        }

        int idx = 0;
        for (int i = 0; i < MAX_DIGIT; ++i) {
            for (int j = 0; j < bucket_count[i]; ++j) {
                arr[idx++] = buckets[i][j];
            }
        }
    }
}

int n;
int arr[MAX_SIZE];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_digits = getMaxDigit(arr, n);
    radix_sort(arr, n, max_digits);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}
