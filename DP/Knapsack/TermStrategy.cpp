/*
 *	UVA 11341
 *	Created by Ziyi Tang
 *	dp[i][j] = max(dp[i][j], all[i][k] + dp[i-1][j-k]);
 *  dp[i][j] = -1 if this situation is impossible to achieve.
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000

int dp[15][105];
int all[15][105];
int mark[15][105];
int main(){
	int t;
	cin >> t;
	while(t--){
		FILL(dp,-1);
		int n,m;
		cin >> n >> m;
		REP(i,1,n+1) REP(j,1,m+1){
			int tmp;
			cin >> tmp;
			all[i][j] = tmp;
		}
		dp[0][0] = 0;
		REP(i,1,n+1) REP(j,1,m+1) REP(k,1,j+1) {
			if(all[i][k] >= 5 && dp[i-1][j-k] != -1)
				dp[i][j] = max(dp[i][j], all[i][k] + dp[i-1][j-k]);
		}
		double re = (double)dp[n][m]/n+1e-9;
		if(dp[n][m] != -1)
			printf("Maximal possible average mark - %.2lf.\n", re);
		else
			printf("Peter, you shouldn\'t have played billiard that much.\n");
	}
	return 0;
}

