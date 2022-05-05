// ******************** kruskal***********
struct edge
{                                                 
    int u, v, w;
    bool operator<(const edge b)const
    {
        return w < b.w;
    }
}e[N];                                      
int fa[N];
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void kruskal()
{
    sort(e, e + m);
    for (int i = 0; i < m; i++)
    {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (find(u) != find(v)){    
            fa[find(u)] = find(v);                        
            // do something                                         
        }
    }
}


//************************** prim *********************
struct edge
{ 
	int u, v, w; 
	friend bool operator<(const edge &a, const edge &b) { 
		return a.w > b.w;
	} 
};
bool vis[N];
void prim(int st)
{ 
	priority_queue<edge> q;
	vis[st] = true;
    for(int i = h[st];i;i = ne[i]){
        int to = e[i];
        q.push({st, to, w[i]});
    }
	while (!q.empty()) { 
		edge now = q.top();
		q.pop();
		int u = now.u, v = now.v;
		if (vis[v]) continue; 
		vis[v] = true; 
		// do something
        for(int i = h[v]; i; i = ne[i]){
            int to = e[i];
            q.push({v, e[i], w[i]});
        }
	}
}
