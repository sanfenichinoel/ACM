//匈牙利算法
bool find(int x)
{
    for (int i = h[x]; i; i = ne[i]){
        int to = e[i];
        if (!vis[to]){
            vis[to] = true;
            if (match[to] == 0 || find(match[to])){
                match[to] = x;
                return true;
            }
        }
    }
    return false;
}
int ans = 0;
for (int i = 1; i <= n; i++)
{
    memset(vis, 0, sizeof(vis));
    if (find(i)) ans++ ;
}
