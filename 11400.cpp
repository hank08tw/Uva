#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
struct s{int v;int k;int c;int l;};
s ss[1005];
int dp[1005];
int sum[1005];
using namespace std;
bool cmp(s s1,s s2){
	return s1.v<s2.v;
}
int main(){
	int n;
	while(true){
		cin >> n;
		if(n==0)break;
		for(int i=1;i<=n;i++){
			cin >> ss[i].v >> ss[i].k >> ss[i].c >> ss[i].l;
		}
		sort(ss+1,ss+n+1,cmp);
		sum[1]=ss[1].l;
		for(int i=2;i<=n;i++){sum[i]=sum[i-1]+ss[i].l;}
		for(int i=1;i<=n;i++){
			dp[i]=ss[i].k+sum[i]*ss[i].c;
			for(int j=1;j<i;j++){
				dp[i]=min(dp[i],dp[j]+(sum[i]-sum[j])*ss[i].c+ss[i].k);
			}
		}
		cout << dp[n] << endl;
	}
}
