template<typename T> struct SegmentTree {
	int n;
	vector<T> st, lzy;

	SegmentTree () {}

	void load(int _n) {
		n = _n;
		st.resize((n << 2) + 3);
		lzy.resize((n << 2) + 3);
	}

	void apply(int id, T value) {
		st[id]; += value;
		lzy[id] += value;
	}

	void push(int id) {
		T k = lzy[id];

		if(k) {
			apply(id << 1, k);
			apply(id << 1 | 1, k);
			lzy[id] = 0;
		}
	}

	void update(int id, int l, int r, int u, int v, T value) {
		if(r < u || v < l) return;
		if(u <= l && r <= v) {
			apply(id, value);
			return;
		}

		push(id);
		int mid = (l + r) >> 1;

		update(id << 1, l, mid, u, v, value);
		update(id << 1 | 1, mid + 1, r, u, v, value);
		st[id] = max(st[id << 1], st[id << 1 | 1]);
	}

	T get(int id, int l, int r, int u, int v) {
		if(u <= l && r <= v) return st[id];

		push(id);
		int mid = (l + r) >> 1;

		if(u > mid) return get(id << 1 | 1, mid + 1, r, u, v);
		if(mid + 1 > v) return get(id << 1, l, mid, u, v);

		return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
	}
};
