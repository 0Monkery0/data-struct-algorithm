#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int data;
    struct stack *next;
};

unsigned short state = 1;

int Create(struct stack *phead);
struct stack *PushStack(struct stack *top);
int PopState(struct stack *phead,struct stack *top);
int Destroy(struct stack *phead);
struct stack *ResetTop(struct stack *phead);
int Display(struct stack *phead);

int main(){
    char temp[5];
    struct stack *top,*phead;
    phead = (struct stack *)malloc(sizeof(struct stack));
    phead->next = NULL;
    top = phead;

    while(1){
        printf("Please select:\n1.Create Stack\n2.Push Stack\n3.Pop Stack\n4.Display the Stack\n5.Exit\nSelect:");
        scanf("%s",temp);
        if(strcmp(temp,"1") == 0){
            Destroy(phead);
            Create(phead);
            top = ResetTop(phead);
        }
        else if(strcmp(temp,"2") == 0){
            top = PushStack(top);
        }
        else if(strcmp(temp,"3") == 0){
            PopState(phead,top);
            top = ResetTop(phead);
        }
        else if(strcmp(temp,"4") == 0){
            Display(phead);
        }
        else if(strcmp(temp,"5") == 0){
            printf("Thank to use!\n");
            break;
        }
        else{
            printf("Can not be recognition!\n\n");
        }
    }

    return 0;
}

int Create(struct stack *phead){
    char temp[5];
    struct stack *ptemp,*pnew;
    ptemp = phead;
    printf("\n");
    while(1){
        printf("Would you like to create a new stack node?(Y/N)\n");
        scanf("%s",temp);
        if(strcmp(temp,"Y") == 0||strcmp(temp,"y") == 0){
            pnew = (struct stack *)malloc(sizeof(struct stack));
            pnew->next = NULL;
            ptemp->next = pnew;
            ptemp = ptemp->next;
            printf("Pleaes input the information.\n");
            scanf("%d",&pnew->data);
        }
        else if(strcmp(temp,"N") == 0||strcmp(temp,"n") == 0){
            printf("\n");
            break;
        }
        else{
            printf("Can not be recognition!\n\n");
        }
    }
    return 0;
}

struct stack *PushStack(struct stack *top){
    char temp[5];
    struct stack *pnew;
    printf("\n");
    while(1){
        printf("Would you like to push a stack node?(Y/N)\n");
        scanf("%s",temp);
        if(strcmp(temp,"Y") == 0||strcmp(temp,"y") == 0){
            pnew = (struct stack *)malloc(sizeof(struct stack));
            pnew->next = NULL;
            top->next = pnew;
            top = top->next;
            printf("Pleaes input the information.\n");
            scanf("%d",&pnew->data);
            if(state == 1){
                state = 0;
            }
        }
        else if(strcmp(temp,"N") == 0||strcmp(temp,"n") == 0){
            printf("\n");
            break;
        }
        else{
            printf("Can not be recognition!\n\n");
        }
    }
    return top;
}

int PopState(struct stack *phead,struct stack *top){
    printf("\n");
    if(state == 1){
        printf("The stack is empty!\n\n");
        return 0;
    }
    int data;
    char temp[5];
    struct stack *pPop,*ptemp;
    ptemp = phead;

    printf("Would you like to pop a stack node?(Y/N)\n");
    scanf("%s",temp);
    if(strcmp(temp,"Y") == 0||strcmp(temp,"y") == 0){
        while(ptemp->next != top){
            ptemp = ptemp->next;
        }
        data = top->data;
        ptemp->next = NULL;
        free(top);
        printf("Done!\n");
    }
    else if(strcmp(temp,"N") == 0||strcmp(temp,"n") == 0){
        ;
    }
    else{
        printf("Can not be recognition!\n");
    }
    printf("\n");

    return data;
}

int Destroy(struct stack *phead){
    if(phead->next == NULL){
        return -1;
    }
    struct stack *pend,*pfree;
    pfree = phead->next;
    pend = pfree->next;
    phead->next = NULL;
    while(pend != NULL){
        free(pfree);
        pfree = pend;
        pend = pend->next;
    }
    free(pfree);
    return 0;
}

struct stack *ResetTop(struct stack *phead){
    struct stack *ptemp;
    ptemp = phead;
    while(ptemp->next != NULL){
        ptemp = ptemp->next;
    }
    if(ptemp == phead){
        state = 1;
    }
    else{
        state = 0;
    }
    return ptemp;
}

int Display(struct stack *phead){
    struct stack *ptemp;
    ptemp = phead->next;
    printf("\n|bottom|\n");
    while(ptemp != NULL){
        printf("|------|\n");
        printf("|%-6d|\n",ptemp->data);
        ptemp = ptemp->next;
    }
    printf("|------|\n|-top--|\n\n");
    return 0;
}
