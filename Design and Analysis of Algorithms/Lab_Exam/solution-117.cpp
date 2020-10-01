#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
void tokenize(std::string const &str, const char* delim,
            std::vector<std::string> &out);
int merge(vector<int> &nums, int l, int m, int h,int b) {
        int count=0;
        int j=m+1;
        for(int i=l;i<=m;++i) {
            while(j<=h && nums[i] > b*nums[j]) ++j;
            count += (j - (m+1));
        }
        
        vector<int> temp;
        int left=l,right=m+1;
        
        while(left<=m && right<=h) {
            if(nums[left]<=nums[right]) temp.push_back(nums[left++]);
            else temp.push_back(nums[right++]);
        }
        
        while(left<=m) temp.push_back(nums[left++]);
        
        while(right<=h) temp.push_back(nums[right++]);
        
        for(int i=l;i<=h;++i) {
            nums[i]=temp[i-l];
        }
        return count;
  }

  int mergeSort(vector<int> &nums, int l, int h,int b) {
      if(l>=h){
          return 0;
      } 
      int m=(l+h)/2;
      int count=0;
      count += mergeSort(nums,l,m,b);    
      count += mergeSort(nums,m+1,h,b);  
      count += merge(nums,l,m,h,b);      
      return count;
  }
    
  int helper(vector<int>& nums,int b) {
      return mergeSort(nums, 0, nums.size()-1,b);
  }


int countBinversions(vector<int>&A,int b) {
  int numofBinversions = 0;
  
  numofBinversions= helper(A,b);

  /* Add your code here. Define appropriate parameters and call this function from main */

  return numofBinversions;
}


int main (int argc, char * argv[]) {

  //cout << "Nu of args " << argc << argv[argc-1];

  string filename = argv[argc-1];

  string line;
  ifstream myfile (filename);

  if (myfile.is_open())
  {
    // int numTestCases = getline (myfile,line);

    getline (myfile,line);

    int numTestCases = stoi(ltrim(rtrim(line)));

    for (int i=0; i < numTestCases; i++)
    {
      std::vector<int> A;          // Vector to store the sequence of numbers
      int b;

      std::vector<string> Astr;
      const char* delim = " ";
      getline (myfile,line);
      tokenize(line, delim, Astr);
      
      cout << "Sequence is ";
      // Read in the numbers in the sequence into Vector A
      for (auto &s : Astr) {

        int i = stoi(ltrim(rtrim(s)));
        A.push_back(i);
        cout << i <<" ";

      }

      // Read in the number b
      getline (myfile,line);
      b = stoi(ltrim(rtrim(line)));

      cout << "\nB is " << b << '\n';
      

       cout<<"Number of b-inversions is: "<<countBinversions(A,b)<<endl<<endl;
    }

    cout<<endl;


    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}


/* You do not need to modify the code from here below */


void tokenize(std::string const &str, const char* delim,
            std::vector<std::string> &out)
{
    char *token = strtok(const_cast<char*>(str.c_str()), delim);
    while (token != nullptr)
    {
        out.push_back(std::string(token));
        token = strtok(nullptr, delim);
    }
}
string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

