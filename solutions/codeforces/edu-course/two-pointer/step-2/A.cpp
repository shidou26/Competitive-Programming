#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long 

const int N = 1e5 + 12;

int n, ans = 0;
ll s, sum = 0;
ll a[N];

void solve() {
	cin >> n >> s;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 1, j = 1; i <= n; i++) {
		sum += a[i];
		while(j <= i && sum > s)
			sum -= a[j], j++;
		ans = max(ans, i - j + 1);
	}

	cout << ans << el;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}
