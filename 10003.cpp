#include <iostream>
#include <string.h>
using namespace std;
int a[55];
int dp[55][55];
int main(){
	int l,n;
	while(true){
		cin >> l;
		if(l==0)break;
		cin >> n;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		//a[0]=0;
		a[n+1]=l;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		/*
		for(int i=0;i<n+1;i++){
			dp[i][i+1]=0;
		}
		*/
		for(int i=2;i<=n+1;i++){
			for(int j=0;j<=n+1-i;j++){
				int minval=99999999;
				for(int k=j+1;k<j+i;k++){
					if((dp[j][k]+dp[k][j+i])<minval){minval=dp[j][k]+dp[k][j+i];}
				}
				dp[j][j+i]=minval+a[j+i]-a[j];
				//cout << dp[i][j] << endl;
			}
		}
		cout << "The minimum cutting is " << dp[0][n+1] << "." << endl;
	}
}
