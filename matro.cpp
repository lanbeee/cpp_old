#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ftheta(int shell, int i, int j, int M, int N){
    if ((shell==i)&&(i != (N-j-1))) return 0;
    else if(shell==j) return 1;
    else if(shell==M-i-1) return 2;
    else if(shell==N-j-1) return 3;
    return 0;
}

bool ondiagonal(int i, int j,int M, int N){
    if(i==j) return 1;
    else if(i==N-j-1) return 1;
    else if(j==M-i-1) return 1;
    else if(N-j-1==M-i-1) return 1;
    return 0;
}

void rotOnce(int shell,int &theta, int &i, int &j, int M, int N){
    int thet = theta;
    if(ondiagonal(i,j,M,N)) theta = (theta + 1)%4;
    if(ondiagonal(i,j,M,N)){
        if(thet==0){
            i++;
            return;
        }
        else if(thet == 1){
            j++;
            return;
        }
        else if (thet==2){
            i--;
            return;
        }
        else if (thet==3){
            j--;
            return;
        }
    }
    if(theta == 0){
        j--;
        return;
    }
    else if (theta ==1){
        i++;
        return;
    }
    else if(theta==2){
        j++;
        return;
    }
    else if(theta ==3){
        i--;
        return;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int M,N,R,i,j,shell,theta;
    cin>>M>>N>>R;
    int arr[M][N];
    for(int ii = 0;ii<M;ii++) for(int jj=0;jj<N;jj++){
        i = ii;
        j = jj;
        shell = min(min(i,j),min(M-i-1,N-j-1));
        theta = ftheta(shell,i,j,M,N);
        for(int k =0;k<R;k++){
            rotOnce(shell,theta,i,j,M,N);
        }//rotate function
        cin>>arr[i][j];
    }
    for(i=0;i<M;i++) {
        for(j=0;j<N;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
