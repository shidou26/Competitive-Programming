template<class T> struct DiophatineSolver {
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

	bool find_any_solution(T a, T b, T c, T &x, T &y, T &g) {
		if(a == 0 && b == 0) {
			if(c == 0) {
				x = y = g = 0;
				return true;
			}return false;
		}
		
		g = extendedEuclid(abs(a), abs(b), x, y);
		if(c % g) return false;

		x *= c / g;
		y *= c / g;
		if(a < 0) x = -x;
		if(b < 0) y = -y;

		return true;
	}

	T find_all_solutions(T a, T b, T c, T min_x, T max_x, T min_y, T max_y) {
		assert(min_x <= max_x && min_y <= max_y);

		if(a == 0 && b == 0) {
			if(c == 0) 
				return 1LL * (max_x - min_x + 1) * (max_y - min_y + 1);
			else return 0;
		}	

		if(a == 0) { // y = c / b
			if(c % b) return 0;
			if(min_y <= c / b && c / b <= max_y) 
				return max_x - min_x + 1;
			else return 0;
		}

		if(b == 0) { // x = c / a
			if(c % a) return 0;
			if(min_x <= c / a && c / a <= max_x) 
				return max_y - min_y + 1;
			else return 0;
		}

		T x, y, g;
		if(!find_any_solution(a, b, c, x, y, g)) 
			return false;
		
		a /= g;
		b /= g;
		auto shift = [&](T &x, T &y, T a, T b, T times) -> void {
			x += b * times;
			y -= a * times;
		};

		T sign_a = a > 0 ? 1 : -1;
		T sign_b = b > 0 ? 1 : -1;

		shift(x, y, a, b, (min_x - x) / b);
		if(x < min_x) shift(x, y, a, b, sign_b);
		if(x > max_x) return 0;
		T lx1 = x;

		shift(x, y, a, b, (max_x - x) / b);
		if(x > max_x) shift(x, y, a, b, -sign_b);
		T rx1 = x;

		shift(x, y, a, b, -(min_y - y) / a);
		if(y < min_y) shift(x, y, a, b, -sign_a);
		if(y > max_y) return 0;
		T lx2 = x;

		shift(x, y, a, b, -(max_y - y) / a);
		if(y > max_y) shift(x, y, a, b, sign_a);
		T rx2 = x;

		if(lx2 > rx2) swap(lx2, rx2);
		T lx = max(lx1, lx2);
		T rx = min(rx1, rx2);

		if(lx > rx) return 0;
		return (rx - lx) / abs(b) + 1;
	}
};
