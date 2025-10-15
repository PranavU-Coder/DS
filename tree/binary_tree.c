#include "Queue.h"

struct Node *root=NULL;

void treecreate(){
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);
    printf("Enter root value:");
    scanf("%d",&x);
    root=(struct Node*)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("Enter left child of %d:",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("Enter right child of %d:",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}
void Preorder(struct Node *p){
    if(p){
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void Levelorder(struct Node *p){
    struct Queue q;
    create(&q,50);
    enqueue(&q,p);
    while(!isEmpty(q)){
        p=dequeue(&q);
        printf("%d ",p->data);
        if(p->lchild){
            enqueue(&q,p->lchild);
        }
        if(p->rchild){
            enqueue(&q,p->rchild);
        }
    }
}

int count(struct Node *p) {
    int x, y;
    if (p != NULL) {
        x = count(p->lchild);
        y = count(p->rchild);
        return x + y + 1;
    }
    return 0;
}

int countDegree1(struct Node *p) {
    int x, y;
    if (p != NULL) {
        x = countDegree1(p->lchild);
        y = countDegree1(p->rchild);
        if ((p->lchild != NULL && p->rchild == NULL) || 
            (p->lchild == NULL && p->rchild != NULL))
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int countDegree2(struct Node *p) {
    int x, y;
    if (p != NULL) {
        x = countDegree2(p->lchild);
        y = countDegree2(p->rchild);
        if (p->lchild != NULL && p->rchild != NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}


int main(){
    treecreate();
    printf("Preorder:");
    Preorder(root);
    printf("\n");
    printf("Inorder:");
    Inorder(root);
    printf("\n");
    printf("Postorder:");
    Postorder(root);
    printf("\n");
    printf("Levelorder:");
    Levelorder(root);
    printf("\n");

    printf("Total number of nodes: %d\n", count(root));
    printf("Nodes with degree 1: %d\n", countDegree1(root));
    printf("Nodes with degree 2: %d\n", countDegree2(root));

}
