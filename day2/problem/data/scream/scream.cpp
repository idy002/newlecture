#include <bits/stdc++.h>
using namespace std;

#define prev PREEVEV
const int N = 35000 + 10;
const int oo = 0x3f3f3f3f;

struct Node;
void modify(Node *nd, int lf, int rg, int L, int R, int delta);
struct Node {
	int vmax;
	int flag;
	Node *ls, *rs;
	void update() {
		vmax = max(ls->vmax, rs->vmax);
	}
	void pushdown(int lf, int rg) {
		if(flag) {
			int mid = (lf + rg) >> 1;
			modify(ls,lf,mid,lf,mid,flag);
			modify(rs,mid+1,rg,mid+1,rg,flag);
			flag = 0;
		}
	}
}pool[N*2], *tail, *root;

int n, m;
int aa[N], pos[N], prev[N];
int dp[2][N];
int cur = 1, prv = 0;

Node *build(int lf, int rg) {
	Node *nd = ++tail;
	nd->vmax = nd->flag = 0;
	if(lf == rg) {
		nd->vmax = dp[prv][lf];
	} else {
		int mid = (lf + rg) >> 1;
		nd->ls = build(lf, mid);
		nd->rs = build(mid+1, rg);
		nd->update();
	}
	return nd;
}
void modify(Node *nd, int lf, int rg, int L, int R, int delta) {
	if(L <= lf && rg <= R) {
		nd->vmax += delta;
		nd->flag += delta;
		return;
	}
	int mid = (lf + rg)>>1;
	nd->pushdown(lf,rg);
	if( L <= mid )
		modify(nd->ls, lf, mid, L, R, delta);
	if( R > mid )
		modify(nd->rs, mid+1, rg, L, R, delta);
	nd->update();

}
int query(Node *nd, int lf, int rg, int L, int R) {
	if(L <= lf && rg <= R)
		return nd->vmax;
	int mid = (lf + rg) >> 1;
	nd->pushdown(lf,rg);
	int rt = -oo;
	if( L <= mid )
		rt = max( rt, query(nd->ls, lf, mid, L, R) );
	if( R > mid )
		rt = max( rt, query(nd->rs,mid+1,rg,L,R) );
	return rt;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", aa + i);
	for(int i = 1; i <= n; i++) {
		prev[i] = pos[aa[i]];
		pos[aa[i]] = i;
	}
	
	for(int i = 1; i <= n; i++) 
		dp[prv][i] = dp[prv][i-1] + (prev[i] == 0);
	for(int k = 2; k <= m; k++) {
		tail = pool;
		root = build(1, n);
		for(int i = 1; i <= n; i++) {
			if(i < k )
				dp[cur][i] = -oo;
			else {
				modify(root, 1, n, max(prev[i],1), i - 1, +1);
				dp[cur][i] = query(root, 1, n, 1, i - 1);
			}
		}
		swap(prv, cur);
	}
	printf("%d\n", dp[prv][n]);
}
