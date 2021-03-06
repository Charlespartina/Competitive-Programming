/*
 *	UVA 11284
 *	Created by Ziyi Tang
 *	TSP Problem with ASAP
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;
#define INF 1E9
#define INFL (long)1E18
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int n,m;
int mat[55][55];
int dp[15][10005];
vpi all;
int sz;

int tsp(int pos, int path){
	if (path == (1 << sz) -1){
		return -mat[all[pos].first][0];
	}
	if (dp[pos][path] != -1)
		return dp[pos][path];
	else{
		int maxp = -INF;
		maxp = max(maxp, -mat[all[pos].first][0]);
		
		for (int i = 0; i < sz; i++){
			if ((path & (1 << i)) == 0){
				maxp = max(maxp, all[i].second - mat[all[pos].first][all[i].first] + tsp(i, path | (1 << i)));
			}
		}
		return dp[pos][path] = maxp;
	}
}	
int main(){
int test;
	scanf("%d", &test);
	while(test--){
		
		for (int i = 0; i < 55; i++){
			for(int j = 0; j < 55; j++){
				if (i == j)
					mat[i][j] = 0;
				else
					mat[i][j] = INF;
			}
		}
		for (int i = 0; i < 15; i++){
			for(int j = 0; j < 10000; j++){
				dp[i][j] = -1;
			}
		}
		
		all.clear();
		all.push_back(make_pair(0, 0));
		scanf("%d %d",&n,&m);
		int x,y,pin;
		int p1,p2;
		for (int i = 0; i < m; i++){
			scanf("%d %d %d.%d",&x,&y,&p1,&p2);
			pin = p1*100+p2;
			if (mat[x][y] > pin){
				mat[x][y] = pin;
				mat[y][x] = pin;
			}	
		}

		// ASAP: Floyd Warshall
		for (int k = 0; k < n+1; k++){
			for (int i = 0; i < n+1; i++){
				for (int j = 0; j < n+1; j++){
					if (mat[i][k] == INF || mat[k][j] == INF)
						continue;
					mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
				}
			}
		}

		int num;
		scanf("%d",&num);
		int pos; 
		int save1, save2;
		int sain;
		for (int i = 0; i < num; i++){
			scanf("%d %d.%d", &pos, &save1, &save2);
			sain = save1 * 100 + save2;
			all.push_back(make_pair(pos, sain));
		}
		sz = num+1;
		int start = 1;
		int re = tsp(0,start);
		if (re > 0){
			printf("Daniel can save $%d.%02d\n", re/100, re%100);
		}
		else
			printf("Don't leave the house\n");
		
	}
	return 0;
}
