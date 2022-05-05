stack<int> sta;
bool in_sta[N];
int id[N], scc_num;
int low[N], dfn[N], timestamp;

void tarjan(int now)
{
	low[now] = dfn[now] = ++timestamp;
	sta.push(now);
	in_sta[now] = 1;
	for(int i = h[now];i; i = ne[i]){
		int to = e[i];
		if(!dfn[to]){
			tarjan(to);
			low[now] = min(low[now], low[to]);
		}else if(in_sta[to]){
			low[now] = min(low[now], dfn[to]);
		}
	}
	if(low[now] == dfn[now]){
		++scc_num;
		int y;
		do{
			y = sta.top();
			sta.pop();
			in_sta[y] = 0;
			id[y] = scc_num;
		}while(y != now);
	}
}