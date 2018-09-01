#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int z;
    cin>>z;
    float a,b,c,d,f0,h0,temps;
    while(z--){
        //cout<<"input a b c d h0 f0"<<endl;
        cin>>a>>b>>c>>d>>h0>>f0;
        for(int i = 0;i<20;i++){
            cout<<"f"<<i<<" : "<<f0<<" h"<<i<<" : "<<h0<<endl;
            temps = h0;
            h0 = a*h0-b*f0;
            f0= c*f0+d*temps;
        }
    }
    return 0;
}
