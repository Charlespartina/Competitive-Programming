/*
 *	
 *	Created by Ziyi Tang
 *	dp[i][j][k] = dp[i-1][j-1][k-i] + dp[i-1][j][k]
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

int dp[30][30][500];
int main(){
	FILL(dp,0);
	dp[0][0][0] = 1;
	REP(i,1,27){
		REP(j,0,27){
			REP(k,0,500){
				dp[i][j][k] = dp[i-1][j][k];
				if(k >= i && j > 0)
					dp[i][j][k] += dp[i-1][j-1][k-i];
			}
		}
	}
	int cas = 0;
	int l,s;
	while(cin >> l >> s && (l != 0 || s != 0)){
		cas++;
		if(l > 26 || s > 490)
			printf("Case %d: %d\n", cas, 0);
		else 
			printf("Case %d: %d\n", cas, dp[26][l][s]);
	}
	return 0;
}

