#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <cstdio>
#define MY_INT_MAX -1
using namespace std;
int t;
char a[5001];
char b[5001];
int dp[5001][5001];
int c[5001][5001];
int astringstart[26];
int astringend[26];
int bstringstart[26];
int bstringend[26];
//一定要用bottom up迴圈 不能用top down遞歸因為topdown要多一次memset
int solve_count(int n,int m){
	if(dp[n][m]!=MY_INT_MAX)return dp[n][m];
	if(n==0){/*cout << "n:" << n << "m:" << m << "NUM" << solve_count(0,m-1)+c[0][m] << "IN" << endl;*/return dp[n][m]=solve_count(0,m-1)+c[0][m];}
	if(m==0){/*cout << "n:" << n << "m:" << m << "NUM" << solve_count(n-1,0)+c[n][0] << "IN" << endl;*/return dp[n][m]=solve_count(n-1,0)+c[n][0];}
	return dp[n][m]=min(solve_count(n-1,m),solve_count(n,m-1))+c[n][m];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	scanf("%d",&t);
	while(t--){
		scanf("%s",a);
		scanf("%s",b);
		int n=strlen(a);
		int m=strlen(b);
		memset(astringstart,MY_INT_MAX,sizeof(astringstart));
		memset(bstringstart,MY_INT_MAX,sizeof(bstringstart));
		memset(astringend,MY_INT_MAX,sizeof(astringend));
		memset(bstringend,MY_INT_MAX,sizeof(bstringend));
		//memset(dp,MY_INT_MAX,sizeof(dp));
		for(int i=0;i<n;i++){
			if(astringstart[a[i]-'A']==MY_INT_MAX){astringstart[a[i]-'A']=i;}
			else{
				astringend[a[i]-'A']=i;
			}
		}
		for(int i=0;i<26;i++){
			if(astringend[i]==MY_INT_MAX&&astringstart[i]!=MY_INT_MAX){
				astringend[i]=astringstart[i];
			}
		}
		for(int i=0;i<m;i++){
                        if(bstringstart[b[i]-'A']==MY_INT_MAX){bstringstart[b[i]-'A']=i;}
                        else{
                                bstringend[b[i]-'A']=i;
                        }
                }
		for(int i=0;i<26;i++){
                        if(bstringend[i]==MY_INT_MAX&&bstringstart[i]!=MY_INT_MAX){
                                bstringend[i]=bstringstart[i];
                        }
                }/*
		for(int i=0;i<26;i++){
			cout << astringstart[i] << " " << astringend[i] << " " << bstringstart[i] << " " << bstringend[i] << endl;
		}*/
		c[0][0]=0;
		for(int i=1;i<=n;i++){
			c[i][0]=0;
			for(int k=0;k<26;k++){
                                if(astringstart[k]!=MY_INT_MAX){
                                                if(i-1>=astringstart[k]&&(i-1<astringend[k]||bstringstart[k]!=-1)){
                                                        c[i][0]++;
                                                }
				}
                        }
		}
		for(int i=1;i<=m;i++){
			c[0][i]=0;
			for(int k=0;k<26;k++){
                                if(bstringstart[k]!=MY_INT_MAX){
                                                if(i-1>=bstringstart[k]&&(i-1<bstringend[k]||astringstart[k]!=-1)){
                                                        c[0][i]++;
                                                }
                                }
                        }
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				c[i][j]=0;
				for(int k=0;k<26;k++){
					if(astringstart[k]!=MY_INT_MAX&&bstringstart[k]!=MY_INT_MAX){
						if((i-1>=astringstart[k]&&j-1<bstringstart[k])||(j-1>=bstringstart[k]&&i-1<astringstart[k])||((i-1>=astringstart[k]&&j-1>=bstringstart[k]&&(i-1<astringend[k]||j-1<bstringend[k])))){
							c[i][j]++;
						}
					}else if(astringstart[k]!=-1&&bstringstart[k]==-1){
						if(i-1>=astringstart[k]&&i-1<astringend[k]){
                                                        c[i][j]++;
                                                }
					}else if(astringstart[k]==-1&&bstringstart[k]!=-1){
						if(j-1>=bstringstart[k]&&j-1<bstringend[k]){
							c[i][j]++;
						}
					}
				}
			}
		}
		dp[0][0]=0;
		for(int i=1;i<=n;i++){
			dp[i][0]=dp[i-1][0]+c[i][0];
		}
		for(int i=1;i<=m;i++){
			dp[0][i]=dp[0][i-1]+c[0][i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=min(dp[i-1][j],dp[i][j-1])+c[i][j];
			}
		}
		printf("%d\n",dp[n][m]);
		//printf("%d\n",solve_count(n,m));
	}
}
