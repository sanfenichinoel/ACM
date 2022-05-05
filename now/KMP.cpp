int _next[N];
void get_next()
{
	int now = 0, i = 2;
	
	while(i <= len_s){
		if(s[now+1] == s[i]){
			_next[i++] = ++now;
		}else if(now){
			now = _next[now];
		}else{
			_next[i++] = 0;
		}
	}
}

int KMP()
{
	int ans = 0;
	int s_i = 1, ss_i = 1;
	while(ss_i <= len_ss){
		if(s[s_i] == ss[ss_i]){
			s_i++, ss_i++;
		}else if(s_i != 1){
			s_i = _next[s_i-1] + 1;
		}else{
			ss_i++;
		}
		if(s_i == len_s+1){
			ans++;
			s_i = _next[s_i-1] + 1;
		}
	}
	return ans;
}