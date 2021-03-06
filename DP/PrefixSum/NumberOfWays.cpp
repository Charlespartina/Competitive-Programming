/*
 *	Codeforces 226C
 *	Created by Ziyi Tang
 *	Prefix Sum with two pointers
 *	Use prefix sum to count the number of ways 0...i has sum of sum/3.
 *	One pointer i iterates from right to left. Each time the sum on i's right
 *	equals to sum/3, we add prefixsum[i-2].
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
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 500005
#define MOD 1000000007

vi all;
ll presum[MAXN];
int main(){
	int n;
	cin >> n;
	ll sum = 0LL;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all.push_back(tmp);
		sum += tmp;
	}
	FILL(presum,0);
	ll cont = 0;
	if(sum%3 != 0 || n <= 2){
		cout << 0 << endl;
		return 0;
	}
	ll cur = 0;
	// Compute how many presums that equals sum/3 before i
	REP(i,0,n){
		if(i != 0)
			presum[i] = presum[i-1];
		cur += all[i];
		if(cur == sum/3)
			presum[i]++;
	}
	cur = 0;
	for(int i = n-1; i > 1; i--){
		cur += all[i];
		if(cur == sum/3){
			cont += presum[i-2];
		}
	}
	cout << cont << endl;
	return 0;
}