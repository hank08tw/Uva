#include <iostream>
using namespace std;
char c[105][105];
int main(){
	int w,h;
	
	while(cin >> h >> w){
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin >> c[i][j];
		}
	}
	double ans=0;
	for(int i=1;i<=h;i++){
		bool even=true;
		for(int j=1;j<=w;j++){
			if(c[i][j]=='/'||c[i][j]=='\\'){ans+=0.5;even=!even;}
			else{
				if(!even)ans+=1;
			}
		}
	}
	cout << ans << endl;}
}
