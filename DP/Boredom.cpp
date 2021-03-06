/*
 *	CodeForces 455A
 *	Created by Ziyi Tang
 *	Compute the count of each element
 *	dp[i] = max(i*cont[i] + dp[i-2], dp[i-1]);
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

ll cont[100005];
ll dp[100005];
int main(){
	int n, tmp;
	int maxe = 0;
	cin >> n;
	REP(i,0,n){
		cin >> tmp;
		maxe = max(maxe, tmp);
		cont[tmp]++;
	}
	dp[0] = 0;
	dp[1] = cont[1]*1;
	REP(i,2,maxe+1){
		dp[i] = max(i*cont[i] + dp[i-2], dp[i-1]);
	}
	cout << dp[maxe] << endl;
	return 0;
}

