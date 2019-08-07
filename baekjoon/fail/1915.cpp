#include <cstdio>
#include <queue>
using namespace std;

#define MAXN 1000

typedef pair<int, int> pii;

queue<pii> qu;
int n, m, map[MAXN][MAXN], ans;
#define chk(row, col) 0<=row&&row<n&&col<=0&&col<m

void search(pii f)
{
	int cur = map[f.first][f.second];
	if (!chk(f.first+cur, f.second+cur)) return;

	bool ret = true;
	for (int i=0; i<=cur; i++)
	{
		if (map[f.first+i][f.second+cur] == 0 || map[f.first+cur][f.second+i] == 0)
		{
			return ;
		}
	}
	map[f.first][f.second]++;
	qu.push(f);
	ans = max(ans, cur+1);
}


int main()
{
	scanf("%d %d\n", &n, &m);
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<=m; j++)
		{
			char input; scanf("%c", &input);
			if (input == '\n') break;
			map[i][j] = input-'0';
			if (input == '1') qu.push(make_pair(i, j));
		}
	}

	while (!qu.empty())
	{
		pii f = qu.front(); qu.pop();
		search(f);
	}
	printf("%d\n", ans*ans);
}