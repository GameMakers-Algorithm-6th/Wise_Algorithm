#include<iostream>


using namespace std;

int N; //입력값
int middle_res = 1700; //중간 결과값
int res = -1; //최종 결과값

int main()
{
	scanf("%d", &N);


	for (int i = 0; i < (N / 3) + 1; i++)
	{
		int new_N = N, new_res = 0;

		new_N = new_N - (5 * i);
		new_res += i;

		if (new_N < 0)
			break;

		if (new_N == 0 && new_res < middle_res)
			middle_res = new_res;


		new_res += new_N / 3;
		new_N = new_N % 3;

		if (new_N == 0 && new_res < middle_res)
			middle_res = new_res;

	}

	if (middle_res < 1700)
		res = middle_res;

	printf("%d", res);


}