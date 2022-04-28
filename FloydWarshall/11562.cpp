#include<iostream>

using namespace std;

int n,m;//ÀÔ·Â°ª



int road[251][251] = {0};

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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	


	cin >> n >> m;

	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <=n; j++)
		{
			road[i][j] = 1000000000;

		}
	}


	int u, v, b;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> b;
		
		road[u][u] = 0;
		road[v][v] = 0;

		road[u][v] = 0;
		if (b == 0)
		{
			road[v][u] = 1;
		}
		else 
		{
			road[v][u] = 0;
		}
			
	}



	FloydWarshall();

	int k;
	cin >> k;
	int s, e;
	for (int i = 0; i < k; i++)
	{
		cin >> s >> e;
		cout << road[s][e]<<'\n';
	}
}