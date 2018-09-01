#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>

using namespace std ;

int target, tar[8][8][4] ,position[3], lift_direction[3];  //tar[from][to][in lift] lift direction [1] is up
double t[8],tlif[3],tstay[3],textra[3];
double c = RAND_MAX +1;
bool switchh[8][2] ,callift[8][3][2];      //switch[][1] is down

void print_status(){
    cout<<"STATUS"<<endl;
    cout<<"Position:"<<position[0]<<" "<<position[1]<<" "<<position[2]<<endl;
    cout<<"lift Directions:"<<lift_direction[0]<<lift_direction[1]<<lift_direction[2]<<endl;
    cout<<"time at floors :";
    for (int i = 0; i<8; i++){
        cout<<t[i]<<" ";
    }
    cout<<endl<<endl;
}

double minarray (double a[], int s){      //returns minimum value from array
    //cout<<"in minarray size "<<s<<endl;
    //print_status();
    double small =  a[0];
    for(int i = 1 ; i< s; i++){
        small = min(small,a[i]);
    }
    return small;
}

int minarray (int a[], int s){
    //cout<<"in minarray size "<<s<<endl;
    //print_status();
    int small =  a[0];
    for(int i = 1 ; i< s; i++){
        small = min(small,a[i]);
    }
    return small;
}

double maxarray (double a[], int s){
    //cout<<"in maxarray size"<<s<<endl;
    //print_status();
    double large =  a[0];
    for(int i = 1 ; i< s; i++){
        large = max(large,a[i]);
    }
    return large;
}

int maxarray (int a[], int s){
    //cout<<"in maxarray size "<<s<<endl;
    //print_status();
    int large =  a[0];
    for(int i = 1 ; i< s; i++){
        large = max(large,a[i]);
    }
    return large;
}

int maxpos(int l){                      //to find the max floor lift will go
    //cout<<"in maxpos"<<endl;
    //print_status();
    int a =0;
    for(int i = ((position[l])/2); i<8;i++){
        if(callift[i][l][0]) a = 7;
        if(callift[i][l][1]) a = max(i,a);
    }
    int b =0;
    int c = position[l]/2;
    for(int j = c; j> -1 ; j--){
        for(int i = c; i<8; i++){
            if (tar[j][i][l+1] != 0) b = max(b, i);
        }
    }
    return 2*(max(a,b));
}

int minpos(int l){                  //to find the minimum floor the lift will go
    //cout<<"in minpos"<<endl;
    //print_status();
    int a = 7;
    for(int i = (position[l]/2); i> -1; i++){
        if(callift[i][l][0]) a = min(i,a);
        if(callift[i][l][1]) a = 0;
    }
    int b = 7;
    for(int j = position[l]; j< 8 ; j++){
        for(int i = position[l]; i>-1 ;i--){
            if (tar[j][i][l+1] != 0) b = min( b, i);
        }
    }
    return 2*(min(a,b));
}

int decide_up(int i){              //to decide lift for response at floor i
    cout<<"in decide_up call from "<<i;
    int a[3];
    for(int j=0; j<3;j++){
        if(lift_direction[j] ==0) a[j] = abs(position[j]- 2*i);
        else if(lift_direction[j] ==1) a[j] = position[j]>2*i ? 2*maxpos(j) - position[j] + 2*i : 2*i - position[j];
        else a[j] = position[j] - minpos(j) + abs(minpos(j) - 2*i);
    }
    if (minarray(a,3)==a[0]){
        cout<<" returned "<<0<<endl;
        print_status();
        return 0;
    }
    else if (minarray(a,3)==a[1]){
        cout<<" returned "<<1<<endl;
        print_status();
        return 1;
    }
    else{
        cout<<" returned "<<2<<endl;
        print_status();
        return 2;
    }
}

int decide_down(int i){
    cout<<"in decide_down call from "<<i;
    print_status();
    int a[3];
    for(int j= 0; j<3; j++){
        if(lift_direction[j]==0) a[j] = abs(position[j] - 2*i);
        else if( lift_direction[j] == -1) a[j] = position[j]>= 2*i ? position[j] - 2*i : 14 + position[j] - 2*minpos(j) - 2*i;
        else a[j] = maxpos(j) - position[j] + abs(maxpos(j) - 2*i);
    }
    if (minarray(a,3)==a[0]){
        cout<<" returned "<<0<<endl;
        print_status();
        return 0;
    }
    else if (minarray(a,3)==a[1]){
        cout<<" returned "<<1<<endl;
        print_status();
        return 1;
    }
    else{
        cout<<" returned "<<2<<endl;
        print_status();
        return 2;
    }
}


void transaction_up(int p,int l){           //for transaction of customers at floor
    cout<<"in transaction_up at "<<p<<" lift:"<<l<<endl;
    print_status();
    tar[p][p][1] = 0;                       //variable to check if any movement of passenger
    for(int i = p+1;i<8;i++){                //pick passenger
        tar[p][i][l+1] = tar[p][i][0];
        tar[p][p][1] = tar[p][p][1] + tar[p][i][l+1];
        tar[p][p][0] = tar[p][p][0] - tar[p][i][l+1];
        tar[p][i][0] = 0;
    }
    for(int i = 7;i >= 0;i--){    //leave passenger
        tar[p][p][1] = tar[p][p][1] + tar[i][p][l+1];
        tar[i][p][l+1] = 0;
    }
    switchh[p][0]=0;
    callift[p][l][0]=0;
    if(tar[p][p][1] != 0) tlif[l]=tlif[l]+1+0.2*(tar[p][p][1]);
    while(t[p]<tlif[l]){      //mini next call with changes
        target = p;
        float a1 = p>0 ? (-10.0) : (-2.0);
        t[p]=t[p] + a1*log(1-(rand())/c);
        while (target==p){
            target = rand()%8;
            if(target > p){tar[p][target][l+1]++;tlif[l]=tlif[l]+0.2;tar[p][p][1]++;}
            if(target < p){
                tar[p][p][0]++;
                switchh[p][1]=1;
                callift[p][decide_down(p)][1]=1;
                cout<<"new call from "<<p<<" for "<<target<<" lift:"<<decide_down(p)<<endl;
            }
        }
    }
}

void transaction_down(int p,int l){
    cout<<"in transaction_down at "<<p<<" lift:"<<l<<endl;
    print_status();
    tar[p][p][1] = 0;           //variable to check movement of passenger
    for(int i = p-1;i >= 0;i--){     //pick passenger
        tar[p][i][l+1] = tar[p][i][0];
        tar[p][p][1] = tar[p][p][1] + tar[p][i][l+1];//activity checked
        tar[p][p][0] = tar[p][p][0] - tar[p][i][l+1];
        tar[p][i][0] = 0;
    }
    for(int i = 0;i <= 7;i++){    //leave passenger
        tar[p][p][1] = tar[p][p][1] + tar[i][p][l+1];//activity checked
        tar[i][p][l+1] = 0;//(required)passengers moved out
    }
    switchh[p][1]=0;
    callift[p][l][1]=0;
    if(tar[p][p][1] != 0) tlif[l]=tlif[l]+1+0.2*(tar[p][p][1]);
    while(t[p]<tlif[l]){      //mini next call with changes
        target = p;
        float a1 = p>0 ? (-10.0) : (-2.0);
        t[p]=t[p] + a1*log(1-(rand())/c);
        while (target==p){
            target = rand()%8;
            if(target < p){tar[p][target][l+1]++;tlif[l]=tlif[l]+0.2;tar[p][p][1]++;}
            if(target > p){
                tar[p][p][0]++;
                switchh[p][0]=1;
                callift[p][decide_up(p)][0]=1;
                cout<<"new call from "<<p<<" for "<<target<<" lift:"<<decide_up(p)<<endl;
            }
        }
    }
}

bool decide_moveup(int l){
    cout<<"in decide_moveup lift "<<l<<endl;
    print_status();
    int a=0;
    int b=0;
    //if (lift_direction[l]== 1) return 1;
    for(int j = position[l] ; j<15; j+=2) if(tar[(position[l])/2][j/2][l+1] != 0) return 1;
    for(int i= position[l] +2 ;i<15 ;i+=2){
        a = a + callift[i/2][l][0] + callift[i/2][l][1] ;
    }
    for(int i= position[l] -2 ;i>-1 ;i-=2){
        b = b + callift[i/2][l][0] + callift[i/2][l][1] ;
    }
    if (a>b) return 1;
    if (((a==0)&&(b==0))&&(callift[position[l]/2][l][0])) return 1;
    return 0;
}

void moveup(int i){
    cout<<"in moveup lift"<<i<<endl;
    print_status();
    while(((decide_moveup(i))&&(tlif[i]< minarray(t,8)))&& (position[i])<15){
        if (position[i]%2 ==0){
            transaction_up((position[i]/2), i);
            tlif[i] += 0.3;
        }
        if (position[i] < 14) position[i]++;
        lift_direction[i]= 1;
        if (tlif[i]> minarray(t,8)) return;
        if (((position[i]%2)!=0)&&(position[i]<14)) position[i]++;
        lift_direction[i] = 0;
    }
}


bool decide_movedown(int l){
    cout<<"in decide_movedown lift "<<l<<endl;
    print_status();
    int a = 0;
    int b = 0;
    //if (lift_direction[l]== -1) return 1;
    for(int j = position[l] -2; j>-1; j-=2) if(tar[(position[l])/2][j/2][l+1] != 0) return 1;
    for(int i= position[l] +2 ;i<15 ;i+=2){
        a = a + callift[i/2][l][0] + callift[i/2][l][1] ;
    }
    for(int i= position[l] -2 ;i>-1 ;i-=2){
        b = b + callift[i/2][l][0] + callift[i/2][l][1] ;
    }
    if ((a<=b)&&(b!=0)) return 1;
    if (((a==0)&&(b==0))&&(callift[position[l]/2][l][1])) return 1;
    return 0;
}

void movedown(int i){
    cout<<"in movedown lift"<<i<<endl;
    print_status();
    while(((decide_movedown(i))&&(tlif[i]< minarray(t,8)))&& (position[i])>=0){
        if (position[i]%2 ==0){ transaction_down((position[i]/2), i);tlif[i] += 0.3;}
        if (position[i]>0)position[i]--;
        lift_direction[i]= -1;
        if (tlif[i]> minarray(t,8)) return;
        if (position[i]>0) position[i]--;
        lift_direction[i]= 0;
    }
}

void nextcall(){
    cout<<"in nextcall"<<endl;
    print_status();
    for(int i=0; i<8;i++){
        if(t[i]==minarray(t,8)){
            target = i;
            float a1 = i>0 ? (-10) : (-2);
            t[i]=t[i] + a1*log(1-(rand())/c);           //if i!= then arrival rate 10 and if 0 then 1 person per 2 second
            tar[i][i][0]=tar[i][i][0] +1;
            while (target==i){
                target = rand()%8;
                if(target != i) tar[i][target][0]++;    //add 1 to queue at that floor
            }
            if(target<i){
                if(switchh[i][1] != 1) callift[i][decide_down(i)][1]=1;
                switchh[i][1] = 1;
                cout<<"new call from "<<i<<" for "<<target<<" lift:"<<decide_down(i)<<endl;                      //button on that floor
            }
            else{
                if(switchh[i][0] != 1) callift[i][decide_up(i)][0]=1;
                switchh[i][0]=1;
                cout<<"new call from "<<i<<" for "<<target<<" lift:"<<decide_up(i)<<endl;
            }
            return ;
        }
    }
}

void staylift(int i){
    cout<<"in staylift for lift "<<i<<endl;
    print_status();
    tstay[i] = tstay[i]+ minarray(t,8) - tlif[i];
    tlif[i] = minarray(t,8);
}

int main(){
    for(int i=0;i<8;i++){           //initiating arrays
        t[i]=0;
        for(int j=0;j<8;j++){
            for(int k=0;k<2;k++){
                tar[i][j][2*k]= 0;
                tar[i][j][(2*k+1)%4]= 1;
                switchh[j][k]=0;
                for(int l=0;l<3;l++){
                    tlif[l]=0;
                    tstay[l]=0;
                    lift_direction[l]=0;
                    position[l]= 0;
                    callift[j][l][k]=0;
                }
            }
        }
    }                              // initiation over
    double t1;
    cin>>t1;
    nextcall();
    while(maxarray(t,8)<t1){
        for(int i=0;i<3 ;i++){
            if(decide_moveup(i)) moveup(i);
            else if(decide_movedown(i)) movedown(i);
            else staylift(i);
            nextcall();
        }
    }
    return 0;
}
