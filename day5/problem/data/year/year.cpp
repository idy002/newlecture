#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
const int oo = 0x3f3f3f3f;

struct Info {
	int tr[5][5];
	//	0	1	2	3	4 
	//	$	2	20	201	2017
	void init( int cur ) {
		memset( tr, 0x3f, sizeof(tr) );
		//	3 4 5 8 9
		if( cur == 3 || cur == 4 || cur == 5 || cur == 8 || cur == 9 ) {
			for( int i = 0; i <= 4; i++ )
				tr[i][i] = 0;
		}
		//	2 0 1 6 7
		if( cur == 2 ) {
			tr[0][0] = 1;
			tr[0][1] = 0;
			tr[1][1] = tr[2][2] = tr[3][3] = tr[4][4] = 0;
		}
		if( cur == 0 ) {
			tr[1][1] = 1;
			tr[1][2] = 0;
			tr[0][0] = tr[2][2] = tr[3][3] = tr[4][4] = 0;
		}
		if( cur == 1 ) {
			tr[2][2] = 1;
			tr[2][3] = 0;
			tr[0][0] = tr[1][1] = tr[3][3] = tr[4][4] = 0;
		}
		if( cur == 7 ) {
			tr[3][3] = 1;
			tr[3][4] = 0;
			tr[0][0] = tr[1][1] = tr[2][2] = tr[4][4] = 0;
		}
		if( cur == 6 ) {
			tr[3][3] = 1;
			tr[4][4] = 1;
			tr[0][0] = tr[1][1] = tr[2][2] = 0;
		}
	}
};
Info operator+( const Info &r, const Info &s ) {
	Info rt;
	memset( &rt, 0x3f, sizeof(rt) );
	for( int i = 0; i <= 4; i++ )
		for( int j = 0; j <= 4; j++ ) {
			for( int k = i; k <= j; k++ ) {
				rt.tr[i][j] = min( rt.tr[i][j], r.tr[i][k] + s.tr[k][j] );
			}
		}
	return rt;
}
struct Node {
	Info info;
	Node *ls, *rs;
}pool[N*3], *tail = pool, *root;

int n, q;
int aa[N];
char ss[N];

Node *build( int lf, int rg ) {
	Node *nd = ++tail;
	if( lf == rg ) {
		nd->info.init( aa[lf] );
		return nd;
	} else {
		int mid = (lf + rg)>>1;
		nd->ls = build( lf, mid );
		nd->rs = build( mid + 1, rg );
		nd->info = nd->ls->info + nd->rs->info;
		return nd;
	}
}
Info query( Node *nd, int lf, int rg, int L, int R ) {
	if( L <= lf && rg <= R ) return nd->info;
	int mid = (lf + rg)>>1;
	if( R <= mid )
		return query( nd->ls, lf, mid, L, R );
	else if( L > mid )
		return query( nd->rs, mid+1, rg, L, R );
	else
		return query( nd->ls, lf, mid, L, R ) + query( nd->rs, mid+1, rg, L, R );
	
}
int query( int l, int r ) {
	Info info = query( root, 1, n, l, r );
	return info.tr[0][4] == oo ? -1 : info.tr[0][4];
}
int main() {
	scanf( "%s", ss + 1 );
	scanf( "%d", &q );
	n = strlen(ss+1);
	for( int i = 1; i <= n; i++ )
		aa[i] = ss[i] - '0';
	root = build( 1, n );
	while( q-- ) {
		int l, r;
		scanf( "%d%d", &l, &r );
		printf( "%d\n", query(l,r) );
	}
}
