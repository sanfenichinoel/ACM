int lg[200005];
int st[200005][100];

int que(int l,int r)
{
	int k = lg[r - l + 1];
	return max(st[l][k] , st[r - (1<<k) + 1][k]);
}
void init()
{
    lg[1]= 0;
	for(int i = 2;i <= n;i++){
		lg[i] = lg[i>>1] + 1;
	}
}

void stbiao()
{
    for(int i = 1;i <= n;i++){
        cin >> st[i][0];
    }
    for(int j = 1;j <= lg[n];j++){
		for(int i = 1;i <= n;i++){
			st[i][j] = max(st[i][j-1] , st[i + (1<<(j-1))][j-1]);
		}
	}
}

