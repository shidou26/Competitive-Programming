vector<int> suffixArray(string s) {
	s.push_back('$'); int n = sz(s);
	const int alphabet_size = 256;

	int classes;
	vector<int> p(n), c(n), pn(n), cn(n);
	vector<int> cnt(max(alphabet_size, n), 0);

	for(int i = 0; i < n; i++) cnt[s[i]]++;
	for(int i = 1; i < alphabet_size; i++)
		cnt[i] += cnt[i - 1];

	for(int i = 0; i < n; i++) {
		p[--cnt[s[i]]] = i;
	}

	classes = c[p[0]] = 0;
	for(int i = 1; i < n; i++) {
		if(s[p[i]] != s[p[i - 1]]) classes++;
		c[p[i]] = classes;
	}

	for(int k = 0; (1 << k) < n; k++) {
		for(int i = 0; i < n; i++) {
			pn[i] = p[i] - (1 << k);
			if(pn[i] < 0) pn[i] += n;
		}

		for(int i = 0; i <= classes; i++)
			cnt[i] = 0;
		
		for(int i = 0; i < n; i++) cnt[c[pn[i]]]++;
		for(int i = 1; i <= classes; i++)
			cnt[i] += cnt[i - 1];

		for(int i = n - 1; i >= 0; i--) {
			p[--cnt[c[pn[i]]]] = pn[i];
		}

		classes = cn[p[0]] = 0;
		for(int i = 1; i < n; i++) {
			pair<int, int> x = {c[p[i]], c[(p[i] + (1 << k)) % n]};
			pair<int, int> y = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};

			if(x != y) classes++;
			cn[p[i]] = classes;
		}

		for(int i = 0; i < n; i++)
			c[i] = cn[i];
	}

	p.erase(p.begin());
	return p;
}
