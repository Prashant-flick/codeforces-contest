#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

	int n,m,cnt=0;
	cin >> n >> m;
	int arr[n+1];
	int row[m+1]={0},col[m+1]={0},dp[m+1]={0};
	for(int i=1; i<=n; i++){
		cin >> arr[i];
		if(arr[i]<0 && -arr[i]<=m)row[-arr[i]]++;
		else if(arr[i]>0 && arr[i]<=m)col[arr[i]]++;
	}

	int ans=0;
	for(int i=1; i<=n; i++){
		if(arr[i]<0 && -arr[i]<=m)row[-arr[i]]--;
		else if(arr[i]>0 && arr[i]<=m)col[arr[i]]--;
		else{
			cnt++;
			for(int j=cnt; j>=0; j--){
				if(j==0){
					dp[j]=dp[j]+col[cnt-j];
				}else{
					dp[j]=max(dp[j-1]+row[j], dp[j]+col[cnt-j]);
				}
			}
		}
	}

	for(int i=0; i<=cnt; i++)ans=max(ans,dp[i]);

	cout << ans << endl;
}