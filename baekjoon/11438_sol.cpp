#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int counter = 1;

pii node[100'001];

pii val[200'002];
pii BIT1[200'002];
pii BIT2[200'002];
vector<int> adj[100'001];

inline pii func(const pii& a, const pii& b)
{
	return a.first > b.first ? b : a;
}

void initBIT()
{
	int next, prev;
	memcpy(BIT1, val, sizeof(val));
	memcpy(BIT2, val, sizeof(val));
	for (int i = 1; i < counter; i++) {
		next = i + (i & -i);
		if(next<counter)
			BIT2[next] = func(BIT2[i], BIT2[next]);
	}
	for (int i = counter-1; i !=0; i--) {
		prev = i - (i & -i);
		BIT1[prev] = func(BIT1[i], BIT1[prev]);
	}
}

void dfs(int s, int dep)
{
	val[counter] = { dep,s };
	node[s].second = node[s].first = counter++;
	for (const auto& next : adj[s]) {
		if (node[next].first != 0) continue;
		dfs(next,dep+1);
		val[counter] = { dep,s };
		node[s].second = counter++;
	}
	
}

int query(int s, int e)
{
	pii ret = { 987654321,-1 };
	int cur, prev, next;
	cur = s;
	next = s + (s & -s);
	while (next <= e) {
		ret = func(ret, BIT1[cur]);
		cur = next;
		next += (next & -next);
	}
	ret = func(ret, val[cur]);
	cur = e;
	prev = e - (e & -e);
	while (s <= prev) {
		ret = func(ret, BIT2[cur]);
		cur = prev;
		prev -= (prev & -prev);
	}
	return ret.second;
}

int lca(int a, int b)
{
	if (node[a].first <= node[b].first 
		&& node[b].second <= node[a].second)
		return a;
	if (node[b].first <= node[a].first
		&& node[a].second <= node[b].second)
		return b;

	return query(std::min(node[a].second, node[b].second),
		std::max(node[a].first, node[b].first));
}
int main()
{
	int a, b;
	int N, M;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	initBIT();
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
	return 0;
}
