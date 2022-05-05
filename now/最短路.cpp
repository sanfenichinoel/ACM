int h[N], e[N<<1], w[N<<1], ne[N<<1], idx = 0;
void add(int a, int b, int c)
{
    e[++idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx;
}


//djstl
bool vis[N];
int len[N];
struct node
{ 
	int l, u;
	friend bool operator<(const node &a, const node &b) { 
		return a.l > b.l; 
	} 
};
priority_queue<node> q;
void dij(int s)
{
	memset(vis, 0, sizeof(vis));
	memset(len, 0x3f, sizeof(len));
	len[s] = 0;
	q.push({0, s});
	while (!q.empty()) {
        int now = q.top().u;
        q.pop();
        if(vis[now]) continue;
        vis[now] = 1;
        for(int i = h[now]; i; i = ne[i]){
            int to = e[i];
            if(!vis[to] && len[to] > len[now] + w[i]){
                len[to] = len[now] + w[i];
                q.push({len[to], to});
            }
        }
	}
}


// bf
void bf(int st)
{ 
    memset(len, 0x3f, sizeof len); 
    len[st] = 0;
    for (int i = 1; i < n; ++i){
        for (int j = 0; j < e.size(); ++j){ 
            int u = e[j].u, v = e[j].v, l = e[j].l; 
            if (len[v] > len[u] + l){
                len[v] = len[u] + l;
            }
        }
    }
}

//spfa (判负环)
bool spfa(int beg)
{
    queue<int> q;
    mem(dis, 0x3f);
    dis[beg] = 0;
    // for(int i = 1;i <= n;i++){
    //     q.push(i);
    //     vis[i] = 1;
    // }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        vis[now] = 0;
        for(int i = h[now]; i; i = ne[i]){
	        int to = e[i];
            if(dis[to] < dis[now] + w[i]){
                dis[to] = dis[now] + w[i];
                cnt[to] = cnt[now] + 1;
                if(cnt[to] >= n+1) return false;    
                if(!vis[to]){
                    vis[to] = 1;
                    q.push(to);
                }
            }
        } 
    }
    return true;
}

//floyd
void floyd()
{
    memset(len, 0x3f, sizeof(len));
    for(int i = 1;i <= n;i++){
        len[i][i] = 0;
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                len[i][j] = min(len[i][j], len[i][k] + len[k][j]);
            }
        }
    }
}
