/*
 *	UVA 11572
 *	Created by Ziyi Tang
 *	Sliding Window: Two Pointers for Unique Interval
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
#define MAXN 10000005

map<int,int> mm;
vector<int> all;
int main(){
	int test;
	cin >> test;
	while(test--){
		mm.clear();
		all.clear();
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			int tmp;
			scanf("%d", &tmp);
			all.push_back(tmp);
		}
		int i = 0, j = 0;
		int maxp = 0;
		while(j < n){
			int now = all[j];
			if(mm.count(now)){
				i = max(i,mm[now]+1);	
			}
			mm[now] = j;
			maxp = max(maxp, j-i+1);
			j++;
		}
		printf("%d\n", maxp);
	}
	return 0;
}