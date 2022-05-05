#define le i<<1
#define ri i<<1|1
struct node
{
	int l, r;
	int val;
};
struct xds
{
	vector<node> tree;
	void push_up(node &FA, const node &one, const node &two)
	{
		FA.val = one.val + two.val;
	}
	void push_up(int i)
	{
		push_up(tree[i], tree[le], tree[ri]);
	}
	void build(int i, int l, int r)
	{
		tree[i].l = l,tree[i].r = r;
		if(l == r){
			tree[i].val = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(le, l, mid);
		build(ri, mid+1, r);
		push_up(i);
	}
	xds(int n):tree(n << 2)
	{
		build(1, 1, n);
	}
	void modify(int i, int x, int change)
	{
		if(tree[i].l == tree[i].r){
			tree[i].val = change;
			return;
		}
		int mid = (tree[i].l + tree[i].r) >> 1;
		if(x > mid){
			modify(ri, x, change);
		}else{
			modify(le, x, change);
		}
		push_up(i);
	}
	node que(int i, int l, int r)
	{
		if(l == tree[i].l && r == tree[i].r){
			return tree[i];
		}
		int mid = (tree[i].l + tree[i].r) >> 1;
		if(l > mid){
			return que(ri, l, r);
		}else if(r <= mid){
			return que(le, l, r);
		}else{
			node ans;
			push_up(ans, que(le, l, mid),  que(ri, mid+1, r));
			return ans;
		}
	}
};
