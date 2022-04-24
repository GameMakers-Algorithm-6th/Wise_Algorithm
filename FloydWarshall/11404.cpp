#include<iostream>
#include<algorithm>
using namespace std;


int n, m;

int road[101][101] = { 0 };


void FloydWarshall() {
	for (int via = 1; via <= n; via++) {
		for (int from = 1; from <= n; from++) {
			for (int to = 1; to <= n; to++) {
				if (road[from][to] > road[from][via] + road[via][to])
					road[from][to] = road[from][via] + road[via][to];
			}
		}
	}
}


int main()
{
	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == j)
				road[i][j] = 0;
			else
			road[i][j] = 20000000;
		}
	}

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);

		if(road[a][b] > c)
		road[a][b] = c;
	}

	FloydWarshall();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (road[i][j] == 20000000)
				road[i][j] = 0;
			printf("%d ", road[i][j]);
		}
		printf("\n");
	}
}