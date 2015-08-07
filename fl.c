#include<stdio.h>
int a, b;
char arr[200][200];
int visit[200][200];

void input()
{
	int i, j;
	char c;
	scanf("%d %d", &a, &b);

	for (i = 1; i <= a; i++)
	{
		
		scanf("%c", &c);
		for (j = 1; j <= b; j++)
			scanf("%c", &arr[i][j]);
	}
}

void dfs(int n, int m)
{
	if (visit[n][m] == 1)
		return;

	visit[n][m] = 1;

	if (arr[n - 1][m] == 'W')
		dfs(n - 1, m);
	if (arr[n][m - 1] == 'W')
		dfs(n, m - 1);
	if (arr[n][m + 1] == 'W')
		dfs(n, m + 1);
	if (arr[n + 1][m] == 'W')
		dfs(n + 1, m);
	if (arr[n - 1][m - 1] == 'W')
		dfs(n - 1, m - 1);
	if (arr[n - 1][m + 1] == 'W')
		dfs(n - 1, m + 1);
	if (arr[n + 1][m - 1] == 'W')
		dfs(n + 1, m - 1);
	if (arr[n + 1][m + 1] == 'W')
		dfs(n + 1, m + 1);
}
void process()
{
	int i, j;
	int cnt = 0;
	for (i = 1; i <= a; i++)
	{
		for (j = 1; j <= b; j++)
		{
			if ((arr[i][j] == 'W') && (visit[i][j] == 0))
			{
				dfs(i, j);
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	input();
	process();
	return 0;
}
