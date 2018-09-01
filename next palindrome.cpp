#include<iostream>
#include<cmath>
using namespace std;

int main(){
    bool odd;
    int lenn,l2,t;
    long int dat,m1,m2,m3,temp;
    cin>>t;
    while(t--){
    cin>>dat;
    if (dat==0) {cout<<1<<endl;continue;}
    lenn =  (int)log10(dat) +1;
    l2=lenn/2;
    odd= lenn%(2) ;
    temp =1;
    m2=0;
    if(!odd){                       //cas 1
        while(l2--) temp=temp*10;
        l2=lenn/2;
        m1 = dat/temp;
        m2 =0;
        temp = m1;
        for(int i=0;i<lenn/2;i++){
            m2 = 10*m2 + temp%10;
            temp= temp/10;
        }
        m3 =m1;
        while(l2--) m3=m3*10;
        l2= lenn/2;
        m3= m3 + m2;
        if (m3>dat)temp =0;
        else{
            temp = (int)log10(m1);
            m1++;
            if (temp< (int)log10(m1)){
                m3 =m1;
                while(l2--) m3=m3*10;
                m3= m3 + 1;
            }
            else{
                m2 =0;
                temp = m1;
                for(int i=0;i<lenn/2;i++){
                    m2 = 10*m2 + temp%10;
                    temp= (int)temp/10;
                }
                m3 =m1;
                while(l2--) m3=m3*10;
                m3= m3 + m2;
            }
        }
        cout<<m3<<endl;
    }
    else{
        while(l2--) temp=temp*10;
        l2=lenn/2;
        m1 = dat/temp;
        m2 =0;
        temp = m1/10;
        for(int i=0;i<lenn/2;i++){
            m2 = 10*m2 + temp%10;
            temp= temp/10;
        }
        m3 =m1;
        while(l2--) m3=m3*10;
        l2= lenn/2;
        m3= m3 + m2;
        if (m3>dat)temp =0;
        else{
            temp = (int)log10(m1);
            m1++;
            if (temp< (int)log10(m1)){
                m3 =m1;
                while(l2--) m3=m3*10;
                m3= m3 + 1;
            }
            else{
                m2 =0;
                temp = m1/10;
                for(int i=0;i<lenn/2;i++){
                    m2 = 10*m2 + temp%10;
                    temp= (int)temp/10;
                }
                m3 =m1;
                while(l2--) m3=m3*10;
                m3= m3 + m2;
            }
        }
        cout<<m3<<endl;
    }
    }
    return 0;
}
