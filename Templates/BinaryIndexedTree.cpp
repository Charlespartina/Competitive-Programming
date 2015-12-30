/*
 *	Binary Indexed Tree
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

int ft[MAXN+1];

int rsq(int b){
	int sum = 0;
	for(; b; b-=(b&-b))
		sum += ft[b];
	return sum;
}
int rsq(int a, int b){
	return rsq(b) - (a == 1 ? 0 : rsq(a-1));
}
void adjust(int k, int v){
	for(; k < ft.size(); k += (k&-k))
		ft[k] += v;
}
int main(){
	
	// Clear
	FILL(ft,0);

	return 0;
}
