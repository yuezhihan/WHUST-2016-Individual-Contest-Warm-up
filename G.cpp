#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
typedef long long LL;
LL M;
LL f(LL x) {
	LL res = 0;
	for(LL k = 2;x>=k*k*k;++k) {
		res += x/(k*k*k);
	}
	return res;
}
bool func(LL x) {
	return f(x)>=M;
}

LL binary_d(LL L,LL r,bool func(LL)) 
{
	while(L<r) {
		LL m=L+(r-L)/2;
		if(func(m)) r = m;
		else L = m + 1;
	}
	return L;
}
int main()
{
	scanf("%I64d",&M);
	LL res = binary_d(1,LONG_LONG_MAX,func);
	if(f(res)!=M) printf("-1\n");
	else printf("%I64d\n",res);
	return 0;
}
