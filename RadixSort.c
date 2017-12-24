#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(){
    int list[50],radix[10][50],i,j,k,temp,rd0,rd1,rd2,rd3,rd4,rd5,rd6,rd7,rd8,rd9;
    srand((unsigned)time(NULL));
    for(i = 0;i< 50;i++){
        list[i] = rand() % 10000 + 1;
        printf("%d ",list[i]);
    }
    printf("\n");
    for(j = 0;j < 4;j++){
        k = 0;
        rd0 = 0;
        rd1 = 0;
        rd2 = 0;
        rd3 = 0;
        rd4 = 0;
        rd5 = 0;
        rd6 = 0;
        rd7 = 0;
        rd8 = 0;
        rd9 = 0;
        for(i = 0;i < 50;i++){
            temp = (list[i] % (int)pow(10,j + 1)) / (int)pow(10,j);
            switch(temp){
            case 0:radix[0][rd0] = list[i];rd0++;break;
            case 1:radix[1][rd1] = list[i];rd1++;break;
            case 2:radix[2][rd2] = list[i];rd2++;break;
            case 3:radix[3][rd3] = list[i];rd3++;break;
            case 4:radix[4][rd4] = list[i];rd4++;break;
            case 5:radix[5][rd5] = list[i];rd5++;break;
            case 6:radix[6][rd6] = list[i];rd6++;break;
            case 7:radix[7][rd7] = list[i];rd7++;break;
            case 8:radix[8][rd8] = list[i];rd8++;break;
            case 9:radix[9][rd9] = list[i];rd9++;break;
            defult:break;
            }
        }
        for(i = 0;i < rd0;i++){
            list[k] = radix[0][i];
            k++;
        }
        for(i = 0;i < rd1;i++){
            list[k] = radix[1][i];
            k++;
        }
        for(i = 0;i < rd2;i++){
            list[k] = radix[2][i];
            k++;
        }
        for(i = 0;i < rd3;i++){
            list[k] = radix[3][i];
            k++;
        }
        for(i = 0;i < rd4;i++){
            list[k] = radix[4][i];
            k++;
        }
        for(i = 0;i < rd5;i++){
            list[k] = radix[5][i];
            k++;
        }
        for(i = 0;i < rd6;i++){
            list[k] = radix[6][i];
            k++;
        }
        for(i = 0;i < rd7;i++){
            list[k] = radix[7][i];
            k++;
        }
        for(i = 0;i < rd8;i++){
            list[k] = radix[8][i];
            k++;
        }
        for(i = 0;i < rd9;i++){
            list[k] = radix[9][i];
            k++;
        }
    }
    for(i = 0;i< 50;i++){
        printf("%d ",list[i]);
    }
    printf("\n");
    return 0;
}
