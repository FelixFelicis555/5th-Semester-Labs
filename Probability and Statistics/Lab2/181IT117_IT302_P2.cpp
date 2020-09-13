#include <bits/stdc++.h>
using namespace std;

int main(){
	// Initialize a stream to write the output to output file.
	ofstream file("181IT117_IT302_P2_Output_TC1.txt");

	// If the output file is not present, exit the program
	if (!file){
		cout << "No output file exists. Please create the Output file!" << endl;
		exit(1);
	}
	
	// Take the input of number of Inspectors
	int num;
	cout << "Please Enter the Number of Inspectors: ";
	cin >> num;
	
	// Take the name of reqd Inspector as input
	int ind = -1;
	string name;
	cout << "Please Enter the name of the required Inspector: ";
	cin >> name;

	// Take the names of all inspectors as input
	string str;
	cout << "Please Enter the names of all " << num << " Inspectors: " << endl;
	for (int a = 0; a < num; a++){
		cin >> str;
		// Check if the required inspector is present or not
		if (name == str){
			ind = a;
		}
	}
	
	// If the inspector doesn't exist, Exit the program
	if(ind == -1){
		cout<<"Invalid Input. The required inspector does not exist"<<endl;
		file<<"Invalid Input. The required inspector does not exist"<<endl;
		file.close();
		exit(0);
	}

	int percent[num], fail[num];
	int sum = 0;
	// Take the input of percentages
	cout << "Please Enter " << num << " percentages in the correct order: " << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> str;
		// Truncating the string to remove the % sign
		if (str[str.size()-1] == '%'){
			str = str.substr(0, str.size()-1);
		}
		// Converting String to Integer
		percent[i] = atoi(str.c_str());
		sum+= percent[i];
	}
	
	// Check if sum of all percentages is 100 or not
	if (sum != 100){
		cout << "Invalid Input. Please enter valid percentages" << endl;
		file << "Invalid Input. Please enter valid percentages" << endl;
		file.close();
		exit(0);
	}
	
	// Initialize total probability to 0
	long double totalprob = 0;
	// Take the input of Fail Rates
	cout << "Please Enter the " << num << " fail rates in correct order: " << endl;
	for (int i = 0; i < num; i++){
		cin >> fail[i];
		// Add the value of Percentage/Failure_Rate to Total Prob
		totalprob += 1.0*percent[i]/fail[i];
	}

	cout<<"Intermediate Answers :"<<endl;
	file<<"Intermediate Answers :"<<endl;
	cout << "P(Fail/" << name << "): " << 1.0/fail[ind] << endl;
	file << "P(Fail/" << name << "): " << 1.0/fail[ind] << endl;
	cout << "P(" << name << "): " << percent[ind]/100.0 << endl;
	file << "P(" << name << "): " << percent[ind]/100.0 << endl;
	cout << "P(Fail): " << totalprob << endl;
	file << "P(Fail): " << totalprob << endl;
	cout<<endl;
	file<<endl;
	cout<<"Final Answer :"<<endl;
	file<<"Final Answer :"<<endl;
	cout << "P(" << name << "/Fail): " << 1.0/fail[ind] * percent[ind] / totalprob << endl;
	file << "P(" << name << "/Fail): " << 1.0/fail[ind] * percent[ind] / totalprob << endl;
	file.close();
}
