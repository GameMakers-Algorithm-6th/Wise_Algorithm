#include<iostream>
#include<queue>

using namespace std;

int N, K; //입력값

int minTime = 100000; //결과값1 (동생 찾는 가장 빠른 시간)
int maxCase = 0; //결과값2 (가장 빠른 시간으로 동생을 찾는 방법의 수)
int nowTime = -1; //현재 노드의 시간( 가장 빠른시간과의 비교를위해 존재하는 변수 )
int visit[100002] = { 0 }; //탐색했던적이 있는지를 check하기 위한 배열
queue <pair <int, int>> q;


void bfs() //현재 방문한 노드에 걷는경우와 순간이동의 경우의 수를 큐에 넣어주기
{
	int now = q.front().first;
	nowTime = q.front().second;
	q.pop();
	visit[now] = 1;

	if (now == K && minTime >= nowTime)
	{
		maxCase++;
		minTime = nowTime;
	}

	if (now * 2 <= 100000 && visit[now * 2] == 0)
		q.push(make_pair(now * 2, nowTime + 1)); //순간이동( x*2 값 , 시간) 큐에 넣어주기

	if (now - 1 >= 0 && visit[now - 1] == 0)
		q.push(make_pair(now - 1, nowTime + 1));//걷기( x-1 값 , 시간) 큐에 넣어주기


	if (now + 1 <= 100000 && visit[now + 1] == 0)
		q.push(make_pair(now + 1, nowTime + 1));//걷기( x-1 값 , 시간) 큐에 넣어주기



}



int main()
{
	scanf("%d %d", &N, &K);

	q.push(make_pair(N, 0)); //시작 지점 넣어줌

	while (!q.empty())
	{
		if (N == K) //둘의 위치가 같을 경우
		{
			maxCase++;
			minTime = 0;
			break;
		}

		bfs();
		if (nowTime > minTime)
			break;
	}

	printf("%d\n%d", minTime, maxCase);

}