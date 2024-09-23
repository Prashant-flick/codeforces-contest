#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t=1;
    cin >> t;
    while (t--)
    {
        int l,n,m;
        cin >> l >> n >> m;
        const int size = (n*m)+5;
        int arr[l];
		for(int i=0; i<l; i++)cin >> arr[i];
		int b[n][m];
        int mpi[size][2];
        int mpj[size][2];
        memset(mpi, -1, sizeof mpi);
        memset(mpj, -1, sizeof mpj);
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin >> b[i][j];
                if(i>=mpi[b[i][j]][0]){
                    mpi[b[i][j]][0]=i;
                    mpi[b[i][j]][1]=j;
                }
			}
		}

		for(int j=0; j<m; j++){
			for(int i=0; i<n; i++){
                if(j>=mpj[b[i][j]][1]){
                    mpj[b[i][j]][0]=i;
                    mpj[b[i][j]][1]=j;
                }
			}
		}

		int dp[l+1][2]={0};
        int pa1=-1,pa2=-1,pb1=-1,pb2=-1;
        int a1=-1,a2=-1,b1=-1,b2=-1;
		for(int i=l-1; i>=0; i--){
			if(i==l-1){
                if(mpi[arr[i]][0]==-1){
                    dp[i][0]=1;
                    dp[i][1]=1;
                    a1 = mpi[arr[i]][0];
                    b1 = mpi[arr[i]][1];
                    a2 = mpj[arr[i]][0];
                    b2 = mpj[arr[i]][1];
                }else{
                    a1=a2=b1=b2=-1;
                }
            }else{
                if(mpi[arr[i]][0]==-1){
                    a1=a2=b1=b2=-1;
                }else{
                    a1 = mpi[arr[i]][0];
                    b1 = mpi[arr[i]][1];
                    a2 = mpj[arr[i]][0];
                    b2 = mpj[arr[i]][1];
                    if(a1==-1){
                        dp[i][0]=1;
                        dp[i][1]=1;
                        continue;
                    }
                    if((a1>=pa1 || b1>=pb1) && (a1>=pa2 || b1>=pb2)){
                        dp[i][0]=1;
                    }else{
                        if(a1<pa1 && b1<pb1){
                            if(dp[i+1][0]==1){
                                dp[i][0]=0;
                            }else{
                                dp[i][0]=1;
                            }
                        }
                        if(a1<pa2 && b1<pb2){
                            if(dp[i+1][1]==1){
                                dp[i][0]=max(dp[i][0],0);
                            }else{
                                dp[i][0]=max(dp[i][0],1);
                            }
                        }
                    }
                    
                    if((a2>=pa1 || b2>=pb1) && (a2>=pa2 || b2>=pb2)){
                        dp[i][1]=1;
                    }else{
                        if(a2<pa1 && b2<pb1){
                            if(dp[i+1][0]==1){
                                dp[i][1]=0;
                            }else{
                                dp[i][1]=1;
                            }
                        }
                        if(a2<pa2 && b2<pb2){
                            if(dp[i+1][1]==1){
                                dp[i][1]=max(dp[i][1],0);
                            }else{
                                dp[i][1]=max(dp[i][1],1);
                            }
                        }
                    }
                }
            }
            pa1=a1;
            pa2=a2;
            pb1=b1;
            pb2=b2;
		}

        if((max(dp[0][0], dp[0][1]))==1){
            cout << "T" << endl;
        }else{
            cout << "N" << endl;
        }
    }
    
}