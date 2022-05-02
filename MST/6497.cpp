#include<iostream>
#include<algorithm>
using namespace std;


int m, n;

pair<long, pair<int, int>> edge[200001];
int parents[200001];

long res=0;
int edgenum = 0;


int FindRoot(int x)
{
	if (x == parents[x])
		return x;
	return parents[x] = FindRoot(parents[x]);
}

void Merge(int x, int y)
{
	x = FindRoot(x);
	y = FindRoot(y);

	if (x == y)
		return;
	parents[x] = y;
}


int main()
{


	int x, y, z;


	while(1)
	{
		edgenum = 0;
		res = 0;


		cin >> m >> n;

		
		if (m == 0 && n == 0)
			break;


		for (int i = 0; i <= n; i++)
		{
			parents[i] = i;
			edge[i] = { 0,{0,0} };
		}



		for (int i = 0; i < n; i++) 
		{
			cin >> x >> y >> z;

			edge[i] = { z,{x,y} };
			res += z;

		}


		sort(edge, edge + n);


		for (int i = 0; i < n; i++)
		{
			if (FindRoot(edge[i].second.first) == FindRoot(edge[i].second.second))
				continue;

			Merge(edge[i].second.first, edge[i].second.second);
			res -= edge[i].first;

			edgenum++;
			if (edgenum == m - 1)
				break;
		}

		cout << res<<'\n';


	}

}