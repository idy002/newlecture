#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;

struct Info {
	int a[10][11][4];
};
struct Node {
	Info info;
	Node *ls, *rs;
	void update() {
		const Info &il = ls->info;
		const Info &ir = rs->info;
		for( int len = 1; len <= 10; len++ )
			for( int a = 0; a < len; a++ )
				for( int v = 0; v < 4; v++ )
					info.a[a][len][v] = il.a[a][len][v] + ir.a[a][len][v];
	}
}pool[N*2], *tail=pool, *root;

int n, q;
char ss[N];
int id[256];

void init() {
	id['A'] = 0;
	id['G'] = 1;
	id['C'] = 2;
	id['T'] = 3;
}
Node *build( int lf, int rg ) {
	Node *nd = ++tail;
	if( lf == rg ) {
		for( int len = 1; len <= 10; len++ )
			nd->info.a[lf % len][len][id[ss[lf]]]++;
	} else {
		int mid = (lf + rg) >> 1;
		nd->ls = build( lf, mid );
		nd->rs = build( mid + 1, rg );
		nd->update();
	}
	return nd;
}
void modify( Node *nd, int lf, int rg, int pos, int val ) {
	if( lf == rg ) {
		memset( nd->info.a, 0, sizeof(nd->info.a) );
		for( int len = 1; len <= 10; len++ )
			nd->info.a[lf % len][len][val]++;
		return;
	}
	int mid = (lf + rg) >> 1;
	if( pos <= mid )
		modify( nd->ls, lf, mid, pos, val );
	else
		modify( nd->rs, mid+1, rg, pos, val );
	nd->update();
}
int query( Node *nd, int lf, int rg, int L, int R, int a, int m, int v ) {
	if( L <= lf && rg <= R ) {
		return nd->info.a[a][m][v];
	}
	int mid = (lf + rg) >> 1;
	int rt = 0;
	if( L <= mid )
		rt += query(nd->ls,lf,mid,L,R,a,m,v);
	if( R > mid )
		rt += query(nd->rs,mid+1,rg,L,R,a,m,v);
	return rt;

}
int main() {
	init();
	scanf("%s", ss + 1);
	n = strlen(ss + 1);
	root = build( 1, n );
	scanf("%d", &q);
	while( q-- ) {
		int opt;
		scanf("%d", &opt);
		if( opt == 1 ) {
			int pos;
			char s[10];
			scanf("%d%s", &pos, s);
			modify( root, 1, n, pos, id[s[0]] );
		} else {
			int L, R;
			char s[111];
			scanf("%d%d%s", &L, &R, s );
			int ans = 0;
			int len = strlen(s);
			for( int i = 0; i < len; i++ ) {
				ans += query(root,1,n,L,R,(L+i)%len,len,id[s[i]]);
			}
			printf( "%d\n", ans );
		}
	}
}
