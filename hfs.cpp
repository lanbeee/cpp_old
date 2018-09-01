#include <cstdio>
#include<cmath>

using namespace std;

int main(){
	double pi = 4*atan(1.0);
	int x;
	while (scanf("%d",&x)&&x!=0){
		printf("%.8lf\n",(double)(x*x)/2/pi);
	}
}
