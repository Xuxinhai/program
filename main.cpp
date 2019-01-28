#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<iostream>

using namespace std;
 
typedef long long ll;
const int N = 1e4 + 100;
const int M = 1e5 + 100;
const int INF = 0x3fffffff;
const double PI = 3.14159265358979323;

struct node
{
	int u,v,w;
}a[M];

int fa[M];
int time[M];
int n,m;
 
bool cmp(node a,node b)
{
	return a.w < b.w;
}

int findfa(int x)
{
	if(x == fa[x])	return x;
	return fa[x] = findfa(fa[x]);
}

int main()
{	
	int cnt = 0;
	int ans = 0;
	int x = INF;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&time[i]);
		x = min(x,time[i]); 
	}
		
	for(int i = 0;i < m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		a[i].w = time[a[i].u] + time[a[i].v] + 2*a[i].w;
	}
		
		
	for(int i = 1;i <= N;i++)
		fa[i] = i;
	
	sort(a,a+m,cmp);
	for(int i = 0;i < m;i++){
		int u = a[i].u;
		int v = a[i].v;
		if(findfa(u) != findfa(v)){
			cnt++;
			ans += a[i].w;
			fa[findfa(u)] = fa[findfa(v)];
		} 
		if(cnt == n-1)	break;
	}
	printf("%d\n",ans+x);	
	return 0;
} 
