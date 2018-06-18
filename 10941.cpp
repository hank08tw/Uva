#include <iostream>
using namespace std;
#include <iomanip>
int main(){
	double a,b,c;
	while(cin >> a){
		cin >> b;
		cin >> c;
		cout << fixed << setprecision(5) << (a*b+b*(b-1))/((a+b)*(a+b-c-1)) << endl;
	}
}
