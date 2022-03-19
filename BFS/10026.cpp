#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N;//입력값

int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };


void bfs(char copy_graph[][100], int x, int y, int seq)
{
	char color = copy_graph[x][y];

	queue<pair<int, int>> q;
	q.push({ x,y });
	copy_graph[x][y] = 'o';



	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_r = r + dir[i][0];
			int next_c = c + dir[i][1];


			if (color == 'B' || seq == 0)
			{
				if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < N && copy_graph[next_r][next_c] == color)
				{
					q.push({ next_r, next_c });
					copy_graph[next_r][next_c] = 'o';
				}
			}
			else
			{
				if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < N && (copy_graph[next_r][next_c] == 'R' || copy_graph[next_r][next_c] == 'G'))
				{
					q.push({ next_r, next_c });
					copy_graph[next_r][next_c] = 'o';
				}
			}

		}

	}



}


int main()
{
	cin >> N;

	char graph[100][100];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
		}
	}


	int color_count;
	for (int seq = 0; seq < 2; seq++) //seq:0 _ 일반인 , seq:1 _ 적록색약
	{
		char copy_graph[100][100];
		copy(&graph[0][0], &graph[0][0] + 10000, &copy_graph[0][0]);

		color_count = 0;


		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (copy_graph[i][j] != 'o') {
					bfs(copy_graph, i, j, seq);
					color_count++;
				}
			}
		}

		printf("%d ", color_count);
	}
	return 0;



}