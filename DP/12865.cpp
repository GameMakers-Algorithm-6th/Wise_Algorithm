#include<iostream>
#include<algorithm>
using namespace std;


int N, K;

int input[200][2] = {0};

int res[200][200000] = { 0 };

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 1; i < N+1; i++)
		scanf("%d %d", &input[i][0], &input[i][1]);

	
	for (int i = 1; i <= N; i++)
	{
		int weight = input[i][0];
		int value = input[i][1];

		for (int j = 0; j <=K ; j++)
		{
			if (j < input[i][0]) //현재 물건의 무게가 더 무거울경우
				res[i][j] = res[i - 1][j];
			else
				res[i][j] = max(res[i - 1][j], res[i - 1][j - weight] + value);
		}
			
	}

	printf("%d", res[N][K]);

	return 0;
}