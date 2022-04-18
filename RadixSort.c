#include <stdio.h>
#define MAX 10000
void radixSort(int *a, int n) 
{
	int result[MAX], maxValue = 0;
	int exp = 1;
	for (int i = 0; i < n; i++) 
    {
		if (a[i] > maxValue) maxValue = a[i];
	}
	while (maxValue / exp > 0) 
    { // 1의 자릿수 계산
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++) 
            bucket[a[i] / exp % 10]++; // 자릿수 배열 처리
		for (int i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1]; // 누적 계산 : 결과 배열을 만들기 위해서!	
		for(int i=n-1; i>=0;i--)
        { //같은 자릿수 끼리는 순서를 유지
			result[--bucket[a[i] / exp % 10]] = a[i];
		}
		for (int i = 0; i < n; i++) 
            a[i] = result[i]; // 기본 배열 갱신
		exp *= 10;
	}
}