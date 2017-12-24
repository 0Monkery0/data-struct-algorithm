#include <stdio.h>
#include <math.h>

int main(int argc,char *argv[]){
    int a,b,sum = 1,i = 0;
    scanf("%d %d",&a,&b);
    while(b != 0){
        if(b & 1 == 1){
            sum *= pow(a,pow(2,i));
        }
        i++;
        b = b >> 1;
    }
    printf("sum=%d\n",sum);
    return 0;
}