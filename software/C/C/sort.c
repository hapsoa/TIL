#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 100000

void swap(int *a, int *b);
void shuffle(int arr[], int count);
void bubble_sort(int arr[], int count);
int  partition (int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);
void merge(int arr[], int l, int m, int r);
void merge_sort(int arr[], int low, int high);
void selection_sort(int arr[], int count);

struct timespec tstart={0,0}, tend={0,0};
int main()
{
    int input;
    int array[NUMBER];
    for(int i = 0 ; i < NUMBER ; i++)   array[i] = i;
    shuffle(array, NUMBER);
    do{
        printf("소트를 해 봅시다.\n");
        printf("1번:\t버블 소트\n");
        printf("2번:\t퀵 소트\n");
        printf("3번:\t머지 소트\n");
        printf("4번:\t선택 소트\n");
        printf("5번:\t셔플\n");
        printf("다른 문자를 입력하면 프로그램이 종료됩니다.\n");
        printf("숫자를 입력하세요: ");
        scanf("%d", &input);

        switch(input)
        {
            case 1:
                clock_gettime(CLOCK_MONOTONIC, &tstart);
                bubble_sort(array, NUMBER);
                clock_gettime(CLOCK_MONOTONIC, &tend);
                printf("bubble sort: %.5f seconds\n",
                       ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
                       ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));
                break;
            case 2:
                clock_gettime(CLOCK_MONOTONIC, &tstart);
                quick_sort(array, 0, NUMBER - 1);
                clock_gettime(CLOCK_MONOTONIC, &tend);
                printf("quick sort: %.5f seconds\n",
                       ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
                       ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));
                break;
            case 3:
                clock_gettime(CLOCK_MONOTONIC, &tstart);
                merge_sort(array, 0, NUMBER - 1);
                clock_gettime(CLOCK_MONOTONIC, &tend);
                printf("merge sort: %.5f seconds\n",
                       ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
                       ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));
                break;
            case 4:
                clock_gettime(CLOCK_MONOTONIC, &tstart);
                selection_sort(array, NUMBER);
                clock_gettime(CLOCK_MONOTONIC, &tend);
                printf("selection sort: %.5f seconds\n",
                       ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
                       ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));
                break;
            case 5:
                shuffle(array, NUMBER);
                break;
            default:
                break;
        }

    }while(input < 6 && input >= 0);
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubble_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;


    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
void selection_sort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}
void shuffle(int arr[], int n)
{
    srand(time(NULL));
    if (n > 1)
    {
        int i;
        for (i = 0; i < n - 1; i++)
        {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
        }
    }
}