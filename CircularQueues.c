#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct queue{
    struct queue *previous;
    char info[16];
    struct queue *next;
};

struct queue *pfront,*prear;

int Create();
int Insert();
int Delete();
int Clear();
int Destroy();
int Display();
int Life();
int Empty();
int Full();

int main(){
    char temp[5];
    pfront = prear = NULL;
    while(1){
        printf("Welcom!\n");
        printf("1.Create Queue.\n2.Insert a node.\n3.Delete a node.\n4.Clear the Queue.\n5.Destroy the Queue.\n6.Display the Queue.\n7.Exit.\n");
        printf("Please select:\n");
        scanf("%s",temp);
        if(strcmp(temp,"1") == 0){
            Create();
        }
        else if(strcmp(temp,"2") == 0){
            Insert();
        }
        else if(strcmp(temp,"3") == 0){
            Delete();
        }
        else if(strcmp(temp,"4") == 0){
            Clear();
        }
        else if(strcmp(temp,"5") == 0){
            Destroy();
        }
        else if(strcmp(temp,"6") == 0){
            Display();
        }
        else if(strcmp(temp,"7") == 0){
            printf("Thank!\n");
            break;
        }
        else{
            printf("Can not recognition!\n\n");
        }
    }
    return 0;
}

int Create(){
    Destroy();
    unsigned short i,len;
    struct queue *pnew,*ptemp;
    prear = pfront = (struct queue *)malloc(sizeof(struct queue));
    strcpy(prear->info,"Empty!");
    ptemp = pfront;
    while(1){
        printf("Please input the length of the queue;\n");
        scanf("%d",&len);
        if(len <= 0){
            printf("Len must bigger then 0!\n");
            continue;
        }
        if(len == 1){
            prear->next = prear;
            prear->previous = prear;
        }
        else{
            for(i = 0;i < len - 1;i++){
                pnew = (struct queue *)malloc(sizeof(struct queue));
                ptemp->next = pnew;
                pnew->next = NULL;
                pnew->previous = ptemp;
                ptemp = pnew;
                strcpy(pnew->info,"Empty!");
            }
            ptemp->next = pfront;
            pfront->previous = ptemp;
        }
        break;
    }
    printf("\n");
    return 0;
}

int Insert(){
    if(Life() == -1){
        return -1;
    }
    if(Full() == -1){
        return -1;
    }
    if(strcmp(prear->info,"Empty!") != 0){
        prear = prear->previous;
    }
    printf("Please input the number you want to insert:\n");
    scanf("%s",prear->info);
    printf("\n");
    return 0;
}

int Delete(){
    if(Life() == -1){
        return -1;
    }
    if(Empty() == -1){
        return -1;
    }
    strcpy(pfront->info,"Empty!");
    if(pfront != prear){
        pfront = pfront->previous;
    }
    printf("\n");
    return 0;
}

int Clear(){
    if(Life() == -1){
        return -1;
    }
    if(Empty() == -1){
        return -1;
    }
    struct queue *ptemp;
    ptemp = pfront;
    while(pfront != prear){
        pfront = pfront->previous;
        strcpy(ptemp->info,"Empty!");
        ptemp = pfront;
    }
    strcpy(ptemp->info,"Empty!");
    printf("\n");
    return 0;
}

int Destroy(){
    if(Life() == -1){
        return -1;
    }
    struct queue *pfree,*pend;
    pfree = prear;
    pend = prear->next;
    while(pend != pfront){
         free(pfree);
         pfree = pend;
         pend = pend->next;
    }
    free(pfree);
    free(pend);
    pfront = prear = NULL;
    printf("\n");
    return 0;
}

int Display(){
    if(Life() == -1){
        return -1;
    }
    if(Empty() == -1){
        return -1;
    }
    struct queue *ptemp;
    ptemp = prear;
    printf("|--rear--|\n");
    printf("|%-8s|\n|--------|\n",ptemp->info);
    ptemp = prear->next;
    while(ptemp != prear){
        printf("|%-8s|\n|--------|\n",ptemp->info);
        ptemp = ptemp->next;
    }
    printf("|-front--|\n\n");
    return 0;
}

int Life(){
    if(pfront == NULL){
        printf("Queue is non-existent!\n\n");
        return -1;
    }
    return 0;
}

int Empty(){
    if(pfront == prear&&strcmp(pfront->info,"Empty!") == 0){
        printf("Queue is empty!\n\n");
        return -1;
    }
    return 0;
}

int Full(){
    if(pfront->next == prear){
        printf("Queue is full!\n\n");
        return -1;
    }
    return 0;
}
