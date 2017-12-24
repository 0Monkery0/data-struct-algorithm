#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int list[50],i,j,change;
    srand((unsigned)time(NULL));
    for(i = 0;i < 50;i++){
        list[i] = rand() % 10 + 1;
        printf("%d ",list[i]);
    }
    printf("\n");
    for(i = 1;i < 50;i++){
        for(j = i;j > 0;j--){
            if(list[j] < list[j - 1]){
                change = list[j];
                list[j] = list[j - 1];
                list[j - 1] = change;
            }
            else{
                break;
            }
        }
    }
    for(i = 0;i < 50;i++){
        printf("%d ",list[i]);
    }
    printf("\n");
    return 0;
}
