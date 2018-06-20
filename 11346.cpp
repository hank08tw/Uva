#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
	int t;
	long double a,b,s;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> a >> b >> s;
		if(s>=a*b){
			cout << "0.000000%" << endl;
		}else if(s<0.0000001){
			cout << "100.000000%" << endl;
		}else{
			long double tmp=(a*b-s-s*log(a*b/s))/(a*b);
			cout << fixed << setprecision(6) << tmp*100 << "%" << endl;
		}
	}
}
