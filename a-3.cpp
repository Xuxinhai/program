#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<iostream>
#include<map>
#include<iomanip>
#include<fstream>
#include<set>
#include<iomanip>

using namespace std;

typedef long long ll;
const int N = 2e5 + 100;
const int M = 1e5 + 100;
const int mod = 1e9 + 7;
const int INF = 0x3fffffff;
const double PI = 3.14159265358979323;

int n,m;
int k,l;
ll cnt[110][110];

int main()
{	
	scanf("%d%d",&k,&l);
	if(l == 1){
		printf("%I64d\n",k-1);
		return 0;
	}
	memset(cnt,0,sizeof(cnt));
	for(int i = 1;i < k;i++)
		cnt[i][1] = 1;
	for(int i = 2;i <= l;i++){
		for(int j = 0;j < k;j++){
			int x = j - 1;
			int y = j + 1;
			for(int t = 0;t < k;t++){
				if(t == x || t == y)	continue;
				cnt[j][i] = (cnt[j][i] + cnt[t][i-1]) % mod;
			}
//			if(j == k-1)
//				cnt[j][i] = cnt[j][i-1]*(k-1)%mod;
//			else
//				cnt[j][i] = cnt[j][i-1]*(k-2)%mod;
		}
	}
	ll ans = 0;
	for(int i = 0;i < k;i++){
		ans = (ans + cnt[i][l]) % mod;
	}
	printf("%I64d\n",ans);
	return 0;
} 


