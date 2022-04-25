#include<iostream>
#include<algorithm>
using namespace std;


int n, m;
bool road[26][26] = { 0 };


char before, after;
string tmp;

void FloydWarshall() {
	for (int via = 0; via < 26; via++) {

		for (int from = 0; from < 26; from++) {
			if (!road[from][via])
				continue;


			for (int to = 0; to < 26; to++) {
				if (!road[from][via])
					continue;


				if (road[from][via] && road[via][to])
					road[from][to] = 1;
				if (!road[from][via] && !road[via][to])
					road[from][to] = 0;
			}
		}
	}
}


int main()
{

	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> before >> tmp >> after;
		road[before -'a'][after -'a'] = 1;	
	}

	FloydWarshall();

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> before >> tmp >> after;
		if (road[before - 'a'][after - 'a'] == 1)
			printf("T\n");
		else
			printf("F\n");
	}

}