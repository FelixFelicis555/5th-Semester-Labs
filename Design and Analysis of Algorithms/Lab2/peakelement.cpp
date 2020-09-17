#include<bits/stdc++.h>
using namespace std;

int go(int a[],int l, int r,int n){
	if(l > r)
		return -1;
		int mid = l + (r-l)/2;
		if ((mid == 0 || a[mid - 1] <= a[mid]) && (mid == n - 1 || a[mid + 1] <= a[mid])) 
        	return a[mid]; 
		else if(a[mid] < a[mid-1])
			return go(a,l,mid-1,n);
		else
			return go(a,mid+1,r,n);	
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	int ans = go(a,0,n-1,n);
	cout<<ans;
}