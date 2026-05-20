#include <iostream>
using namespace std;

void merge(int arr[], int kiri, int mid, int kanan) {
    int n1 = mid - kiri + 1;
    int n2 = kanan - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[kiri + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = kiri;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int kiri, int kanan) {
    if (kiri < kanan) {
        int mid = kiri + (kanan - kiri) / 2;

        mergeSort(arr, kiri, mid);
        mergeSort(arr, mid + 1, kanan);

        merge(arr, kiri, mid, kanan);
    }
}

void cetakData(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {50000, 35000, 75000, 45000, 60000, 30000, 55000};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Data sebelum diurutkan:\n";
    cetakData(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Data setelah diurutkan (Ascending):\n";
    cetakData(arr, n);

    return 0;
}