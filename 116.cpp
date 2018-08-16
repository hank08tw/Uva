#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdio.h>
using namespace std;
long long dp[1005][1005];
long long a[1005][1005];
int keep[1005][1005];//1:up 2:right 3:down
int n,m;
long long solve(int i,int j){
	if(dp[i][j]!=10000000000000000)return dp[i][j];
	dp[i][j]=a[i][j];
	int up=i-1;
	int mid=i;
	int down=i+1;
	if(up<1){up=n;int tmp=up;up=mid;mid=down;down=tmp;}
	if(down>n){down=1;int tmp=down;down=mid;mid=up;up=tmp;}	
	dp[i][j]+=min(min(solve(up,j+1),solve(mid,j+1)),solve(down,j+1));
	if((solve(up,j+1)<solve(mid,j+1)&&solve(mid,j+1)==solve(down,j+1))||(solve(up,j+1)==solve(mid,j+1)&&solve(mid,j+1)==solve(down,j+1))||(solve(up,j+1)==solve(mid,j+1)&&solve(mid,j+1)<solve(down,j+1))||(solve(up,j+1)==solve(down,j+1)&&solve(mid,j+1)>solve(down,j+1))||(solve(up,j+1)<solve(mid,j+1)&&solve(up,j+1)<solve(down,j+1))){
		keep[i][j]=up;
	}else if((solve(up,j+1)>solve(mid,j+1)&&solve(mid,j+1)==solve(down,j+1))||(solve(up,j+1)==solve(down,j+1)&&solve(mid,j+1)<solve(up,j+1))||(solve(up,j+1)>solve(mid,j+1)&&solve(mid,j+1)<solve(down,j+1))){
		keep[i][j]=mid;
	}else keep[i][j]=down;
	return dp[i][j];
}
int main(){
	while(~scanf("%d %d", &n, &m)){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> a[i][j];
			}
		}
		if(n==1){
			int all=0;
			for(int i=1;i<=m-1;i++){
                       		cout << 1 << " ";
				all+=a[1][i];
                	}
			cout << 1 << endl;
			all+=a[1][m];
                	cout << all << endl;
			continue;
		}
		//memset(dp,1 << 30+1,sizeof(dp));
		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){dp[i][j]=10000000000000000;}}
		for(int i=1;i<=n;i++){dp[i][m]=a[i][m];}
		int min_n=0;
		long long min_v=10000000000000000;
		for(int i=1;i<=n;i++){
			if(min_v>solve(i,1)){
				min_n=i;
				min_v=solve(i,1);
			}
		}
		//cout << endl;
		/*
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){cout << keep[i][j] << " ";}cout << endl;
		}*/
		//cout << endl;
		for(int i=1;i<m;i++){
			cout << min_n << " ";
			min_n=keep[min_n][i];
			/*
			switch(keep[min_n][i]){
				case 1:{min_n-=1;if(min_n<1){min_n=n;}break;}
				case 2:{break;}
				case 3:{min_n+=1;if(min_n>n){min_n=1;}break;}
			}*/
		}
		cout << min_n << endl;
		cout << min_v << endl;
	}
}
