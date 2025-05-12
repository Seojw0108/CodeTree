#include <iostream>
#define swap(a, b) {int tmp=a; a=b; b=tmp;}
using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.

    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int key = arr[i];

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
   

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}

