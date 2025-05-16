#include <bits/stdc++.h>
using namespace std;

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
	
	for(int i = 1, j = 1; i <= m; i++) {
		while(j <= n && a[j] < b[i])
			j++;
		cout << j - 1 << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}