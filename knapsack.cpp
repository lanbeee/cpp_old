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
        int size, exp, mint;
        cin>>size>>exp;
        int arr[size];
        cin>>arr[0];
        mint = arr[1];
        for(int i=1; i<=size; i++){
            cin>>arr[i];
            mint = min(arr[i],mint);
        }
        int maxt,arr2[size][exp-mint+1];
        maxt = (exp/mint) + 1;
        for(int l=0;l<=(exp-mint);l++){
            if((l%arr[0])==0) arr2[0][l] == (l/arr[0]) +1;
            else arr2[0][l] = maxt;
        }
        for(int j = 1;j<size;j++){
            for(int k= 0;k<=(exp-mint);k++){
                if((k-arr[j])>=0) arr2[j][k]=min((arr2[j-1][k]),arr2[j][k-arr[j]]+1);
                else arr2[j][k] = arr2[j-1][k];
            }
        }
        for(int m=exp-mint; m>=0;m--){
            if (arr2[size-1][m]<maxt){
                cout<<arr2[size-1][m];
                break;
            }
        }
    }
    return 0;
}
