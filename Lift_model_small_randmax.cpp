#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>

int tar1,tar2,tar3,tar4,tar5,tar6,tar7,target,targetmax,cycle,position,q0,q1,q2,q3,q4,q5,q6,q7 = 0;
double tsystem,t1,t2,t3,t4,t5,t6,t7,t0 = 0;
double c = RAND_MAX +1;
bool direction =1;

using namespace std ;

void timecover(){
    while(t1<=tsystem){
            t1=t1+(-10.5)*log(1-(rand())/c);
            q1=q1+1;
            targetmax = max(targetmax,1);
    }
    while(t2<=tsystem){
            t2=t2+(-10.5)*log(1-(rand())/c);
            q2=q2+1;
            targetmax = max(targetmax,2);
    }
    while(t3<=tsystem){
            t3=t3+(-10.5)*log(1-(rand())/c);
            q3=q3+1;
            targetmax = max(targetmax,3);
    }
    while(t4<=tsystem){
            t4=t4+(-10.5)*log(1-(rand())/c);
            q4=q4+1;
            targetmax = max(targetmax,4);
    }
    while(t5<=tsystem){
            t5=t5+(-10.5)*log(1-(rand())/c);
            q5=q5+1;
            targetmax = max(targetmax,5);
    }
    while(t6<=tsystem){
            t6=t6+(-10.5)*log(1-(rand())/c);
            q6=q6+1;
            targetmax = max(targetmax,6);
    }
    while(t7<=tsystem){
            t7=t7+(-10.5)*log(1-(rand())/c);
            q7=q7+1;
            targetmax = max(targetmax,7);
    }
}

bool positionque(){
    bool a;
    if (position==7){
            a = (q7 != 0);
            q7=0;
            return a;
    }
    else if (position==6){
            a = (q6 != 0);
            q6=0;
            return a;
    }
    else if (position==5){
            a = (q5 != 0);
            q5=0;
            return a;
    }
    else if (position==4){
            a = (q4 != 0);
            q4=0;
            return a;
    }
    else if (position==3){
            a = (q3 != 0);
            q3=0;
            return a;
    }
    else if (position==2){
            a = (q2 != 0);
            q2=0;
            return a;
    }
    else if (position==1){
            a = (q1 != 0);
            q1=0;
            return a;
    }
}

void ground(){
    tar1,tar2,tar3,tar4,tar5,tar6,tar7=0;
    targetmax = 1;
    cycle++;
    while(t0<=tsystem){
        t0 = t0 + (-1.5)*log(1 - (rand())/c);
        target = rand()%7 +1;
        if (target==1) {
                tar1++;
                targetmax = max(targetmax,1);
        }
        else if (target==2) {
                tar2++;
                targetmax = max(targetmax,2);
        }
        else if (target==3) {
                tar3++;
                targetmax = max(targetmax,3);
        }
        else if (target==4) {
                tar4++;
                targetmax = max(targetmax,4);
        }
        else if (target==5) {
                tar5++;
                targetmax = max(targetmax,5);
        }
        else if (target==6) {
                tar6++;
                targetmax = max(targetmax,6);
        }
        else {
                tar7++;
                targetmax = 7;
        }
    }
    position = targetmax;
    tsystem = tsystem + targetmax/1.5 + ((tar1>0)+(tar2>0)+(tar3>0)+(tar4>0)+(tar5>0)+(tar6>0)+(tar7>0)+1);
    direction = 1;
}

void reset(){
    while (direction){
        timecover();
        if (targetmax <= position){
                direction=0;
                break;
        }
        position = max(targetmax,position);
        tsystem = tsystem + (targetmax - position)/1.5;
    }
}

void movedown(){
    while(position > 0){
        timecover();
        tsystem = tsystem + 1/1.5 + (positionque());
        position = position - 1;
    }
}

int main(){
    while (cycle<10000){
        srand(time(NULL)+rand());
        ground();
        reset();
        movedown();
    }
    cout << tsystem;
}
