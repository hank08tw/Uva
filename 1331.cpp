#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define MAX 51
using namespace std;
int t,n;
double dp[MAX][MAX];
int x[MAX];
int y[MAX];
double thearea[MAX][MAX][MAX];
double dist(int first,int second){
	return sqrt(((double)x[first]-(double)x[second])*((double)x[first]-(double)x[second])+((double)y[first]-(double)y[second])*((double)y[first]-(double)y[second]));
}
double area(int first,int second,int third){
	double a=dist(first,second);
	double b=dist(second,third);
	double c=dist(first,third);
	double p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
//檢查這個a,b,c可不可以剖分有沒有包括到外面的區域 如果是凹多邊形有些地方不能剖分  有問題????AC???
bool check(int a, int b, int c)
{
     int i;
     for (i = 1; i <= n; i++)
     {
         if (i == a || i == b || i == c) continue;
         double d = area(a, b, i) + area(a, c, i) + area(b, c, i) - area(a, b, c);
         if (d<0) d = -d;
         if (d <= 0.01) return 0;
     }
     return 1;
}
int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> x[i] >> y[i];
		}
		//cout << area(1,3,2) << endl;
		/*
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;j<=n;j++){
					thearea[i][j][k]=area(i,j,k);
				}
			}
		}*/
		for(int i=1;i<n;i++){
			dp[i][i+1]=0;
		}
		
		for(int i=2;i<=n-1;i++){//長度
			for(int j=1;j<=n-i;j++){//起點
				dp[j][j+i]=21467483647;
				for(int k=j+1;k<j+i;k++){
					//cout <<"j:" << j << " j+i:"<< j+i << "k:" << k << area(i+j,j,k) << endl;
					if(check(j,j+i,k))dp[j][j+i]=min(dp[j][j+i],max(max(dp[j][k],dp[k][j+i]),area(j,j+i,k)));
				}
			}
		}/*
		cout << endl;
		for(int i=1;i<=n-1;i++){//長度
                        for(int j=i+1;j<=n;j++){
               			cout << i << " " << j << " " << dp[i][j] << endl;
                        }
                }
*/
		printf("%.1lf\n",dp[1][n]);
	}
}
