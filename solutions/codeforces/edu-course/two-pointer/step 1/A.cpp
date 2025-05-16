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

	int i = 1, j = 1;

	a[n + 1] = b[m + 1] = 1e9;

	while(i <= n || j <= m) {
		cout << min(a[i], b[j]) << " ";

		if(a[i] == b[j]) {
			if(a[i + 1] < b[j + 1]) i++;
			else j++;
		}else if(a[i] < b[j]) 
			i++;
		else 
			j++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}
