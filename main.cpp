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
const int mod = 100003;
const int INF = 0x3fffffff;
const double PI = 3.14159265358979323;

struct node{
	int x;
	int t;
	node(int a = 0,int b = 0):x(a),t(b){} 
};
int m,n;
int d[N];
int vs[N];
int main() 
{
	cin >> n;
	memset(vs,0,sizeof(vs));
	for(int i = 1;i <= n;i++)
		cin >> d[N];
		
	int x = 1;
	int cnt = 0;
	while(true){
		if(vs[x] == 1){
			cout << cnt;
			return 0;
		}
		vs[x] = 1;
		cnt++;
		x = d[x];
	}
	return 0;
}



