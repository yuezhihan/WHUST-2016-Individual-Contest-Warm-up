#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
bool vis[13];
int zb[10][2] = {{2,4},{1,1},{1,2},{1,3},{2,1},{2,2},{2,3},{3,1},{3,2},{3,3}};
int main()
{
	int n;
	scanf("%d",&n);
	
	memset(vis,false,sizeof(vis));
	fromto(1,n,i) {
		char ch;
		scanf(" %c",&ch);
		vis[ch-'0'] = true;
	}
	if(vis[0]) {
		if(vis[1] || vis[2] || vis[3]) printf("YES\n");
		else printf("NO\n");
		return 0;
	}
	int top = 3,bottom = 1,left = 3,right = 1;
	fromto(1,9,i) if(vis[i]) {
		top = min(top,zb[i][0]);
		bottom = max(bottom,zb[i][0]);
		left = min(left,zb[i][1]);
		right = max(right,zb[i][1]);
	}
	if(top == 1 && bottom == 3 && left == 1 && right == 3) {
		if(vis[8] && (!vis[7] && !vis[9])) printf("NO\n");
		else printf("YES\n");
	} else printf("NO\n");
	return 0;
}
