#include <bits/stdc++.h>
using namespace std;

int main(){
	// Initialize a stream to write the output to output file.
	ofstream output_file("181IT117_IT302_P1_Output_TC6.txt");

	// If the output file is not present, exit the program
	if (!output_file){
		cout << "No output file exists. Please create the Output file!" << endl;
		exit(1);
	}

	// Taking the input in the form of a string of characters
	string input;
	cout<<"Please Enter the Radius of the Circle"<<endl;
	cin >> input;

	// Iterating over the input string to find whether it contains only integers or not
	for (int i = 0; i < input.size(); i++){
		if (input[i] >= '0' && input[i] <= '9'){
			continue;
		}
		cout << "Invalid Input. Please enter a valid 3 digit number." << endl;
		output_file << "Invalid Input. Please enter a valid 3 digit number." << endl;
		output_file.close();
		exit(0);
	}
	
	// Converting the input string to integer radius for futher calculations
	int radius = atoi(input.c_str());
	
	// If the value of radius does not lie between 100 and 999, then it is not a valid 3 digit integer
	if (radius < 100 || radius > 999){
		cout << "Invalid Input. Please enter a valid 3 digit number" << endl;
		output_file << "Invalid Input. Please enter a valid 3 digit number" << endl;
		output_file.close();
		exit(0);
	}
	
	// Iterating over the x and y axes starting from 0 to radius-1 (1st Quadrant)
	for (int x = 0; x < radius; x++){
		for (int y = 0; y < radius; y++){
			// Checking if the point (x,y) lies inside the circle using the formula (x*x + y*y <= radius*radius)
			if ((x*x + y*y) <= radius*radius){
				cout <<"(" << x << "," << y << ")"<<" "<<","<<" ";
				output_file <<"(" << x << "," << y << ")"<<endl;
			}
		}
	}
	output_file.close();
}
