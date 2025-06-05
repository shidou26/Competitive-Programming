template<typename T> struct CRT {
	struct Congruence {
		T a, m;
	};

	vector<Congruence> congruences;
	void load(T a, T m) {congruences.push_back({a, m});}
	void reload() {congruences.clear();}

	T extendedEuclid(T a, T b, T &x, T &y) {
		if(b == 0) {
			x = 1;
			y = 0;
			return a;
		}

		T x1, y1;
		T g = extendedEuclid(b, a % b, x1, y1);

		x = y1;
		y = x1 - (a / b) * y1;

		return g;
	}

	T inv(T a, T m) {		
		T x, y;
		T g = extendedEuclid(a, m, x, y);
		assert(g == 1);
		return (x % m + m) % m;
	}

	T solve() {
		T mod = 1, answer = 0;
		for(auto [_, m] : congruences) mod *= m;
		for(auto [a, m] : congruences) {
			a = (a % m + m) % m;
			T M = mod / m, N = inv(M, m);
			answer = (answer + a * N % mod * M % mod) % mod;
		}
		return answer;
	}
};
