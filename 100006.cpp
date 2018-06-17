#include <iostream>
using namespace std;
typedef long long ll;
ll mod_pow(ll x,ll n, ll mod){
	if(n==0)return 1;
	ll tmp=mod_pow(x*x%mod,n/2,mod);
	//tmp=(tmp*tmp);
	if(n%2==1)return (tmp*x)%mod;
	return tmp%mod;
}
int main(){
	ll n;
	//cout << mod_pow(3,3,1000) << endl;
	while(cin >>n){
		if(n==0)break;
		bool ans=true;
		for(ll i=2;i<n;i++){
			if(mod_pow(i,n,n)%n!=i){
				cout << n << " is normal." << endl;
				ans=false;
				break;
			}
		}
		if(ans){
			cout << "The number " << n << " is a Carmichael number." << endl;
		}
	}
}
