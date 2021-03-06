/*
 *	UVA 04843
 *	Created by Ziyi Tang
 *	Two Loops
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

vi all;
int main(){
	int test;
	cin >> test;
	while(test--){
		all.clear();
		int num;
		cin >> num;
		REP(i,0,num){
			int tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		int sum = 0;
		REP(i,1,num) REP(j,0,i) if(all[j] <= all[i])
			sum++;
		cout << sum << endl;
	}
	return 0;
}
