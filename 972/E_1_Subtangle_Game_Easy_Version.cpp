#include<bits/stdc++.h>
using namespace std;

const int N = 1500;
int arr[N],b[N][N],store[N][N],prev1[N],prev2[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t=1;
    cin >> t;
    while (t--)
    {
        int l,n,m;
        cin >> l >> n >> m;
		unordered_map<int,vector<int>> mp;
		for(int i=0; i<l; i++){
			cin >> arr[i];
			mp[arr[i]].push_back(i);
		}
		memset(store, -1, sizeof store);
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin >> b[i][j];
				for(int &v: mp[b[i][j]]){
					store[v][i]=j;
					break;
				}
			}
		}

		for (auto &it : mp) {
            int first_pos = -1;
			int k=0;
            for(int &v: it.second){
				if(k==0){
					first_pos=v;
					k++;
					continue;
				}
				for(int j=0; j<n; j++){
					store[v][j]=store[first_pos][j];
				}
			}
        }


		vector<int> prev(n,0);
		vector<int> curr(n,0);
		for(int i=l-1; i>=0; i--){
			if(i!=l-1){
				if(store[i+1][n-1]!=-1){
					if(prev[n-1]==0){
						prev1[n-1]=store[i+1][n-1];
					}else{
						prev1[n-1]=0;
					}
					if(prev[n-1]==1){
						prev2[n-1]=store[i+1][n-1];
					}else{
						prev2[n-1]=0;
					}
				}
				curr[n-1]=0;
				for(int j=n-2; j>=0; j--){
					if(prev[j]==0){
						prev1[j]=max(prev1[j+1], store[i+1][j]);
					}else{
						prev1[j]=prev1[j+1];
					}
					if(prev[j]==1){
						prev2[j]=max(prev2[j+1], store[i+1][j]);
					}else{
						prev2[j]=prev2[j+1];
					}
					curr[j]=0;
				}
			}
			
			for(int j=n-1; j>=0; j--){
				if(store[i][j]!=-1){
					if(j==n-1 || store[i][j]==m-1){
						curr[j]=1;
					}else{
						if(prev2[j+1]>store[i][j]){
							curr[j]=0;
						}else if(prev1[j+1]>store[i][j]){
							curr[j]=1;
						}else{
							curr[j]=1;
						}
					}
				}
				if(j<n-1){
					prev1[j+1]=prev2[j+1]=0;
				}
			}
			prev1[0]=prev2[0]=0;
			prev=curr;
		}

		bool flag=false;
		for(int i=0; i<n; i++){
			if(prev[i]==1){
				flag=true;
				break;
			}
		}

		if(flag){
			cout << "T" << endl;
		}else{
			cout << "N" << endl;
		}
    }
    
}