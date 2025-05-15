template<class T> class QueueOnTwoStack {
private:
	class Stack {
	private:
		vector<int> st;
		vector<T> value;

	public:
		Stack () {
			 // edit here
		}

		int top() {
			return st.back();
		}

		T get() {
			return value.back();
		}

		bool empty() {
			return st.empty();
		}

		void push(int x) {
			st.push_back(x);
			value.push_back(/*edit here*/);
		}

		void pop() {
			st.pop_back();
			value.pop_back();
		}
	} one, two;

public:
	void add(int x) {
		two.push(x);
	}

	void ravage() {
		if(one.empty()) {
			while(!two.empty()) {
				one.push(two.top());
				two.pop();
			}
		}
		one.pop();
	}

	bool good() {
		// edit here
	}
};
