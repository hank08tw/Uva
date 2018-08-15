//WA
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
#define N 1005
double x[N];
double y[N];
double dp[N][N];
using namespace std;
double dist(int first,int second){
	return sqrt((x[first]-x[second])*(x[first]-x[second])+(y[first]-y[second])*(y[first]-y[second]));
}
double solve(int first,int second){
	if(dp[first][second]!=0){/*cout << first << " return " << second << " " <<dp[first][second] << endl;*/return dp[first][second];}
	return dp[first][second]=min(solve(first+1,second)+dist(first,first+1),solve(first+1,first)+dist(second,first+1));
	//cout << first << " " <<second << " " <<dp[first][second] << endl;
}
int main(){
	int n;
	while(cin >> n){
		if(n==1){cout << "0.00" << endl;continue;}
		if(n==2){printf("%.2lf",dist(1,2));continue;}
		for(int i=1;i<=n;i++){
			cin >> x[i] >> y[i];
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<n-1;i++){
			dp[n-1][i]=dist(n,n-1)+dist(i,n);
		}
		double ans=solve(1,1);//solve(2,1)+dist(1,2);
		printf("%.2lf\n",dp[2][1]+dist(1,2));
	}
}
