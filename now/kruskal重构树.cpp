
int h[N], e[N<<1], ne[N<<1], idx = 0, tot = 0;
void add(int a, int b)
{
    e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}
int val[N<<1];
struct ed
{
    int l, r, w;

    friend bool operator<(ed a, ed b){
        return a.w > b.w;                       // 最大 / 小生成树
    }
}edge[N];

int fa[N];
void init(int n){ for(int i = 0;i <= n;i++){ fa[i] = i; } }
int _find(int i) { return fa[i] == i ? i : fa[i] = _find(fa[i]); }
void merge(int a, int b) { fa[_find(a)] = _find(b); }
bool yes(int a, int b) { return _find(a) == _find(b); }

const int base = 20;
int d[N<<1], fatree[N<<1][base+3];
void bfs(int root)
{
	memset(d, -1, sizeof(d));
    queue<int> q;
	q.push(root);
	d[root] = 0;
	while(!q.empty()){
		int now = q.front();
		q.pop();

        for(int i = h[now]; i; i = ne[i]){
            int to = e[i];
            if(d[to] != -1) continue;

            d[to] = d[now] + 1;
            q.push(to);
            fatree[to][0] = now;
            for(int j = 1;j <= base;j++){
                fatree[to][j] = fatree[ fatree[to][j-1] ][j-1];
            }
        }
	}
}
int lca(int a, int b)
{
	if(d[a] < d[b]){
		swap(a, b);
	}
	
	for(int i = base; i >= 0; i--){
		if(d[ fatree[a][i] ] >= d[b]){
			a = fatree[a][i];
		}
	}
	
	if(a == b){
		return b;
	}
	for (int i = base; i >= 0; --i) 
		if (fatree[a][i] != fatree[b][i]) 
			a = fatree[a][i], b = fatree[b][i]; 
	
	return fatree[a][0];
}

void kruskal()
{
    init(n<<1);
    tot = n;
    for(int i = 0;i < m;i++){
        int a = edge[i].l, b = edge[i].r;
        a = _find(a), b = _find(b);
        if(!yes(a, b)){
            val[++tot] = edge[i].w;
            merge(a, tot), merge(b, tot);
            add(tot, a), add(tot, b);
            add(a, tot), add(b, tot);
        }
    }
    val[++tot] = INF;  // 超级源点处理不连通
    for(int i = 1;i < tot;i++){
        if(_find(i) == i){
            merge(i, tot);
            add(tot, i), add(i, tot);
        }
    }
    bfs(tot);
}

