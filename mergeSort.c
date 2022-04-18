#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
void merge(int a[], int start, int middle, int end);
void mergeSort(int a[], int start, int end);
int sorted[SIZE];

void merge(int a[], int start, int middle, int end)
{
    int i, j, k; // 각각 start, middle, middle + 1에 해당
    i = start;
    j = middle + 1;
    k = start;

    // 3가지의 경우 중에 교차되는 경우 먼저
    while( i <= middle && j <= end)
    {
        if( a[i] <= a[j] )
        {
            sorted[k] = a[i];
            i++;
        }
        else // 그 반대의 경우면
        {
            sorted[k] = a[j];
            j++;
        }
        k++; // 정렬배열의 다음 칸에 담아야한다.
    }

    // 교차되는 경우가 아니라 특정 하나가 먼저 채워진다면 ?
    if ( i > middle) // i가 먼저 채워졌기 때문에 middle보다 커진다.
    {  
        for(int t = j; t <= end; t++)
        {
            sorted[k] = a[t];
            k++;
        }
    }
    else // j가 먼저 채워졌기 때문에
    {
        for(int t = i; t <= middle; t++)
        {
            sorted[k] = a[t];
            k++;
        }
    }

    for(int t = start; t <= end; t++)
    {
        a[t] = sorted[t];
    }
}

void mergeSort(int a[], int start, int end) // mergeSort 구현
{
    if(start < end)
    {
        int middle;
        middle = (start + end) / 2;
        mergeSort(a, start, middle);
        mergeSort(a, middle + 1, end); // 계속 분할
        merge(a, start, middle, end);
    }
}

int main()
{
    // 크기가 10인 랜덤배열을 생성하겠다.
    int arr[10];
    int random = 0;

    for(int i = 0; i < 10; i ++)
    {
        random = rand() % 9;
        arr[i] = random;
    }
    return 0;
}

