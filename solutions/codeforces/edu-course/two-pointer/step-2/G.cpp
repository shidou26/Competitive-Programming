#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define el '\n'
#define ll long long 

const int N = 1e6 + 12;
const int lg = 17;

int n, ans;
ll a[N];
int _lg[N];
ll spt[N][lg + 1];

void prepareSpt() {
	_lg[1] = 0;
    for(int i = 2; i < N; i++)
        _lg[i] = _lg[i / 2] + 1;

	for(int i = 1; i <= n; i++)
		spt[i][0] = a[i];

	for(int j = 1; j <= lg; j++) {
		for(int i = 1; i + (1 << j) - 1 <= n; i++) {
			spt[i][j] = __gcd(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int gcd(int l, int r) {
	int b = _lg[r - l + 1];
    return __gcd(spt[l][b], spt[r - (1 << b) + 1][b]);
}

void solve() {
	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	prepareSpt();

	ans = n + 1;

	for(int i = 1, j = 1; i <= n; i++) {
		while(j <= i && gcd(j, i) == 1)
			ans = min(ans, i - j + 1),
			j++;
	}

	cout << (ans == n + 1 ? -1 : ans) << el;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}