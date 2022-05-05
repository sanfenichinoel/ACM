//  边
stack<int> sta;
bool in_sta[N];
int id[N], dcc_num;
int low[N], dfn[N], timestamp;
bool is_bridge[N];
#define back(x) (x&1 ? x+1 : x-1)

void tarjan(int now, int from)
{
	low[now] = dfn[now] = ++timestamp;
	sta.push(now);
	in_sta[now] = 1;
	for(int i = h[now];i; i = ne[i]){
		int to = e[i];
		if(!dfn[to]){
			tarjan(to, i);
			low[now] = min(low[now], low[to]);

			if(dfn[now] < low[to]){
				is_bridge[i] = is_bridge[back(i)] = 1;
			}
		}else if(i != back(from)){
			low[now] = min(low[now], dfn[to]);
		}
	}
	if(low[now] == dfn[now]){
		++dcc_num;
		int y;
		do{
			y = sta.top();
			sta.pop();
			in_sta[y] = 0;
			id[y] = dcc_num;
		}while(y != now);
	}
}

// 点
// woc这个太难了，那个点双连通分量我完全不会，下面这个只是找割点

int low[N], dfn[N], timestamp;
bool cut[N];

void tarjan(int now, int root)
{
	low[now] = dfn[now] = ++timestamp;
	int cnt = 0;
	for(int i = h[now];i; i = ne[i]){
		int to = e[i];
		if(!dfn[to]){
			tarjan(to, root);
			low[now] = min(low[now], low[to]);

			if(dfn[now] <= low[to] && now != root){    
				cut[now] = 1;
			}
			if(now == root){
				cnt++;
			}
		}
		low[now] = min(low[now],dfn[to]);
	}
	if(cnt >= 2 && now == root){
		cut[now] = 1;
	}
}
