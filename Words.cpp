/*
 *	Codeforces 59A
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
#include <ctype.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = (int)1E9;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

int main(){
	string line;
	cin >> line;
	int C = 0, c = 0;
	int sz = line.size();
	REP(i,0,sz){
		if(line[i] >= 'a' && line[i] <= 'z')
			c++;
		if(line[i] >= 'A' && line[i] <= 'Z')
			C++;
	}
	if(C > c){
			REP(i,0,sz){
				line[i] = toupper(line[i]);
			}
	} else {
		REP(i,0,sz){
			line[i] = tolower(line[i]);
		}
		
	}
	cout << line << endl;
	return 0;
}