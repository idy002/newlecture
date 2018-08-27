#include <bits/stdc++.h>
using namespace std;

struct Stat {
	int x, y, s, d;
	Stat(){}
	Stat( int x, int y, int s, int d ):x(x),y(y),s(s),d(d){}
};

const int N = 555;

int n;
int dep[N];
int dx[] = { -1, -1, -1, 1, 1, 1, 0, 0 };
int dy[] = { -1, 0, 1, -1, 0, 1, -1, 1 };
int nxt[][2] = {
	{ 1, 6 }, { 0, 2 }, { 1, 7 }, { 4, 6 }, 
	{ 3, 5 }, { 4, 7 }, { 0, 3 }, { 2, 5 },
};
bool toc[350][350];
bool vis[350][350][31][8];

int bfs() {
	queue<Stat> qu;
	for( int i = 0; i < dep[1]; i++ ) 
		toc[175][175 + i] = true;
	qu.push( Stat(175,175 + dep[1] - 1, 2,7) );
	vis[175][175][1][7] = true;
	while( !qu.empty() ) {
		Stat s = qu.front();
		qu.pop();
		if( s.s == n + 1 ) continue;
		for( int k = 0; k < 2; k++ ) {
			int d = nxt[s.d][k];
			for( int l = 1; l <= dep[s.s]; l++ ) {
				int xx = s.x + dx[d] * l;
				int yy = s.y + dy[d] * l;
				toc[xx][yy] = true;
			}
			int xdst = s.x + dx[d] * (dep[s.s] );
			int ydst = s.y + dy[d] * (dep[s.s] );
			if( !vis[xdst][ydst][s.s+1][d] ) {
				vis[xdst][ydst][s.s+1][d] = true;
				qu.push( Stat(xdst,ydst,s.s+1,d) );
			}
		}
	}
	int ans = 0;
	for( int i = 0; i < 350; i++ )
		for( int j = 0; j < 350; j++ ) {
			ans += toc[i][j];
			/*
			if( toc[i][j] ) {
				printf( "%d %d\n", i - 175, j - 175 );
			}
			*/
		}
	return ans;
}
int main() {
	scanf( "%d", &n );
	for( int i = 1; i <= n; i++ ) 
		scanf( "%d", dep + i );
	printf( "%d\n", bfs() );
}

