const int base = 20;
int deep[N<<1], fatree[N<<1][base+3];
void bfs(int root)
{
	memset(deep, -1, sizeof(deep));
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