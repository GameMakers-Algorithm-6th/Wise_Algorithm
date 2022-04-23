#include<iostream>

using namespace std;

int N;//입력값
int res;//결과값
int arr[1001] = {0};


int main()
{
    arr[0] = 1;
    arr[1] = 1;

    scanf("%d", &N);

    for (int i = 2; i < N + 1; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    }

    res = arr[N];
    printf("%d", res);

   
    return 0;

}