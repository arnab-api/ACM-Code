#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

int n,m;
int ans[405], z, beg, end;
bool g[405][405], v[405];

void Rev(int beg,int end)
{
	while(beg < end) swap(ans[beg ++], ans[end --]);
}

void ext()
{
	while(true)
	{
		bool flag = false;
		for(int i = 1; i <= n; i ++)
		{
			if(!v[i] && g[end][i])
			{
				ans[z ++] = end = i;
				v[i] = flag = true;
				break;
			}
		}
		if(!flag) break;
	}
}

bool hamilton()
{
	memset(v,false,sizeof(v));
	beg = 1;
	for(int i = 1; i <= n; i ++)
		if(g[beg][i])
		{
			end = i;
			break;
		}

	v[beg] = v[end] = true;
	ans[0] = beg; ans[1] = end; z = 2;

	while(true)
	{
		ext();
		Rev(0,z-1);
		swap(beg,end);
		ext();

		int mid = 0;
		if(!g[beg][end])
		{
			for(int i = 1; i < z-2; i ++)
			{
				if(g[ans[i]][end] && g[ans[i+1]][beg])
				{
					mid = i+1;
					break;
				}
			}
			Rev(mid,z-1);
			end = ans[z-1];
		}
		if(z == n) break;
		for(int i = 1; i <= n; i ++)
		{
			if(!v[i])
			{
				int j;
				for(j = 1; j < z-1; j ++)
					if(g[ans[j]][i])
					{
						mid = j;
						break;
					}
				if(g[ans[mid]][i])
				{
					end = i; mid = j; break;
				}
			}
		}
		beg = ans[mid-1];
		Rev(0,mid-1);
		Rev(mid,z-1);
		ans[z ++] = end;
		v[end] = true;
	}
}

int main()
{
	while(scanf("%d",&n) != EOF)
	{
		memset(g,false,sizeof(g));
		getchar();
		char str[10];
		while(gets(str) && str[0]!='%')
		{
			int a,b;
			sscanf(str,"%d%d",&a,&b);
			g[a][b] = g[b][a] = true;
		}

		bool chk = hamilton();

		if(chk)
		{
			for(int i = 0; i < z; i ++)
			{
				if(i == 0) printf("%d",ans[i]);
				else printf(" %d",ans[i]);
			}
			printf(" %d\n",ans[0]);
		}
		else
		{
			printf("N\n");
		}
	}
}
