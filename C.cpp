#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
#define fromgoto(from,to,i) for(int i=(from),__to=(to);i<=__to;++i)
typedef long long LL;
const int MAXN = 100008;
int A[MAXN];
vector<int> G[MAXN];
LL C[MAXN];
LL sum[MAXN];
LL cnt[MAXN];
void calsum(int u,LL res) {
	sum[u] = res;
	fromgoto(0,G[u].size()-1,i) {
		calsum(G[u][i],max(C[G[u][i]],res + C[G[u][i]]));
	}
}
LL calcnt(int u) {
	cnt[u] = 1;
	fromgoto(0,G[u].size()-1,i) {
		cnt[u] += calcnt(G[u][i]);
	}
	return cnt[u];
}
LL del_cnt;
void calres(int u) {
	if(A[u]<sum[u]) {
		del_cnt+=cnt[u];
		return;
	}
	fromgoto(0,G[u].size()-1,i) {
		calres(G[u][i]);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	fromto(1,n,i) scanf("%I64d",&A[i]);
	fromto(2,n,i) {
		int p;
		scanf("%d%I64d",&p,&C[i]);
		G[p].push_back(i);
	}
	memset(sum,0,sizeof(sum));
	calsum(1,0);
	calcnt(1);
	del_cnt = 0;
	calres(1);
	printf("%d\n",del_cnt);
	return 0;
}
