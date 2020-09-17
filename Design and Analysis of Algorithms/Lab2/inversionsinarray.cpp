#include<bits/stdc++.h>
using namespace std;

int merge(int a[],int l,int mid, int r){
	int i = l, j = mid, k = l;
	int ans = 0;
	while((i <= mid-1)&&j<=r){
		if(a[i] <= a[j]){
			k++;
			i++;
		}
		else{
			k++;
			j++;
			ans += (mid-i);
		}

	}
	return ans;
}

int go(int a[],int l, int r, int n){
	int mid,c = 0;
	if(r > l){
		mid = l+(r-l)/2;
		c += go(a,l,mid,n);
		c += go(a,mid+1,r,n);
		c += merge(a,l,mid+1,r);

	}
	return c;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	int ans = go(a,0,n-1,n);
	cout<<ans<<endl;
	return 0;
}