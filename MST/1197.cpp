#include<iostream>
#include<algorithm>
using namespace std;


int V, E;
pair<int, pair<int, int>> edge[100001];
int parents[10001];

int res;
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
	for (int i = 0; i < 10001; i++)
	{
		parents[i] = i;
	}


	cin >> V >> E;

	int a, b, c;

	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		edge[i] = { c,{a,b} };

	}

	sort(edge, edge + E);


	for (int i = 0; i < E; i++)
	{
		if (FindRoot(edge[i].second.first) == FindRoot(edge[i].second.second))
			continue;

		Merge(edge[i].second.first, edge[i].second.second);
		res += edge[i].first;

		edgenum++;
		if (edgenum == V - 1)
			break;
	}

	cout << res;

}