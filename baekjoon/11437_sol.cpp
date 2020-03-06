#include <iostream>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define MAXN 50'000

int n, m;
vector<int> linked[MAXN+1];
int parent[MAXN+1][20] = { 0 };
int depth[MAXN+1] = { 0 };
bool check[MAXN+1] = { false };

void input()
{
    cin >> n;
    for (int i=1, a, b; i<n; i++)
    {
        cin >> a >> b;
        linked[a].push_back(b);
        linked[b].push_back(a);
	}

	parent[1][0] = 1;
	depth[1] = 1;

	queue<int> qu;
	qu.push(1);
	while (!qu.empty())
	{
		int idx = qu.front();
		qu.pop();
		int next_num;

        for (auto& nxt : linked[idx])
        {
            if (!parent[nxt][0])
            {
                parent[nxt][0] = idx;
                depth[nxt] = depth[idx] +1;
                qu.push(nxt);
            }
        }
	}
}

// 부모의 부모의 부모의 부모의 부모의~~ DP 에 저장
void fill_parent()
{
	for (int j = 1; j < 20; j++)
		for (int i = 1; i <= n; i++)
			parent[i][j] = parent[ parent[i][j - 1] ][j - 1];
}


int LCA(int x, int y)
{
	if (x == y) return x;
	if (depth[x] < depth[y]) swap(x, y);
	for (int j = 19; j >= 0; j--)
	{
		if (depth[x] == depth[y]) break;
		if (depth[x] - depth[y] >= (1 << j))
		{
			x = parent[x][j];
		}
	}

	if (x == y) return x;
	else
	{
		int d = depth[x] - 1;
		for (int j =19; j >=0; j--)
		{
			if (parent[x][j] != parent[y][j])
			{
				x= parent[x][j];
				y = parent[y][j];
			}
		}
	}

	return parent[x][0];
}




int LCA2(int u, int v)
{
	if (depth[u] < depth[v])
		swap(u, v);
	while (depth[u] != depth[v])
	{
		u = parent[u][0];//레벨이 같아질 때 까지 부모노드를 넣어준다
	}
	while (u != v)//두 정점이 같아질 때까지 부모노드를 넣어준다
	{
		u = parent[u][0];
		v = parent[v][0];
	}
	return u;
}


int main()
{
	input();
	fill_parent();
	/*for (int j = 0; j < 3; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << parent[i][j] << " ";
		}
		cout << endl;
	}*/





	//	cout << endl;
		/*cout << "depth!" << endl;

		for (int i = 1; i <= n; i++)
		{
			cout << i << " ";
		}
		cout << endl;
		for (int i = 1; i <= n; i++)
		{
			cout << depth[i] << " ";
		}
		cout << endl;*/



	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", LCA(a, b));;
	}

	return 0;
}