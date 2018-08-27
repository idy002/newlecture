#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 200010;

int n;
int color[N];
int edge[N][2];
int fa[N];
vector<int> g[N];
int dis[N];

void init( int n ) {
	for(int i = 1; i <= n; i++)
		g[i].clear();
	for( int i = 1; i <= n; i++ )
		fa[i] = i;
}
int find( int u ) {
	return u == fa[u] ? u : fa[u] = find(fa[u]);
}
void unon( int u, int v ) {
	fa[find(u)] = find(v);
}
void dfs( int u, int f ) {
	for( int t = 0; t < (int)g[u].size(); t++ ) {
		int v = g[u][t];
		if( v == f ) continue;
		dis[v] = dis[u] + 1;
		dfs( v, u );
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf( "%d", &n );
		for( int i = 1; i <= n; i++ )
			scanf( "%d", color + i );
		init(n);
		for( int i = 1; i <= n - 1; i++ ) {
			int u, v;
			scanf( "%d%d", &u, &v );
			edge[i][0] = u;
			edge[i][1] = v;
			if( color[u] == color[v] )
				unon( u, v );
		}
		for( int i = 1; i <= n - 1; i++ ) {
			int u = edge[i][0];
			int v = edge[i][1];
			u = find(u);
			v = find(v);
			if( u != v ) {
				g[u].push_back( v );
				g[v].push_back( u );
			}
		}
		memset( dis, 0, sizeof(dis) );
		dfs( find(1), 0 );
		int farest = find(1);
		for( int u = 1; u <= n; u++ )
			if( dis[find(u)] > dis[farest] )
				farest = find(u);
		memset( dis, 0, sizeof(dis) );
		dfs( farest, 0 );
		int maxdis = 0;
		for( int i = 1; i <= n; i++ )
			maxdis = max( maxdis, dis[find(i)] );
		printf( "%d\n", (maxdis+1)/2 );
	}
}
