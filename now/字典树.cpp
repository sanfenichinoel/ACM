void insert(char *s)
{
	int len = strlen(s);
	int p = 0;
	for(int i = 0;i < len;i++){
		int c = s[i] - 'a';
		if(!trie[p][c]){
			trie[p][c] = k++;
		}
		p = trie[p][c];
	}
	color[p] = 1;
}

int que(char *w)
{
	int len = strlen(w);
	int p = 0;
	for(int i = 0;i < len;i++){
		int c = w[i] - 'a';
		if(!trie[p][c]){
			return 0;
		}
		p = trie[p][c];
	}
	return color[p];
}