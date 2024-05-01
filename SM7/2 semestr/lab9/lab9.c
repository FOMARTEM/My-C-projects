#include <stdio.h>
#include <stdlib.h>

#define n 10

void print_mass(int* arr) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void metod_vstavok(int* arr) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--){
            if (arr[j - 1] < arr[j])
                break;
            int tmp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = tmp;
        }
    }
}

void merge(int* arr, int begin, int end) {
    int i = begin;
    int mid = begin + (end - begin) / 2;
    int j = mid + 1;
    int k = 0;
    int t[n];

    while (i <= mid && j<=end) {
        if (arr[i] <= arr[j])
            t[k] = arr[i++];
        else 
            t[k] = arr[j++];
        k++;
    }

    while (i <= mid) {
        t[k++] = arr[i++];
    }
    
    while (j <= end) {
        t[k++] = arr[j++];
    }
    
    for (i = 0; i < k; i++) {
        arr[begin + i] = t[i];
    }
}

void metod_merge(int* arr, int left, int right) {
    //print_mass(arr);
    if (left >= right)
        return;
    if (right - left == 1) {
        if (arr[left] > arr[right]) {
            int tmp = arr[right];
            arr[right] = arr[left];
            arr[left] = tmp;
        }
        return;
    }
    metod_merge(arr, left, left + (right - left) / 2);
    //print_mass(arr);
    metod_merge(arr, left + (right - left) / 2 + 1, right);
    //print_mass(arr);
    merge(arr, left, right);
    //print_mass(arr);
}

void metod_fast(int* arr, int first, int last) {
    int i = first;
    int j = last;
    int x = arr[(first + last) / 2]; //средний элемент

    do {
        while (arr[i] < x)
            i++;

        while (arr[j] > x)
            j--;
        
        if (i <= j) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }

            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        metod_fast(arr, i, last);
    if (first < j)
        metod_fast(arr, first, j);
    
}

int main(void) {
    int arr[] = {6, 5, 3, 1, 8, 7, 2, 4, 9, 0};
    int choice = 0;

    printf("Исходный массив:\n");
    print_mass(arr);

    printf("1 - сортировка вставок\n");
    printf("2 - сортировка слиянием\n");
    printf("3 - быстрая сортировка\n");
    printf("введите число: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Вставки\n");
        metod_vstavok(arr);
        printf("Отсрортированный массив:\n");
        print_mass(arr);
        break;
    case 2:
        printf("Слияние\n");
        metod_merge(arr, 0, n - 1);
        printf("Отсрортированный массив:\n");
        print_mass(arr);
        break;
    case 3:
        printf("Быстрый\n");
        metod_fast(arr, 0, n - 1);
        printf("Отсрортированный массив:\n");
        print_mass(arr);
        break;
    default:
        printf("учись читать\n");
        break;
    }

    return 0;
}