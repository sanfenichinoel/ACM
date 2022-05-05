
int lowbit(int x)
{
	return x&(-x);
}

int que(int x)
{
	int ans = 0;
	while(x){
		ans += tree[x];
		x -= lowbit(x);
	}
	return ans;
}

void update(int x,int change)
{
	while(x <= MAXN){
		tree[x] += change;
		x += lowbit(x);
	}
}


// ***************¶şÎ¬**********************************
int que(int x,int y)
{
	int  ans = 0;
	int cy;
	while(x){
		cy = y;
		while(y){
			ans += tree[x][y];
			y -= lowbit(y);
		}
		x -= lowbit(x);
	}
	return ans;
}

void update(int x,int y,int change)
{
	while(x <= MAXN_X){
		cy = y;
		while(y <= MAXN_Y){
			tree[x][y] += change;
			y += lowbit(y);
		}
		x += lowbit(x);
	}
}