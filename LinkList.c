#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct number{
    int num;
    struct number *next;
};

int Create(struct number *phead);
int Display(struct number *phead);
int InsertHead(struct number *phead);
int InsertEnd(struct number *phead);
int InsertPlace(struct number *phead);
int InsertSearch(struct number *phead);
int Delete(struct number *phead);
int Reverse(struct number *phead);
int Search(struct number *phead);
int Destory(struct number *phead);

int main(){
    struct number *phead = (struct number *)malloc(sizeof(struct number));
    phead -> next = NULL;
    return 0;
}

int Create(struct number *phead){
    char ch[5];
    struct number *ptemp,*pnew;
    ptemp = phead;
    while(1){
        printf("Do you want to add a node?(Y/N)\n");
        scanf("%s",ch);
        if(strcmp(ch,"y") == 0||strcmp(ch,"Y") == 0){
            pnew = (struct number *)malloc(sizeof(struct number));
            ptemp->next = pnew;
            pnew->next = NULL;
            ptemp = ptemp->next;
            printf("Please input a number:\n");
            scanf("%d",&ptemp->num);
        }
        else if(strcmp(ch,"n") == 0||strcmp(ch,"N") == 0){
            break;
        }
        else{
            printf("Can not recognition!\n");
        }
    }
    return 0;
}

int Display(struct number *phead){
    struct number *ptemp;
    ptemp = phead->next;

    if(ptemp == NULL){
        printf("Can not find any nodes!\n");
        return -1;
    }

    while(ptemp != NULL){
        printf("%d ",ptemp->num);
        ptemp = ptemp->next;
    }
    printf("\n");
    return 0;
}

int InsertHead(struct number *phead){
    char ch[5];
    struct number *pnew,*ptemp;
    if(phead->next == NULL){
        printf("Can not find any nodes!\n");
        return -1;
    }
    while(1){
        printf("Do you want to insert a node?(Y/N)\n");
        scanf("%s",ch);
        if(strcmp(ch,"y") == 0||strcmp(ch,"Y") == 0){
            pnew = (struct number *)malloc(sizeof(struct number));
            ptemp = phead->next;
            phead->next = pnew;
            pnew->next = ptemp;
            printf("Please input a number:\n");
            scanf("%d",&pnew->num);
        }
        else if(strcmp(ch,"n") == 0||strcmp(ch,"N") == 0){
            break;
        }
        else{
            printf("Can not recognition!\n");
        }
    }
    return 0;
}

int InsertEnd(struct number *phead){
    char ch[5];
    struct number *ptemp,*pnew;
    ptemp = phead;
    if(ptemp->next == NULL){
        printf("Can not find any nodes!\n");
        return -1;
    }
    while(ptemp->next != NULL){
        ptemp = ptemp->next;
    }
    while(1){
        printf("Do you want to insert a node?(Y/N)\n");
        scanf("%s",ch);
        if(strcmp(ch,"y") == 0||strcmp(ch,"Y") == 0){
            pnew = (struct number *)malloc(sizeof(struct number));
            ptemp->next = pnew;
            ptemp = ptemp->next;
            printf("Please input a number:\n");
            scanf("%d",&pnew->num);
        }
        else if(strcmp(ch,"n") == 0||strcmp(ch,"N") == 0){
            break;
        }
        else{
            printf("Can not recognition!\n");
        }
    }
    return 0;
}

int InsertPlace(struct number *phead){
    unsigned short i,where,go = 0;
    char ch[5];
    struct number *pnew,*ptemp,*pend;
    if(phead->next == NULL){
        printf("Can not find any nodes!\n");
        return -1;
    }
    while(1){
        pend = phead;
        printf("Do you want to insert a node?(Y/N)\n");
        scanf("%s",ch);
        if(strcmp(ch,"y") == 0||strcmp(ch,"Y") == 0){
            printf("Please input the sequence you want to insert.\n");
            scanf("%lu",&where);
            for(i = 1;i < where;i++){
                if(pend->next == NULL){
                    printf("Can not find the sequence!\n");
                    go = 1;
                    break;
                }
                pend = pend->next;
            }
            if(go == 1){
                go = 0;
                continue;
            }
            ptemp = pend->next;
            pnew = (struct number *)malloc(sizeof(struct number));
            pend->next = pnew;
            pnew->next = ptemp;
            printf("Please input a number:\n");
            scanf("%d",&pnew->num);
        }
        else if(strcmp(ch,"n") == 0||strcmp(ch,"N") == 0){
            break;
        }
        else{
            printf("Can not recognition!\n");
        }
    }
    return 0;
}

int InsertSearch(struct number *phead){
    unsigned short go = 0;
    int temp;
    char ch[5];
    struct number *ptemp,*pnew,*pend;
    ptemp = phead;
    if(ptemp->next == NULL){
        printf("Can not find any nodes!\n");
        return -1;
    }
    printf("Please input the information you want to search.\n");
    scanf("%d",&temp);
    while(1){
        while(1){
            if(ptemp->next == NULL){
                printf("Can not find the information!\n");
                go = 1;
                break;
            }
            ptemp = ptemp->next;
            if(temp == ptemp->num){
                printf("Is this the information you want?:%d (To input 'Y' to confirm.)\n",ptemp->num);
                scanf("%s",ch);
                if(strcmp(ch,"y") == 0||strcmp(ch,"Y") == 0){
                    pend = ptemp->next;
                    pnew = (struct number *)malloc(sizeof(struct number));
                    ptemp->next = pnew;
                    pnew->next = pend;
                    printf("Please input a number!\n");
                    scanf("%d",&pnew->num);
                    go = 1;
                    break;
                }
            }
        }
        if(go == 1){
            break;
        }
    }
    if(go == 0){
        printf("Can not find the information you want!");
    }
    return 0;
}

int Delete(struct number *phead){
    unsigned short go = 0;
    int temp;
    char ch[5];
    struct number *ptemp,*pend;
    ptemp = phead;
    if(ptemp->next == NULL){
        printf("Can not find any nodes!\n");
        return -1;
    }
    printf("Please input the information you want to delete.\n");
    scanf("%d",&temp);
    while(1){
        while(1){
            if(ptemp->next == NULL){
                printf("Can not find the information!\n");
                go = 1;
                break;
            }
            pend = ptemp;
            ptemp = ptemp->next;
            if(temp == ptemp->num){
                printf("Is this the information you want?:%d (To input 'Y' to confirm.)\n",ptemp->num);
                scanf("%s",ch);
                if(strcmp(ch,"y") == 0||strcmp(ch,"Y") == 0){
                    pend->next = ptemp->next;
                    free(ptemp);
                    go = 1;
                    break;
                }
            }
        }
        if(go == 1){
            break;
        }
    }
    if(go == 0){
        printf("Can not find the information you want!");
    }
    return 0;
}


int Reverse(struct number *phead){
    if(phead->next == NULL){
        printf("Can not find any nodes!\n");
        return -1;
    }
    struct number *ptemp,*pend,*pchange1,*pchange2;
    unsigned short i,j,len = 0,times;
    ptemp = phead->next;
    while(ptemp != NULL){
        ptemp = ptemp->next;
        len++;
    }
    if(len == 1){
        return 0;
    }
    if(len == 2){
        ptemp = phead->next;
        phead->next = phead->next->next;
        phead->next->next = ptemp;
        ptemp->next = NULL;
        return 0;
    }
    times = len/2;
    for(i = 0;i < times;i++){
        ptemp = phead;
        for(j = 0;j < i;j++){
            ptemp = ptemp->next;
        }
        pchange1 = ptemp;
        ptemp = ptemp->next;
        pend = phead;
        for(j = 0;j < len;j++){
            pend = pend->next;
        }
        pchange2 = phead;
        for(j = 0;j <len - 1;j++){
            pchange2 = pchange2->next;
        }
        len--;
        pchange1->next = pend;
        pchange1 = pend->next;
        pend->next = ptemp->next;
        pchange2->next = ptemp;
        ptemp->next = pchange1;
    }
    return 0;
}

int Search(struct number *phead){
    unsigned short go = 0;
    int temp;
    char ch[5];
    struct number *ptemp;
    ptemp = phead;
    if(ptemp->next == NULL){
        printf("Can not find any nodes!\n");
        return -1;
    }
    printf("Please input the information you want to search.\n");
    scanf("%d",&temp);
    while(1){
        while(1){
            if(ptemp->next == NULL){
                printf("Can not find the information!\n");
                go = 1;
                break;
            }
            ptemp = ptemp->next;
            if(temp == ptemp->num){
                printf("Is this the information you want?:%d (To input 'Y' to confirm.)\n",ptemp->num);
                scanf("%s",ch);
                if(strcmp(ch,"y") == 0||strcmp(ch,"Y") == 0){
                    go = 1;
                    break;
                }
            }
        }
        if(go == 1){
            break;
        }
    }
    if(go == 0){
        printf("Can not find the information you want!");
    }
    return 0;
}

int Destory(struct number *phead){
    struct number *ptemp,*pend;
    if(phead->next == NULL){
        printf("Can not find any nodes!\n");
        return -1;
    }
    ptemp = phead->next;
    pend = ptemp->next;
    phead->next = NULL;
    while(pend != NULL){
        free(ptemp);
        ptemp = pend;
        pend = pend->next;
    }
    free(ptemp);
    free(pend);
    return 0;
}
