#include<bits/stdc++.h>
using namespace std;
int main(){
	// Initialize a stream to write the output to output file.
	ofstream file("181IT117_IT302_P3_Output_TC1.txt");

	// If the output file is not present, exit the program
	if (!file){
		cout << "No output file exists. Please create the Output file!" << endl;
		exit(1);
	}
	//Taking the input of m,n and a from the user
	cout<<"Please enter the values of m,n and a"<<endl;
	int m,n,a;
	cin>>m>>n>>a;
	if(m == 0){
		cout<<"NOTE: Sir clarified in the doubt session that that m = 0 case is VALID."<<endl;
		file<<"NOTE: Sir clarified in the doubt session that that m = 0 case is VALID."<<endl;
		cout<<"Therefore the value of 0^0 will be assumed as 1 in this case"<<endl;
		file<<"Therefore the value of 0^0 will be assumed as 1 in this case"<<endl;
	}
	//Checking the values of a and n
	if(a <= 0 || n < 0 || m < 0){
		cout<<"Invalid Input. Please enter correct values."<<endl;
		file<<"Invalid Input. Please enter correct values."<<endl;
		file.close();
		exit(0);
	}
	// vector to store the intermediate results
	vector<int>intermed;
	int value = 0;
	// Adding the current values of each term and pushing them into intermediate results vector
	for(int i = 0;i<=n;i++){
		int curr_val = pow(i,m)+a;
		value+=curr_val;
		intermed.push_back(curr_val);
	}
	// Sum of all the values of f(i) is 1
	double ans = 1.0/value;
	cout<<"Intermediate Answers :"<<endl;
	file<<"Intermediate Answers :"<<endl;
	for(int i = 0;i<intermed.size();i++){
		cout<<"f("<<i<<") = c("<<intermed[i]<<")"<<endl;
		file<<"f("<<i<<") = c("<<intermed[i]<<")"<<endl;
	}
	cout<<"Sum of all values of f(x) = c("<<value<<") = 1"<<endl;
	file<<"Sum of all values of f(x) = c("<<value<<") = 1"<<endl;
	cout<<endl;
	cout<<"Final Answer :"<<endl;
	file<<"Final Answer :"<<endl;
	cout<<"The Value of c is "<<ans<<endl;
	file<<"The Value of c is "<<ans<<endl;
	file.close();
}