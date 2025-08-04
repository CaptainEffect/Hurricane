#include <bits/stdc++.h> //sum of the digits of a number.
using namespace std;
int main() {
	string s;
	cin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++){
		sum=sum+s[i]-'0';
	}
	cout<<sum<<endl;
}
