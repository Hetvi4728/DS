#include <iostream>
using namespace std;

int main() {
    int arr[100], n;
    int *ptr;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ptr = arr + n - 1;

    cout << "Array in reverse order: ";

    for (int i = 0; i < n; i++) {
        cout << *ptr << " ";
        ptr--;
    }

    return 0;
}
