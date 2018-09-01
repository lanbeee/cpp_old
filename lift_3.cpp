#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>

using namespace std;

int targett, container[8][8][4], lposition[3], ldirection[3]; //container contains passengers [from][to][lift no.]
double timefloor[8], t_lift[3];
double c = RAND_MAX + 1;
bool calll[8][3][2], switchh[8][2]; //switchh is the button on the floor

int mindex (double a[], int s){ //returns minimum index
    int s1= 0;
    double s2 =a[0];
    for(int i = 0 ; i<s ; i++){
        if (a[i] < s2) s1 = i;
        s2 = min(s2,a[i]);
    }
    return s1;
}

int mindex (int a[], int s){
    int s1= 0;
    int s2 =a[0];
    for(int i = 0 ; i<s ; i++){
        if (a[i] < s2) s1 = i;
        s2 = min(s2,a[i]);
    }
    return s1;
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

int decide_down(int l){}

void nextcall(){                            //to add call to lift and the floor button
    int a1 = mindex(timefloor , 8);
    targett = a1;
    double a2 = a1>0 ? (-10) : (-2);
    timefloor[a1] += a2*log(1-(rand())/c);  //arrival rate, 5 times more at 0th floor.
    while (targett == a1){                  //produces target with 5 times more probability for 0.
        if(rand()%12 < 5) targett = 0;
        else{
            targett = rand()%7 + 1;
        }
        if(targett != a1) container[a1][targett][3] += 1;
    }
    if (targett < a1){
        if(switchh[a1][0] != 1){
            calll[a1][decide_down(a1)][0] = 1;
            switchh[a1][0] = 1;
        }
    }
    else {
        if(switchh[a1][1] != 1){
            calll[a1][decide_down(a1)][1] = 1;
            switchh[a1][0] = 1;
        }
    }
}
