#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;

int n;
vector<int> vc[N];
int bit[N], val[N];

void add( int pos, int delta ) {
	for( int i = pos; i <= n + 1; i += i & -i )
		bit[i] += delta;
}
int query( int rg ) {
	int rt = 0;
	for( int i = rg; i; i -= i & -i )
		rt += bit[i];
	return rt;
}
int query( int lf, int rg ) {
	return query(rg) - query(lf-1);
}
int dist( int i, int j ) {
	if( i <= j )
		return query(i,j);
	else
		return query(i,n) + query(1,j);
}
int main() {
	scanf("%d", &n );
	int vmax = 0;
	for( int i = 1; i <= n; i++ ) {
		scanf("%d", val + i );
		vc[val[i]].push_back(i);
		vmax = max( vmax, val[i] );
	}
	n++;
	for( int i = 1; i <= n - 1; i++ )
		add( i, +1 );
	long long ans = 0;
	int cur = n;
	for( int i = 1; i <= vmax; i++ ) {
		if( vc[i].empty() ) continue;
		int j = int(upper_bound( vc[i].begin(), vc[i].end(), cur ) - vc[i].begin());
		for( int k = j; k < (int)vc[i].size(); k++ ) {
			ans += dist(cur,vc[i][k]);
			add(vc[i][k],-1);
			cur = vc[i][k];
		}
		for( int k = 0; k < j; k++ ) {
			ans += dist(cur,vc[i][k]);
			add(vc[i][k],-1);
			cur = vc[i][k];
		}
	}
	printf( "%lld\n", ans );
}

