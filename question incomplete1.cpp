#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--){
        int siize, expt, mint, maxt,t1,t2,t3;
        cin>>siize;
        cin>>expt;
        int arr[siize];
        cin>>arr[0];
        mint = arr[0];
        for(int i = 1;i<siize;i++){
            cin>>arr[i];
            mint = min(mint, arr[i]);
        }
        maxt = (expt/mint) +1;
        int arr2[siize][expt];
        for(int j=0;j<expt;j++){
            if((j+1)%(arr[j]) == 0) arr2[0][j] = (j+1)/arr[0];
            else arr2[0][j] = maxt;
        }
        for(int j= 1 ; j<siize ;j++){
            for(int k = 0;k<expt;k++){
                if((k+1) == arr[j]){
                    arr2[j][k] = 1;
                    continue;
                }
                t2 = arr2[j-1][k];
                t3 = arr[j];
                t1 = arr2[j][abs(k-t3)]+1;
                if((k-arr[j])<0){
                    arr2[j][k] = t2;
                }
                else arr2[j][k] = min(t1,t2);
            }
        }
        for(int m= 0 ; m<siize ;m++){
            for(int n = 0;n<expt;n++){
                cout<<arr2[m][n]<<" ";
            }
            cout<<endl;}
        /*for(int l = expt-1; l>=0 ; l--){
            if(arr2[siize - 1][l]<maxt) cout<<(l+1)<<endl;
        }*/
    }
    return 0;
}
