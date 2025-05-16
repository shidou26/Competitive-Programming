#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e5 + 12;

int n, m;
int a[N], b[N];

void solve() {
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 1; i <= m; i++)
		cin >> b[i];

	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);

	int ans = 0, sumLast = 0;

	for(int i = 1, j = 1; i <= m; i++) {
		if(i > 1 && b[i - 1] == b[i])
			ans += sumLast;
		else {
			while(j <= n && a[j] < b[i])
				j++;
			
			int last = j;

			while(j <= n && a[j] == b[i])
				j++;

			int cur = j;

			ans += cur - last; 
			sumLast = cur - last;

			// cout << last << " " << cur << endl;
		}

		// cout << sumLast << endl;
	}

	cout << ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}