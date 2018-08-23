#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt[1<<4];

void yes() {
	printf("YES\n");
}
void no() {
	printf("NO\n");
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= n; i++) {
			int s = 0;
			for(int j = 0; j < k; j++) {
				int v;
				scanf("%d", &v);
				if(v) s |= 1<<j;
			}
			cnt[s]++;
		}
		int U = (1<<k) - 1;
		for(int s1 = 0; s1 <= U; s1++)
			for(int s2 = 0; s2 <= U; s2++) {
				if(!cnt[s1] || !cnt[s2]) continue;
				if(!(s1 & s2)) {
					yes();
					goto NEXT;
				}
			}
		no();
NEXT:;
	}
}
