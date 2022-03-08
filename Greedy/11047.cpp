#include<iostream>


using namespace std;

int N, K; //입력값
int arr[10]; //동전의 종류 배열
int res =0; //결과값

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);


	
	for (int i = 0; i <N; i++) 
	{
	
		if (K == 0)
			break;

		else
		{
			
			if (arr[N - i-1] > K) //동전 가치가 남은 돈보다 클 경우 넘어감
				continue;
			else
			{
				res += K/arr[N - i-1]; //몫이 들어가게됨 (동전개수++)
				K = K % arr[N - i-1];
			}

		}
	}
	
	printf("%d", res);

}