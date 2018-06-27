#include <iostream>
#include <string.h>
#include <memory.h>
using namespace std;
int N,T,m1,m2;
int t[51];
int d[55];
int e[55];
bool has_train[251][51][2];
long long dp[201][51];

int main(){
	int C=1;
	while(true){
	memset(has_train,false,sizeof(has_train));
	
	cin >> N;
	if(N==0)break;
	cin >> T;
	dp[T][N]=0;
	for(int i=1;i<N;i++)dp[T][i]=2147483647;
	for(int i=1;i<=N-1;i++){
		cin >> t[i];
	}
	cin >> m1;
	for(int i=1;i<=m1;i++){
		cin >> d[i];
	}
	cin >> m2;
	for(int i=1;i<=m2;i++){
		cin >> e[i];
	}
	for(int i=1;i<=m1;i++){
		has_train[d[i]][1][0]=true;
		int time=d[i];
		for(int j=2;j<=N;j++){
			time+=t[j-1];
			if(time>T)break;
			has_train[time][j][0]=true;
		}
	}
	for(int i=m2;i>=1;i--){
		has_train[e[i]][N][1]=true;
		int time=e[i];
		for(int j=N-1;j>=1;j--){
			time+=t[j];
			if(time>T)break;
			has_train[time][j][1]=true;
		}
	}
	for(int i=T-1;i>=0;i--){
		for(int j=1;j<=N;j++){
			dp[i][j]=dp[i+1][j]+1;//多等一分鐘
			if(j<N&&has_train[i][j][0]&&i+t[j]<=T)dp[i][j]=min(dp[i+t[j]][j+1],dp[i][j]);//往右
			if(j>1&&has_train[i][j][1]&&i+t[j-1]<=T)dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);//往左
		}
	}
	
	cout << "Case Number " << C++ << ": ";
	if(dp[0][1]>=2147483647)cout << "impossible\n";
	else cout << dp[0][1] << endl;
	}
		
}
