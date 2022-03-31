#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int N;//입력값
int check[101] = { 0 };
int arr[101] = { 0 };


int res = 0;
vector<int> res_v;

bool Isfind = false;
int find_now = 0;

void DFS(int now)
{
    if (find_now == arr[now] && Isfind == false) //찾았다!
    {
        check[now] = 1;
        Isfind = true;
        res++;
        res_v.push_back(now);
    }
  
   
    else 
    {
        check[now] = 1;
        if (check[arr[now]] == 0) {
            DFS(arr[now]);

        if (Isfind == true)
        {
            check[now] = 1;
            res++;
            res_v.push_back(now);
        }
   
        }
        check[now] = 0;
    }
}




int main()
{
    scanf("%d", &N);

    for (int i = 1; i < N + 1; i++)
        scanf("%d", &arr[i]);


    for (int i = 1; i < N + 1; i++)
    {
        check[i] = 0;
        Isfind = false;
        find_now = i;
        DFS(i);
        check[i] = 1;
    }

    sort(res_v.begin(),res_v.end());
    printf("%d\n", res);

    for (int i = 0; i < res_v.size(); i++)
        printf("%d\n", res_v[i]);

    return 0;

}