#define le i<<1
#define ri i<<1|1
struct node
{
    int l, r;
    int lazy;
    int val;
}tree[4 * N];

void push_up(node &FA, const node &one, const node &two)
{
    FA.val = one.val + two.val;
}
void push_up(int i)
{
    push_up(tree[i], tree[le], tree[ri]);
}

void push_down(int i)
{
    tree[le].lazy += tree[i].lazy;
    tree[le].val += (tree[le].r - tree[le].l + 1) * tree[i].lazy;
    tree[ri].lazy += tree[i].lazy;
    tree[ri].val += (tree[ri].r - tree[ri].l + 1) * tree[i].lazy;
    tree[i].lazy = 0;
}

void build(int i, int l, int r)
{
    tree[i].l = l,tree[i].r = r;
    if(l == r){
        tree[i].val = a[l];
        tree[i].lazy = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(le, l, mid);
    build(ri, mid+1, r);
    push_up(i);
}

void modify(int i, int l, int r, int change)
{
    if(tree[i].l == l && tree[i].r == r){
        tree[i].val += (tree[i].r - tree[i].l + 1) * change;
        tree[i].lazy += change;
        return;
    }
    int mid = (tree[i].l + tree[i].r) >> 1;
    push_down(i);
    if(l > mid){
        modify(ri, l, r, change);
    }else if(r <= mid){
        modify(le, l, r, change);
    }else{
        modify(le, l, mid, change);
        modify(ri, mid+1, r, change);
    }
    push_up(i);
}

node que(int i, int l, int r)
{
    if(l == tree[i].l && r == tree[i].r){
        return tree[i];
    }
    int mid = (tree[i].l + tree[i].r) >> 1;
    push_down(i);
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
