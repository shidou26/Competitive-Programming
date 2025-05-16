#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long 

const int N = 1e6 + 12;

int n;
ll k;	
ll ans = 0;
ll a[N];
deque<int> dqMx, dqMn;

void solve() {
	cin >> n >> k;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 1, j = 1; i <= n; i++) {
		while(!dqMn.empty() && a[dqMn.back()] >= a[i])
			dqMn.pop_back();
		while(!dqMx.empty() && a[dqMx.back()] <= a[i])
			dqMx.pop_back();

		dqMx.push_back(i); dqMn.push_back(i);
		
		while(a[dqMx.front()] - a[dqMn.front()] > k) {
			j++;

			if(dqMx.front() < j) 
				dqMx.pop_front();
			if(dqMn.front() < j)
				dqMn.pop_front();
		}

		if(!dqMx.empty() && !dqMx.empty()) 
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