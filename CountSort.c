#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int list[50],count[10] = {0},i,j;
    srand((unsigned)time(NULL));
    for(i = 0;i < 50;i++){
        list[i] = rand() % 5 + 1;
        printf("%d ",list[i]);
    }
    printf("\n");
    for(i = 0;i < 50;i++){
        switch(list[i]){
        case 1:count[0]++;break;
        case 2:count[1]++;break;
        case 3:count[2]++;break;
        case 4:count[3]++;break;
        case 5:count[4]++;break;
        defult:break;
        }
    }
    for(j = 0;j < 5;j++){
        for(i = 0;i < count[j];i++){
            printf("%d ",j+1);
        }
    }
    printf("\n");
    return 0;
}
