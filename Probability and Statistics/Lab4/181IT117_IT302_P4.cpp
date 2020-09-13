#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(string s){
	for(auto i:s){
		if(i<'0'||i>'9')
			return 0;
	}
	return 1;
}

ll com(int n,int r){
	ll num=1,den=1;
	for(int i=1;i<=r;i++){
		num*=n;
		n--;
		den*=i;
	}
	return num/den;
}

ll cal(int n,int x,int y,int z,int i,int j){
	int ans=(com(x,i)*com(y,j)*com(z,n-i-j));
	return ans;
}

int main(){
	// Initialize a stream to write the output to output file.
	ofstream file("181IT117_IT302_P4_Output_TC6.txt");

	// If the output file is not present, exit the program
	if (!file){
		cout << "No output file exists. Please create the Output file!" << endl;
		exit(1);
	}
	string a,b,c,d;
	cout<<"Please enter the values of N, X, Y and Z: "<<endl;
	cin>>a>>b>>c>>d;
	bool invalid=0;
	if(!check(a) || !check(b) || !check(c) || !check(d)){
		cout<<"Invalid Input. Please enter correct values."<<endl;
		file<<"Invalid Input. Please enter correct values."<<endl;
		file.close();
		exit(0);
	}
	ll n = stoi(a), x = stoi(b), y = stoi(c), z = stoi(d);

	if(n>x+y+z){
		cout<<"Invalid Input. Please enter correct values."<<endl;
		file<<"Invalid Input. Please enter correct values."<<endl;
		file.close();
		exit(0);
	}

	ll tot=com(x+y+z,n);
	vector<int>g(n+1,0),h(n+1,0);
	cout<<"\nIntermediate Results:\n";
	file<<"\nIntermediate Results:\n";
	cout<<"Total number of ways of selecting "<<n<<" pens = "<<tot<<'\n';
	cout<<"Joint Probability Distribution for f(x,y):\n";
	file<<"Total number of ways of selecting "<<n<<" pens = "<<tot<<'\n';
	file<<"Joint Probability Distribution for f(x,y):\n";
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			ll num=0;
			if(i+j<=n)
				num=cal(n,x,y,z,i,j);
			g[j]+=num;
			h[i]+=num;
			cout<<"f("<<i<<","<<j<<")= "<<num<<"/"<<tot<<"= "<<1.0*num/tot<<'\n';
			file<<"f("<<i<<","<<j<<")= "<<num<<"/"<<tot<<"= "<<1.0*num/tot<<'\n';
		}
	}
	
	cout<<"\nMarginal Probabilities:\n";
	cout<<"For X :\n";
	file<<"\nMarginal Probabilities:\n";
	file<<"For X :\n";
	for(int i=0;i<=n;i++){
		cout<<"h("<<i<<")="<<h[i]<<"/"<<tot<<'\n';
		file<<"h("<<i<<")="<<h[i]<<"/"<<tot<<'\n';
	}
	cout<<"\nFor Y :\n";
	file<<"\nFor Y :\n";
	for(int i=0;i<=n;i++){
		cout<<"g("<<i<<")="<<g[i]<<"/"<<tot<<'\n';
		file<<"g("<<i<<")="<<g[i]<<"/"<<tot<<'\n';
	}
	cout<<"\nJoint probability function: f(x,y)=C("<<x<<",x)*C("<<y<<",y)*C("<<z<<","<<n<<"-x-y)/C("<<x+y+z<<","<<n<<")\n";
	file<<"\nJoint probability function: f(x,y)=C("<<x<<",x)*C("<<y<<",y)*C("<<z<<","<<n<<"-x-y)/C("<<x+y+z<<","<<n<<")\n";
	file.close();
}