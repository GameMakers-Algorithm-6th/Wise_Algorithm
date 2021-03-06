#include<iostream>


using namespace std;

int N; //입력값
int arr[100001][2]; //입력 값

int res = 1; //결과값


void merge(int arr[][2], int first, int mid, int last) //끝나는 시간 오름차순 정렬
{
	int sorted[100001][2];
	int i, j, k;
	i = first;		// First arr idx
	j = mid + 1;	// Second arr idx
	k = 0;			// Sorted arr idx

	while (i <= mid && j <= last)
	{

		if (arr[i][1] <= arr[j][1])
		{
			if (arr[i][1] == arr[j][1])		//끝나는 시간이 같다면, 시작하는 시간이 더 작은 순으로 
				if (arr[i][0] <= arr[j][0])
				{
					sorted[k][1] = arr[i][1];
					sorted[k++][0] = arr[i++][0];
				}
				else
				{
					sorted[k][1] = arr[j][1];
					sorted[k++][0] = arr[j++][0];
				}
			else
			{
				sorted[k][1] = arr[i][1];
				sorted[k++][0] = arr[i++][0];
			}

		}
		else
		{
			sorted[k][1] = arr[j][1];
			sorted[k++][0] = arr[j++][0];

		}
	}

	if (i > mid)
		while (j <= last)
		{
			sorted[k][1] = arr[j][1];
			sorted[k++][0] = arr[j++][0];

		}
	else
		while (i <= mid)
		{
			sorted[k][1] = arr[i][1];
			sorted[k++][0] = arr[i++][0];

		}

	for (i = first, k = 0; i <= last; i++, k++)
	{

		arr[i][0] = sorted[k][0];
		arr[i][1] = sorted[k][1];

	}


}

void mergeSort(int arr[][2], int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergeSort(arr, first, mid);
		mergeSort(arr, mid + 1, last);
		merge(arr, first, mid, last);
	}
}



int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &arr[i][0], &arr[i][1]);


	mergeSort(arr, 0, N - 1);

	int checkPoint = arr[0][1];

	for (int i = 1; i < N; i++)
	{
		if (checkPoint <= arr[i][0])
		{
			res++;
			checkPoint = arr[i][1];
		}
	}




	printf("%d", res);


}