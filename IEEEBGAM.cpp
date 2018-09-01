#include <cstdio>

using namespace std;

int main(){
	int x,t;
	scanf("%d",&t);
	while (t--){
        scanf("%d",&x);
		printf("%.8lf\n",(double)(x)/(x+1));
	}
}
