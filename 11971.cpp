#include <iostream>
#include <math.h>
using namespace std;
unsigned long long gcd(unsigned long long a,unsigned long long b){
	if(!b){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	unsigned long long t,n,k;
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n >> k;
		unsigned long long a=pow(2,k)-(k+1),b=pow(2,k);
		a/=gcd(a,b);
		b/=gcd(a,b);
		cout << "Case #" << i << ": " << a << "/" << b << endl;
	}
}
