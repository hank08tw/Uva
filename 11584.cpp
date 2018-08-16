#include <iostream>
#include <string>
#include <cstring>
using namespace std;
bool is[1005][1005];
int dp[1005];
int t;
int main(){
	string tmp;
	cin >> t;
	while(t--){
		cin >> tmp;
		//cout << "tmp" << endl;
		memset(is,false,sizeof(is));
		//字母當中心
		for(int i=0;i<tmp.length();i++){
			//cout << "in1";
			is[i][i]=true;
			int left=i-1;
                        int right=i+1;
                        while(left>=0&&right<tmp.length()){
				//cout << "in2" << endl;
                                if(tmp[left]==tmp[right])is[left--][right++]=true;
                                else break;
                        }
		}
		//cout << "1" << endl;
		//空隙當中心
		for(int i=0;i<tmp.length()-1;i++){
			if(tmp[i]==tmp[i+1])is[i][i+1]=true;
			int left=i-1;
			int right=i+2;
			while(left>=0&&right<tmp.length()){
				if(tmp[left]==tmp[right])is[left--][right++]=true;
				else break;
			}
		}
		//cout << "2" << endl;
		dp[0]=0;
		for(int i=1;i<tmp.length();i++){
			if(is[0][i])dp[i]=0;
			else{
				int min_v=2147483647;
				for(int j=1;j<=i;j++){
					//cout << "in" << endl;
					if(is[j][i]){
						min_v=min(min_v,dp[j-1]+1);
					}
				}
				dp[i]=min_v;
			}
		}
		cout << dp[tmp.length()-1]+1 << endl;
	}
}
