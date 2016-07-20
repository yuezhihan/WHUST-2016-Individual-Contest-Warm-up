#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n>m) swap(n,m);
	long long res = 0;
	for(int k = 5; k <= n + m; k += 5) {
		if(k-1 <= n) res+=k-1;
		else if(m <= k-1) res+=n+m-k+1;
		else if(n<=k-1 && k-1<=m) res+=n;
	}
	printf("%I64d\n",res);
	return 0;	
}
