#include<iostream>
#include<queue>

using namespace std;

int N, K; //입력값
int visit[100002] = { 0 }; //탐색했던적이 있는지를 check하기 위한 배열
int res = 0; //결과값
bool isFind = 0; //동생 찾음
queue <int> q;


void bfs() //현재 방문한 노드에 걷는경우와 순간이동의 경우의 수를 큐에 넣어주기
{
	int now = q.front();
	q.pop();

	if (now * 2 != N && now * 2 <= 100000) {
		if (visit[now * 2] == 0) {
			q.push(now * 2); //순간이동한 경우 x*2
			visit[now * 2] = visit[now] + 1; //방문할예정(현재 방문한 노드 시간+1 대입)

			if (now * 2 == K)
			{
				isFind = 1;
				res = visit[now * 2];
			}
		}
	}


	if (now - 1 != N && now - 1 >= 0 && now - 1 <= 100000)
	{
		if (visit[now - 1] == 0) {
			q.push(now - 1);  //걷는거 x-1
			visit[now - 1] = visit[now] + 1;

			if (now - 1 == K)
			{
				isFind = 1;
				res = visit[now - 1];
			}
		}
	}


	if (now + 1 != N && now + 1 <= 100000)
	{
		if (visit[now + 1] == 0) {
			q.push(now + 1); //걷는거 x+1
			visit[now + 1] = visit[now] + 1;

			if (now + 1 == K)
			{
				isFind = 1;
				res = visit[now + 1];
			}

		}
	}



}



int main()
{
	scanf("%d %d", &N, &K);

	q.push(N); //시작 지점 넣어줌

	while (!q.empty())
	{
		bfs();
		if (isFind == 1)
			break;
	}

	printf("%d", res);

}