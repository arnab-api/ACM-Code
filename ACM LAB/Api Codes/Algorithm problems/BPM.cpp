class Bmp{
	int used[sz], ans=0,par[sz];
	int maxMatch(void){
		ms(par,-1);
		do{
			ms(used,0);
			int path=0;
			for(int i=0;i<n;i++){
				if(par[i]==-1 and used[i]==0)
					path+=match(i);
			}
		}
		while(path);
		for(int i=0;i<n;i++)
			if(par[i]!=-1)
				ans++;
		return ans;
	}
	int match(int u){
		if(used[u]==true)
			return false;
		uesd[u]=true;
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i];
			if(par[v]==-1 or match(par[v]){
				par[v]=u;
				return true;
			}
		}
		return false;
	}
};
