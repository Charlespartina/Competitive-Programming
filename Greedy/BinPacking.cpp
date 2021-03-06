/*
 *	Topcoder 598 Div1 1
 *	Created by Ziyi Tang
 *	Greedy
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
#define MAXN 55
#define MOD 1000000007

class BinPacking {
public:
	int minBins(vector <int>);
};

int BinPacking::minBins(vector <int> item) {
	sort(item.begin(), item.end());
	int mark[MAXN];
	REP(i,0,MAXN) mark[i] = 1;
	int cont = 0;
	REP(t,0,50){
		int rem = 300;
		for(int i = item.size()-1; i >= 0; i--){
			if(mark[i] == 0) continue;
			if(item[i] <= rem){
				mark[i] = 0;
				rem -= item[i];
			}
		}
		if(rem!=300) cont++;
	}
	return cont;
}


//Powered by [KawigiEdit] 2.0!