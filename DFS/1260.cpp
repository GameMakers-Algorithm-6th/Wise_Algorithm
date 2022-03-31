#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N,M,V;//ÀÔ·Â°ª
int map[1001][1001] = {0};
int check_dfs[1001] = { 0 };
int check_bfs[1001] = { 0 };


void DFS(int now) 
{
	if (check_dfs[now] == 0) {
		check_dfs[now] = 1;
		printf("%d ", now);		
		for (int i = 1; i < N+1; i++)
		{	
			if (map[now][i] == 1 && check_dfs[i] == 0 )
				DFS(i);
		}
	}

}


void BFS(int now) 
{
	queue<int> q;
	q.push(now);

	while (!q.empty())
	{
		
		now = q.front();
		q.pop();
		check_bfs[now] = 1;
		printf("%d ", now);
		
		for (int i = 1; i < N+1; i++)
		{
			if (map[now][i] == 1 && check_bfs[i] == 0) {
				q.push(i);
				check_bfs[i] = 1;
			}
		}

	}
	

}


int main()
{
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		map[a][b] = 1;
		map[b][a] = 1;

	}

	DFS(V);
	printf("\n");
	BFS(V);

	return 0;

}