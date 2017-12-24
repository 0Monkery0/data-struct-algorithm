#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int list[50],i,j,mark;
    srand((unsigned)time(NULL));
    for(i = 0;i < 50;i++){
        list[i] = rand() % 10 + 1;
        printf("%d ",list[i]);
    }
    printf("\n");
    for(i = 0;i < 50;i++){
        mark = i;
        for(j = i + 1;j < 50;j++){
            if(list[mark] > list[j]){
                mark = j;
            }
        }
        if(mark != i){
            j = list[mark];
            list[mark] = list[i];
            list[i] = j;
        }
    }
    for(i = 0;i < 50;i++){
       printf("%d ",list[i]);
    }
    printf("\n");
    return 0;
}
