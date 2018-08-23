#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct Stat {
	int d, s;
	Stat(){}
	Stat(int d, int s):d(d),s(s){}
};
bool operator<(const Stat &r, const Stat &s) {
	return r.d > s.d;
}

int n, S;
int s[N], a[N], b[N], d[N];
Stat stats[N];
long long pres[N];

long long cp(long long len) {
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		if(pres[i] <= len) {
			ans += (long long)stats[i].s * stats[i].d;
		} else {
			ans += (long long)(len - pres[i-1]) * stats[i].d;
			break;
		}
	}
	return ans;
}
long long calc(long long s, long long more) {
	vector<int> vc;
	for(int i = 1; i <= n; i++) {
		if(pres[i] >= s) {
			for(int j = 1; j <= pres[i] - s + 1 && more >= 1; j++) {
				vc.push_back(stats[i].d);
				more--;
			}
			for(int ii = i + 1; ii <= n && more >= 1; ii++)
				for(int j = 1; j <= stats[ii].s && more >= 1; j++) {
					vc.push_back(stats[ii].d);
					more--;
				}
			long long ans = 0;
			for(int t = 0; t < (int)vc.size(); t++) {
				if(vc[t] > 0) ans += vc[t];
			}
			return ans;
		}
	}
	return 0;
}
int main() {
	scanf("%d%d", &n, &S);
	long long sum = 0, ans = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d", s+i, a+i, b+i);
		sum += s[i];
		ans += (long long)b[i] * s[i];
		stats[i] = Stat(a[i] - b[i], s[i]);
	}
	sort(stats+1, stats+1+n);
	for(int i = 1; i <= n; i++) 
		pres[i] = pres[i-1] + stats[i].s;
	long long m = (sum + S - 1) / S;
	long long sub = 0;
	if(stats[n].d >= 0) {
		for(int i = 1; i <= n; i++)
			sub += (long long)stats[i].d * stats[i].s;
		ans += sub;
		printf("%lld\n", ans);
	} else {
		for(int i = 1; i <= n; i++) {
			if(stats[i].d < 0) {
				long long subans = ans + cp(pres[i-1] / S * S);
				long long more = S * m - sum;
				subans = max(subans, ans + cp(pres[i-1] / S * S + S - more) + calc(pres[i - 1] / S * S + S - more + 1, more));
				printf("%lld\n", subans);
				break;
			}
		}
	}
}
