#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin>>t;                           
    while(t--) {
        cin>>n;
        int mList[n+1][n+1];                   
        int wList[n+1][n+1];                   
        int manCurrentMatch[n+1];              
        int womanCurrentMatch[n+1];            
        

        for (int i = 1; i <= n; i++) {         
            womanCurrentMatch[i] = SINGLE;     
            for(int j = 0; j <= n; j++) {
                scanf("%d", &wList[i][j]);
            }
        }

        for (int i = 1; i <= n; i++) {         
            manCurrentMatch[i] = SINGLE;       
            manNextProposal[i] = 1;            
            for(int j = 0; j <= n; j++) {
                scanf("%d", &mList[i][j]);
            }
        }

        bool freeman = 1;
        int m = 1;
        while(freeman){
            freeman = 0;
            int w = mList[m][manNextProposal[m]++];
            if(womanCurrentMatch[w] == 0){
                womanCurrentMatch[w] = m;
                manCurrentMatch[m] = w;
            }
            else{
                bool betterpreference = false;
                for(int p = 1;p<=n;p++){
                    if(wList[w][p] == womanCurrentMatch[w]){
                        betterpreference = false;
                        break;
                    }
                    if(wList[w][p] == m){
                        betterpreference = true;
                        break;
                    }
                }
                if(betterpreference){
                    manCurrentMatch[manCurrentMatch[w]] = 0;
                    manCurrentMatch[m] = w;
                    womanCurrentMatch[w] = m;
                }
            }

            for(int p = 1;p<=n;p++){
                if(manCurrentMatch[p] == 0){
                    m = p;
                    freeman = 1;
                    break;
                }
            }
        }

        for(int i = 1;i<=n;i++){
            cout<<i<<" "<<manCurrentMatch[i]<<endl;
        }

    }

    return 0;
}