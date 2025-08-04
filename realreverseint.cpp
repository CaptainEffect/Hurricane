#include <bits/stdc++.h> //reverse babe 2.0 (beautiful logic)
using namespace std;
int main() {
	string s;
	cin>>s;
	int c=0;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]!='0') break;
		c++;
	}
	int m = stoi(s)/pow(10,c);
	s=to_string(m);
	for(int i=s.size()-1;i>=0;i--){
		cout<<s[i]-'0';
	}
}
