#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int list[50],i,mark = 1,change;
    srand((unsigned)time(NULL));
    for(i = 0;i < 50;i++){
        list[i] = rand() % 10 + 1;
        printf("%d ",list[i]);
    }
    printf("\n");
    while(mark != 0){
        mark = 0;
        for(i = 0;i < 49;i++){
            if(list[i] > list[i + 1]){
                change = list[i];
                list[i] = list[i + 1];
                list[i + 1] = change;
                mark = 1;
            }
        }
    }
    for(i = 0;i < 50;i++){
        printf("%d ",list[i]);
    }
    printf("\n");
    return 0;
}
