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
int sz;
vi all;

struct BITree{
	// Start Index 1
	int n_;
	int bt[MAXN];
	BITree(int n) : n_(n) {
		FILL(bt,0);
	}
	int req(int b){
		int sum = 0;
		for(; b; b-=(b&-b)){
			sum+=bt[b];
		}
		return sum;
	}
	int req(int a, int b){
		return req(b)-req(a);
	}
	void update(int i, int val){
		for(; i <= n_; i+=(i&-i)){
			bt[i] += val;
		}
	}
	void clear(){
		FILL(bt,0);
	}
};
int main(){
	
	// Clear
	all.clear();

	return 0;
}
