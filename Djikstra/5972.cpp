#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m;//입력값

int res[50001] = {0};
vector<pair<int, int>> v[50001]; //{도착지,여물}


void Djikstra(int start)
{
	priority_queue <pair<int,int>> q; //{여물,출발지}

	res[start] = 0;
	q.push({ 0,start});

	while (!q.empty())
	{
		
		int time = -q.top().first;
		int cur = q.top().second;
		q.pop();

		if (time > res[cur])
			continue;

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next_time = v[cur][i].second;
			int next_cur = v[cur][i].first;

			if (next_time  + time < res[next_cur])
			{
				res[next_cur] = next_time + time;
				q.push({ -res[next_cur],next_cur});
			}
		}
	}
	
}


int main()
{


	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}


	for (int i = 0; i <= n; i++)
		res[i] = 50000000;

	Djikstra(1);

	printf("%d", res[n]);

	return 0;
}