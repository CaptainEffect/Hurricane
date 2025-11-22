#include <bits/stdc++.h>
using namespace std;
/*By captainkhan*/

/*logic is that qi or pi always will be integers, and y = x + pi , y = -x + qi
will give x = (qi - pi)/2 and so we can say that we want pair of qi and pi such that
the difference between the two will be divisible by 2 despite of whatsoever the sign
but rather than stupidly looping of O(n^2) complexity; we can simply find the number of
odd and even numbers in both qi and pi queue which will have O(n) and we know since 
pi , qi are int so, the difference is also an int, and we know that odd -/+ odd and even -/+ even
gives an even number, and so say we have 1 3 2 and 0 3 then po = 2 , pe = 1 , qo = 2 , qe = 1
and say we have left numbers as a,b and right numbers as c,d then their possible combinations 
i.e (a,c) , (a,d) , (b,c) , (b,d) and these combination number we can find as no. of left numbers
multiplied to no. of right numbers and similarly po*qo + pe*qe will be the required answer since,
we need odd numbers combination with odd number which can make even difference, 
and similarly we need even number combination with even number which can make even difference.*/

int main() {
	int t; cin >> t;
	while(t--){
		long long po = 0 , pe = 0 , qo = 0 , qe = 0; 
		long long n; cin >> n;

		vector<long long> wow(n);
		for(long long i = 0; i < n; i++){
			cin >> wow[i];
			if(wow[i] % 2 == 0) pe++;
			else if(wow[i] % 2 != 0) po++;
		}
		long long m; cin >> m;
		vector<long long> owo(m);
		
		for(long long i = 0; i < m; i++){
			cin >> owo[i];
			if(owo[i] % 2 == 0) qe++;
			else if(owo[i] % 2 != 0) qo++;
		}
		cout << ((po * qo) + (pe * qe)) << "\n";
	}
}
