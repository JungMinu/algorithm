#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
const int maxn = 1e6 + 5;
int a[10];
char map[51][51];
char dat[4] = {'f','a','c','e'};
int did[4];
int main()
{

	int g, s;
	cin >> g >> s;
	for (int i = 0; i < g; i++)
		scanf("%s",map[i]);
		
	//for (int i = 0; i < g; i++)
	//cout << map[i]<<endl;
	int ans = 0;
	for (int i = 0; i < g - 1; i++){
		for (int x = 0; x < s - 1; x++){
			if (map[i][x] == 'f' || map[i][x] == 'a' || map[i][x] == 'c' || map[i][x] == 'e'){
			
				memset(did, 0, sizeof(did));
				for (int h = 0; h < 4; h++){
					if (dat[h] == map[i][x])did[h] = 1;
				}

				for (int h = 0; h < 4; h++){
					if (dat[h] == map[i][x + 1])did[h] = 1;
				}

				for (int h = 0; h < 4; h++){
					if (dat[h] == map[i + 1][x])did[h] = 1;
				}
				for (int h = 0; h < 4; h++){
					if (dat[h] == map[i + 1][x + 1])did[h] = 1;
				}

				int f = 0;
				for (int h = 0; h < 4; h++){
					if (did[h] == 0)f = 1;
				}
				if (f != 1)ans++;
			
			}

			//cout << map[i][x];
			//cout << endl;

		}
	}

	cout << ans;
		

	return 0;

}
