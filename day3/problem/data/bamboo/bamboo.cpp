#include <bits/stdc++.h>
using namespace std;

const int N = 111;

int n;
long long k;
vector<long long> vc;
long long aa[N];

void split( long long a, vector<long long> &vc ) {
	for( long long d = 1, dd; ; d = dd + 1 ) {
		long long k = (a + d - 1) / d;
		if( k <= 1 ) break;
		dd = (a + k - 1 - 1) / (k - 1) - 1;
		vc.push_back(d);
	}
	vc.push_back(a);
}
bool check( long long d ) {
	long long sum = 0;
	for( int i = 1; i <= n; i++ ) {
		sum += (aa[i] + d - 1) / d * d - aa[i];
	}
	return sum <= k;
}
int main() {
	scanf("%d%lld", &n, &k );
	for( int i = 1; i <= n; i++ ) {
		scanf("%lld", aa + i );
		split(aa[i],vc);
	}
	sort( vc.begin(), vc.end() );
	vc.erase(unique(vc.begin(),vc.end()),vc.end());
	vc.push_back( 10000000000000ll );
	long long ans = 1;
	for( int t = 0; t + 1 < (int)vc.size(); t++ ) {
		long long lf = vc[t];
		long long rg = vc[t+1] - 1;
		if( check(lf) == false ) continue;
		while( lf < rg ) {
			long long mid = (lf + rg + 1) >> 1;
			if( check(mid) )
				lf = mid;
			else
				rg = mid - 1;
		}
		ans = max( ans, lf );
	}
	printf( "%lld\n", ans );
}
