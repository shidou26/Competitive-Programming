class VirtualTree {
private:
    static const int LOG = 20;

    int n, timer, root;
    vector<int> h, tin, tout;
    vector<bool> imp;
    vector<vector<int>> par;
    vector<vector<int>> adj, aux_adj;

public:
    VirtualTree () {}
    VirtualTree(int n) : n(n), h(n + 3), tin(n + 3), tout(n + 3), imp(n + 3), par(n + 3), adj(n + 3), aux_adj(n + 3) {
        timer = 0;
        for(int i = 0; i <= n; i++) {
            imp[i] = false;
            par[i].resize(LOG);
        }
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    void init(int u, int p = -1) {
        tin[u] = ++timer; 
        for(auto [v, w] : adj[u]) if(v != p) {          
            h[v] = h[u] + 1;

            par[v][0] = u; 
            for(int j = 1; j < LOG; j++) {
                par[v][j] = par[par[v][j - 1]][j - 1];
            }

            init(v, u);
        }
        tout[u] = timer;
    }

    int getLCA(int u, int v) {
        if(isAncestor(u, v)) return u;
        if(isAncestor(v, u)) return v;
        for(int i = LOG - 1; i >= 0; i--) if(par[u][i] && !isAncestor(par[u][i], v)) {
            u = par[u][i];
        }
        return par[u][0];
    }

    void build(vector<int> &vertices) {
        for(int ver : vertices) 
            imp[ver] = true;
        imp[1] = false;

        sort(all(vertices), [&](int u, int v){
            return tin[u] < tin[v];
        });

        int k = sz(vertices);
        for(int i = 1; i < k; i++) {
            vertices.push_back(getLCA(vertices[i - 1], vertices[i]));
        }

        sort(all(vertices), [&](int u, int v){
            return tin[u] < tin[v];
        }); 
        filter(vertices); 

        vector<int> stk;
        root = vertices[0]; stk.push_back(root);
        for(int i = 1; i < sz(vertices); i++) {
            while(!isAncestor(stk.back(), vertices[i])) stk.pop_back();
            aux_adj[stk.back()].push_back(vertices[i]);
            stk.push_back(vertices[i]);
        }
    }

    void solve() {
        
    }

    void reload(vector<int> &vertices) {
        for(int ver : vertices) {
            imp[ver] = false;
            aux_adj[ver].clear();
        }
    }

};
