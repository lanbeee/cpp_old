#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
using namespace std;

int main(){
    double d;
    srand(time(NULL));
    int i;
    for(i=1; i<10001; i++){
        int c = rand();
        d = d + (-.2)*log(1 -(c/32768.0));
    }
    cout<<(d/10000.0);
	return 0;
}
