#include <cstdio>
#include <iostream>

using namespace std;

int op_target,op_start;
int moves;

int abs(int a){
    if (a<0) return (0-a);
    else return a;
}

bool opp_continue(int arr[],int si_ze){
    for (int i=0;i<si_ze;i++){
        for (int j=0;j<si_ze;j++){
            if((arr[i]==0)&&(arr[j]>1)) return 1;
        }
    }
    return 0;
}

void decider(int arr[],int si_ze){
    int min_distance = si_ze;
    for(int i=0;i<si_ze;i++){
        if (arr[i]>1) for(int j=0;j<si_ze;j++){
            if ()
        }
    }
}

void teleporter(int arr[],int si_ze){
    if(abs(op_target-op_start)>(si_ze-abs(op_target-op_start))){
        moves += (si_ze - abs(op_target-op_start));
    }
    else{
        moves += abs(op_target-op_start);
    }
    arr[op_target] = 1;
    arr[op_start] -= 1;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        moves = 0;
        op_target = 0;
        op_start = 0;
        int siize;
        scanf("%d",&siize);
        int arr1[siize];
        for(int i=0;i<siize;i++){
            scanf("%d",&arr1[i]);
        }
        while(opp_continue(arr1,siize)){
            decider(arr1,siize);
            teleporter(arr1,siize);
        }
        printf("%d",moves);
    }
}
