#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;

int n, k;
vector<int> vc[N];

int main() {
	scanf("%d%d",&n,&k);
	if( k == 2 ) {
		printf( "%d\n", n - 1 );
		/*
		for( int i = 1; i < n; i++ )
			printf( "%d %d\n", i, i + 1 );
			*/
	} else {
		for( int i = 2; i <= n; i++ ) {
			vc[ (i - 1) % k + 1 ].push_back( i );
		}
		vector<int> sz;
		for( int i = 1; i <= k; i++ )
			sz.push_back((int)vc[i].size() + 1);
		sort(sz.begin(),sz.end());
		int ans = sz[k-1] + sz[k-2] - 2;
		printf( "%d\n", ans );
		/*
		for( int i = 1; i <= k; i++ ) {
			printf( "%d %d\n", 1, vc[i][0] );
			for( int t = 1; t < (int)vc[i].size(); t++ )
				printf( "%d %d\n", vc[i][t-1], vc[i][t] );
		}
		*/
	}
}
