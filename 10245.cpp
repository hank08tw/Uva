#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <cstdio>
using namespace std;
struct point{
	double x,y;
};
point p[100005];
bool cmp(point a,point b){
	return a.x < b.x;
}
double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double closest(int a,int b){
	int mid=(a+b)/2;
	if(a>b)return 2147483647;
	double d=min(closest(a,mid-1),closest(mid+1,b));
	int l=mid,r=mid;
	while(a<=l&&d>p[mid].x-p[l].x)l--;
	while(r<=b&&d>p[r].x-p[mid].x)r++;
	for(int i=l+1;i<r;i++){
		for(int j=i+1;j<r;j++){
			if(abs(p[j].y-p[i].y)>=d)continue;
			d=min(d,dist(p[i],p[j]));
		}
	}
	return d;
}
int main(){
	int t;
	while(cin >> t){
		if(t==0)break;
		for(int i=0;i<t;i++){
			cin >> p[i].x >> p[i].y;
		}		
		sort(p,p+t,cmp);
		double n=closest(0,t-1);
		if(n>=10000)printf("INFINITY\n");
		else printf("%.4lf\n",n);;
	}
	return 0;
}
