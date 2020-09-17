#include<bits/stdc++.h>
using namespace std;

void go(int n, char s, char t, char i){
	if(n <= 0)
		return;
	go(n-1,s,i,t);
	cout<<"Move disc "<<n<<" from peg "<<s<<" to peg "<<t<<endl;
	go(n-1,i,t,s);
}
int main(){
	int n;
	cin>>n;
	char s = 'S',i = 'I',t = 'T';
	go(n,s,t,i);
	return 0;
}