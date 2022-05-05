struct Fenwick
{
	vector<int> tree;
	int n;
	Fenwick(int n):tree(n+5) {this->n = n;}
	int lowbit(int x){return x&(-x);}
	int que(int x){int ans = tree[0];  while(x){ans += tree[x];x -= lowbit(x);}  return ans;}
	void update(int x,int change){while(x <= n){tree[x] += change;x += lowbit(x);}}
};