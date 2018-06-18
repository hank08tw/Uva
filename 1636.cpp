#include <iostream>
#include <string.h>
using namespace std;
int main(){
	string s;
	while(cin >> s){
		int a=0;
		int b=0;
		for(int i=0;i<=s.length()-2;i++){
			if(s[i]=='0'&&s[i+1]=='0')a++;
			if(s[i]=='0')b++;
		}
		if(s[s.length()-1]=='0')b++;
		if(s[s.length()-1]=='0'&&s[0]=='0')a++;
		if(a*s.length()>b*b)cout << "SHOOT" << endl;
		else if(a*s.length()==b*b)cout << "EQUAL" << endl;
		else cout << "ROTATE" << endl;
	}
}
