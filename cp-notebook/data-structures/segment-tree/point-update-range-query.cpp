// Point Update, Range Query
template<typename T> struct SegmentTree {
private:
    int n;
    vector<T> st;

    T merge(T a, T b) {}
public:
    SegmentTree () {}
    SegmentTree (int n) : n(n), st((n << 2) + 3) {}

    void update(int id, int l, int r, int p, T v) {
        if(l == r) {
            st[id] = v;
            return;
        }
        int mid = l + r >> 1;
        if(p <= mid) update(id << 1, l, mid, p, v);
        else update(id << 1 | 1, mid + 1, r, p, v);
        st[id] = merge(st[id << 1], st[id << 1 | 1]);
    }

    T get(int id, int l, int r, int u, int v) {
        if(u <= l && r <= v) return st[id];
        int mid = l + r >> 1;
        if(u > mid) return get(id << 1 | 1, mid + 1, r, u, v);
        if(mid + 1 > v) return get(id << 1, l, mid, u, v);
        return merge(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v)); 
    }
};
