#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long 

const int N = 1e6 + 12;

int n, k;
int cur = 0;
ll ans = 0;
int a[N];
int cnt[N];

void add(int id) {
	int x = a[id];

	if(cnt[x] == 0) cur++;
	cnt[x]++;
}

void remove(int id) {
	int x = a[id];

	cnt[x]--;
	if(cnt[x] == 0) cur--;
}

void solve() {
	cin >> n >> k;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 1, j = 1; i <= n; i++) {
		add(i);
		while(j <= i && cur > k)
			remove(j), j++;
		ans += i - j + 1;
	}

	cout << ans << el;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}