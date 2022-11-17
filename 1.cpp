#include<bits/stdc++.h>
using namespace std;

int iterativeFibonacci(int n){

	if(n<=1) return n;

	int a=0, b=1;
	int c=1;

	for(int i=2; i<n; i++){
		a = b;
		b = c;
		c = a+b;
	}	
	return c;
}

int recursiveFibonacii(int n){
	
	if(n<=1){
		return n;
	}
	return (recursiveFibonacii(n-1)+recursiveFibonacii(n-2));

}

int main(){

	int n;
	cin>>n;
	cout<<iterativeFibonacci(n)<<endl;

	cout<<recursiveFibonacii(n);
	

}

// Fibonacci as O(2^n) 
//T(n) = O(1.6180)^n
// This is the tight upper bound
//space on
