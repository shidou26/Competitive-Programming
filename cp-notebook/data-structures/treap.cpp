// Status : Not tested, Not optimized
// This treap allows you to get range, reverse a range;

struct treap {
	struct node {
		int key;
		int priority, quantity;
		node *left, *right;
		
		ll sum; bool reversed;

		node () : key(0), priority(0), quantity(0), left(nullptr), right(nullptr), sum(0), reversed(0) {}
		node (int key) : key(key), priority(rng()), quantity(1), left(nullptr), right(nullptr), sum(key), reversed(0) {}

		friend int getSize(node *current) {
			return current == nullptr ? 0 : current -> quantity;
		}

		void update() {
			quantity = getSize(left) + getSize(right) + 1;
			sum = (left == nullptr ? 0 : left -> sum) + (right == nullptr ? 0 : right -> sum) + key;
		}
	};

	node *root;
	treap () : root(nullptr) {}

	void traverse(node *current) {
		if(current != nullptr) {
			push(current);
			traverse(current -> left);
			cout << current -> key;
			traverse(current -> right);
		}
	} void traverse() {traverse(root);}

	void push(node *current) {
		if(current != nullptr && current -> reversed) {
			current -> reversed = 0;
			swap(current -> left, current -> right);
			if(current -> left != nullptr) current -> left -> reversed ^= 1;
			if(current -> right != nullptr) current -> right -> reversed ^= 1;
		}
	}

	void split(node *current, node *&left, node *&right, int pos) {
		push(current);
		if(current == nullptr) return void(left = right = nullptr);

		if(getSize(current -> left) >= pos) {
			split(current -> left, left, current -> left, pos);
			right = current;
		}else {
			split(current -> right, current -> right, right, pos - getSize(current -> left) - 1);
			left = current;
		}

		current -> update();
	}

	void merge(node *&current, node *left, node *right) {
		push(left); push(right);
		if(left == nullptr || right == nullptr) return void(left == nullptr ? (current = right) : (current = left));

		if(left -> priority > right -> priority) {
			merge(left -> right, left -> right, right);
			current = left;
		}else {
			merge(right -> left, left, right -> left);
			current = right;
		}

		current -> update();
	}

	void insert(int v) {
		merge(root, root, new node(v));
	}

	void reverse(int l, int r) {
		node *a, *b, *c;
		split(root, a, b, l - 1);
		split(b, b, c, r - l + 1);
		b -> reversed ^= 1;
		merge(root, a, b);
		merge(root, root, c);
	}

	ll getSum(int l, int r) {
		node *a, *b, *c;
	    split(root, a, b, l - 1);
		split(b, b, c, r - l + 1);
	    ll answer = b -> sum;
	   	merge(root, a, b);
		merge(root, root, c);
	    return answer;
	}

	~treap () {
		delete root;
	}
};
