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
	ofstream file("181IT117_IT302_P6_Output_TC1.txt");

	// If the output file is not present, exit the program
	if (!file){
		cout << "No output file exists. Please create the Output file!" << endl;
		exit(1);
	}
	string a,b,c,d;
	cout<<"Please enter the values of m, n, o and a: "<<endl;
	cin>>a>>b>>c>>d;
	bool invalid=0;
	if(!check(a) || !check(b) || !check(c) || !check(d)){
		cout<<"Invalid Input. Please enter correct values."<<endl;
		file<<"Invalid Input. Please enter correct values."<<endl;
		file.close();
		exit(0);
	}
	ll n = stoi(d), x = stoi(a), y = stoi(b), z = stoi(c);

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
	cout<<"Total number of ways of selecting "<<n<<" fruits = "<<tot<<'\n';
	cout<<"Joint Probability Distribution for f(x,y):\n";
	file<<"Total number of ways of selecting "<<n<<" fruits = "<<tot<<'\n';
	file<<"Joint Probability Distribution for f(x,y):\n";
	
	double exy = 0,ux = 0, uy = 0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n && i+j <= n;j++){
			ll num=0;
			if(i+j<=n)
				num=cal(n,x,y,z,i,j);
			g[j]+=num;
			h[i]+=num;

			cout<<setw(5)<<"f("<<i<<","<<j<<")= "<<fixed<<setprecision(4)<<1.0*num/tot;
			file<<setw(5)<<"f("<<i<<","<<j<<")= "<<fixed<<setprecision(4)<<1.0*num/tot;
			exy += i*j*(1.0*num/tot);
		}
		cout<<endl;
		file<<endl;
	}
	
	cout<<"\nMarginal Probabilities:\n";
	cout<<"For X :\n";
	file<<"\nMarginal Probabilities:\n";
	file<<"For X :\n";
	for(int i=0;i<=n;i++){
		cout<<setw(5)<<"g("<<i<<")= "<<fixed<<setprecision(4)<<1.0*h[i]/tot;
		file<<setw(5)<<"g("<<i<<")= "<<fixed<<setprecision(4)<<1.0*h[i]/tot;
		ux += i*(1.0*h[i]/tot);
	}
	cout<<"\n\nFor Y :\n";
	file<<"\n\nFor Y :\n";
	for(int i=0;i<=n;i++){
		cout<<setw(5)<<"h("<<i<<")= "<<fixed<<setprecision(4)<<1.0*g[i]/tot;
		file<<setw(5)<<"h("<<i<<")= "<<fixed<<setprecision(4)<<1.0*g[i]/tot;
		uy += i*(1.0*g[i]/tot);
	}
	cout<<"\n\nExpected Value E(XY) = "<<exy<<endl<<"\nMean of x uX = "<<ux<<endl<<"\nMean of y uY = "<<uy<<endl;
	file<<"\n\nExpected Value E(XY) = "<<exy<<endl<<"\nMean of x uX = "<<ux<<endl<<"\nMean of y uY = "<<uy<<endl;

	cout<<"\n\nFinal Result:"<<endl;
	file<<"\n\nFinal Result:"<<endl;
	cout<<"Cov(X,Y) = E(XY) - uXuY = "<<exy - ux*uy<<endl;
	file<<"Cov(X,Y) = E(XY) - uXuY = "<<exy - ux*uy<<endl;
	file.close();
}