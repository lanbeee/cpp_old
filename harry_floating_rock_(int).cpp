#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,x,y,x2,y2,pts;
    float m,mt;
    bool boo = 0;
    cin>>t;
    while(t--){
        boo = 0;
        pts=0;
        cin>>x>>y>>x2>>y2;
        x = abs(x-x2);
        y = abs(y-y2);
        //cout<<"x: "<<x<<" , y: "<<y<<endl;
        if((x != 0)&&(y != 0)){
            m = ((float)y)/x;
            for(int i = 1; i < x;i++){
                //cout<<"i: "<<i<<endl;
                for(int j=floor(m*i);j<=ceil(m*i);j++ ){
                    mt = ((float)j)/i;
                    //cout<<"i: "<<i<<" , j: "<<j<<" , mt: "<<mt<<" , m: "<<m<<endl;
                    if(mt==m){
                        //cout<<"evaluating pts"<<endl;
                        pts = floor(sqrt((pow(x,2)+pow(y,2))/(pow(i,2)+pow(j,2))))-1;
                        boo = 1;
                        break;
                    }
                }
                if (boo) break;
            }
            cout<<pts<<endl;
        }
        else{
            if (x==y) cout<<0<<endl;
            else cout<<(abs(x-y)-1)<<endl;
        }
    }
    return 0;
}
