/*
 *	Codeforces 682B — Alyona and Mex
 *	Created by Ziyi Tang
 *
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
#define MOD 1000000007

vi all;
int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all.push_back(tmp);
	}
	sort(all.begin(),all.end());
	if(all[0] != 1)
		all[0] = 1;
	REP(i,1,n){
		if(all[i] > all[i-1]+1)
			all[i] = all[i-1]+1;
	}
	cout << all[n-1]+1 << endl;
	return 0;
}