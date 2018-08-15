#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#define N 31
int n;
int a[N];
int b[N];
int c[N];
int dp[N][3];
using namespace std;
long long solve(int index,int num){
	if(dp[index][num]!=-1)return dp[index][num];
	int one,two;
	if(num==0){
		one=b[index];two=c[index];dp[index][num]=a[index];
	}else if(num==1){
		one=a[index];two=c[index];dp[index][num]=b[index];
	}else{one=a[index];two=b[index];dp[index][num]=c[index];}
	long long max_val=0;
	for(int i=0;i<n;i++){
		if((one<b[i]&&two<c[i])||(one<c[i]&&two<b[i])){
			max_val=max(max_val,solve(i,0));
		}
                if((one<a[i]&&two<c[i])||(one<c[i]&&two<a[i])){
                        max_val=max(max_val,solve(i,1));
                }
                if((one<a[i]&&two<b[i])||(one<b[i]&&two<a[i])){
                        max_val=max(max_val,solve(i,2));
                }
	}
	dp[index][num]+=max_val;
	return dp[index][num];
	
}
int main(){
	int t=1;
	while(true){
		cin >> n;
		if(n==0)break;
		for(int i=0;i<n;i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		memset(dp,-1,sizeof(dp));
		long long ans=0;
		for(int i=0;i<n;i++){
			ans=max(solve(i,0),ans);
			ans=max(solve(i,1),ans);
			ans=max(solve(i,2),ans);
		}
		cout << "Case " << t++ << ": maximum height = " << ans << endl;
	}
}
