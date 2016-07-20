#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
char S[MAXN],T[MAXN];
int F[MAXN][MAXN][11][2];

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",S+1,T+1);
	fromto(1,n,i) fromto(1,m,j) {
		if(S[i]==T[j]) fromto(1,k,l)
			F[i][j][l][0] = max(F[i-1][j-1][l][0],F[i-1][j-1][l-1][1]) + 1;
		fromto(1,k,l)
			F[i][j][l][1] = max(max(F[i-1][j-1][l][1],F[i-1][j][l][1]),max(F[i][j-1][l][1],F[i][j][l][0]));
	}
	printf("%d\n",F[n][m][k][1]);
	return 0;
}
