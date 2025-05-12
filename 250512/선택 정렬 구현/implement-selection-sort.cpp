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

    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int k = i + 1; k < n; k++) {
            if (arr[k] < arr[min])
                min = k;
        }
        swap(arr[i], arr[min]);
    }
   

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}

