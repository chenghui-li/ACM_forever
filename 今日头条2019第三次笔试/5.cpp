#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int fa[maxn];
int d[maxn];
int siz[maxn];
int get(int x)
{
    if(x == fa[x]) return x;
    int root = get(fa[x]);
    return fa[x] = root;
}
vector<int> g[maxn];
void merge1(int x, int y)
{
    int u = x, v = y;
    x = get(x), y = get(y);
    if(x == y)
    {
        return;
    }
    fa[x] = y;
	siz[y] += siz[x];
}
int ans = 0;
int vis[maxn];
int last[maxn];
void dfs(int u, int fa)
{
    if(last[u]) return;
    last[u] = 1;
    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if(v == fa) continue;
        vis[v] = 1;
        dfs(v, u);
    }
}
int main()
{
    int n, m;
	scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
		fa[i] = i;
		d[i] = 0;
		siz[i] = 1;
	}
    for(int i = 1; i <= m; i++)
    {
        int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
        merge1(u, v);
    }
    ans = 0;
    int flag = 0;
    for(int i = 1; i <= n; i++)
    {
        //printf("%d\n", siz[i]);
        if(siz[i] >= n){
        	vis[i] = 1;
        	flag = 1;
		}

    }
    if(flag)
    {
        dfs(get(fa[1]), -1);
    }
    for(int i = 1; i <= n; i++)
		if(vis[i])
			ans++;
    printf("%d\n", ans);
    return 0;
}
