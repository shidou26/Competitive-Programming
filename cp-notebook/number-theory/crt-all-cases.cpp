using ll = bigint;

ll extendedEuclid(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1;
	ll g = extendedEuclid(b, a % b, x1, y1);

	x = y1;
	y = x1 - (a / b) * y1;

	return g;
}

pair<ll, ll> solve(ll a1, ll m1, ll a2, ll m2) {
	ll n1, n2;
    ll g = extendedEuclid(m1, m2, n1, n2);
    ll m = m1 / g * m2;

    assert((a1 - a2) % g == 0);
    a1 = (a1 % m1 + m1) % m1;
	a2 = (a2 % m2 + m2) % m2;

    ll x = (a1 * n2 % m * (m2 / g) % m + a2 * n1 % m * (m1 / g) % m) % m;
   	return {(x % m + m) % m, m};
}

int n;
pair<ll, ll> a[12];

void process() {
	if(n == 1) cout << (a[1].first % a[1].second + a[1].second) % a[1].second << endl;
	else {
		pair<ll, ll> last = solve(a[1].first, a[1].second, a[2].first, a[2].second);
		for(int i = 3; i <= n; i++) 
			last = solve(last.first, last.second, a[i].first, a[i].second);
		cout << last.first << endl;
	}
}

void input() {
	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}
}
