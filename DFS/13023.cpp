#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;//ÀÔ·Â°ª
int check[2001] = { 0 };
int res = 0;
int checkNum = 0;
vector<vector<int>> v(2001);

void DFS(int now)
{
	if (checkNum == 5) {
		res = 1;
		return;
	}

	if (check[now] == 0) {
		check[now] = 1;
		checkNum++;
		for (int i = 0; i < v[now].size(); i++)
		{
			if (check[v[now][i]] == 0) {
				DFS(v[now][i]);

			}
			if (checkNum == 5) {
				res = 1;
				return;
			}
		}
	}

	if (checkNum == 5) {
		res = 1;
		return;
	}
	else {
		check[now] = 0;
		checkNum--;
	}
}




int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);

	}

	for (int i = 0; i < N; i++)
	{
		if (res == 1)
			break;

		DFS(i);
	}
	printf("%d", res);

	return 0;

}