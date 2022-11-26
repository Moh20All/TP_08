#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>
//Definition de la structure
   typedef struct node
    {
      int val;
      struct node *link,*prec;
    }node;
    node *Tete,*temp,*Tet1,*ink;
    int i=1,alt;
//Def de fonction de creation

node *creation(int n ){
//La fonction de creation de "Nodes"
node * HEAD=NULL;
node * TEMP=NULL;
node * P=NULL;

for(int i=0;i<n;i++){

    TEMP=(node*)malloc(sizeof(node));
    printf("Entrer la valeur %d \n",i+1);
    scanf("%d",&(TEMP->val));
    TEMP->link=NULL;
    TEMP->prec=NULL;
    if(HEAD==NULL){
        HEAD=TEMP;
    }else{

    P=HEAD;
    while(P->link != NULL){
        P = P->link;
    }//Loop
    P->link=TEMP;
    TEMP->prec=P;

    }//else


}
   return HEAD;
}
// fonction de occurance
void display(node *HEAD){

node * P=HEAD;

    while(P!=NULL)
    {
       if((P->link)!=NULL)
       printf("%d<->",P->val);
       if((P->link)==NULL)
       printf("%d",P->val);
       P=P->link;
    }



}
//
 void display1(node *HEAD){

node * P=HEAD;
node * Q=NULL;

    while(P!=NULL)
    {
       //printf("%d->",P->val);
       Q=P;
       P=P->link;

    }

   while(Q!=NULL)
    {
       if((Q->prec)!=NULL)
       printf("%d<->",Q->val);
       if((Q->prec)==NULL)
       printf("%d",Q->val);
       //printf("%d<->",Q->val);
       Q=Q->prec;

    }



}
node *inv1(node *tete){
node * c=tete;
node * p=tete;
while(p!=NULL){
c=p->link;
p->link=p->prec;
p->prec=c;
tete=p;
p=c;
}
return tete;
}
//Fonction d'ajout node pour la list de resault
node *push(node* head,int val){
node * newp = (node*)malloc(sizeof(node));
newp->val=val;
newp->link=head;
head=newp;
return head;

}
//Recherche de element
bool reche(int x,node *EL){

node *P=EL;
bool ch=false;
    while(P!=NULL)
    {
       if((P->val)==x){
       ch=true;
       return ch;
       }else{
       P=P->link;
       }

    }
}

//Recherche de element
int reche1(int x,node *EL){
int v=0;
node *P=EL;

    while(P!=NULL)
    {
       if((P->val)==x){
       v++;
       }
       P=P->link;


    }
    return v;
}

//Ajout un element
void insert(node *q,node *l,int p){
   printf("Entrer la valeur de element a inserer : ");
   scanf("%d",&(q->val)) ;
   node *temp =l  ;
   //node *tt;
   for(int i=2; i < p; i++){
   if(temp->link != NULL){
    //tt=temp;
   temp = temp->link;
   }
   }
   q->link=temp->link;
   (temp->link)->prec=q;
   temp->link=q;
   q->prec=temp;
    }
//inserer au debut
node* insert_debut(node* head, int new_ )
{
    /* 1. allocate node */
    node* new_node= (node*)malloc(sizeof(node));

    /* 2. put in the data  */
    new_node->val = new_;

    /* 3. Make next of new node as head and previous as NULL
     */
    new_node->link = head;
    new_node->prec = NULL;

    /* 4. change prev of head node to new node */
    if (head != NULL)
        head->prec = new_node;

    /* 5. move the head to point to the new node */
    head= new_node;
    return head;
}
//inserer a la fin
    void insert_fin(node** head, int new_)
{
    /* 1. allocate node */
    node* new_node= (node*)malloc(sizeof(node));

    node* last = *head; /* used in step 5*/

    /* 2. put in the data  */
    new_node->val = new_;

    /* 3. This new node is going to be the last node, so
          make next of it as NULL*/
    new_node->link = NULL;

    /* 4. If the Linked List is empty, then make the new
          node as head */
    if (*head == NULL) {
        new_node->prec = NULL;
        *head = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->link != NULL)
        last = last->link;

    /* 6. Change the next of last node */
    last->link = new_node;

    /* 7. Make last node as previous of new node */
    new_node->prec = last;

    return;
}
//Deletion de node
void delete_pos(node *Tete,int pos)
{
        int i;
        struct node *temp,*ptr;
        if(Tete==NULL)
        {
                printf("\nLa liste est vide:\n");
                exit(0);
        }
        else
        {

                if(pos==0)
                {
                        ptr=Tete;
                        Tete=Tete->link ;
                        printf("L'element a supprimer est:%d\t",ptr->val  );
                        free(ptr);
                }
                else
                {
                        ptr=Tete;
                        for(i=1;i<pos;i++) {
                                temp=ptr; ptr=ptr->link ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition est introvable:\n");
                                        return;
                                }
                        }
                        temp->link =ptr->link ;
                        printf("l'element supprimer est:%d\t",ptr->val );
                        free(ptr);
                }
        }
}


//Tri par bulle
//swap fonction
 node* swap(node* ptr1,node* ptr2)
{
    node* tmp = ptr2->link;
    ptr2->link = ptr1;
    ptr1->link = tmp;
    return ptr2;
}

//fonction de tri

int bulle_tri(node** head, int count)
{
    struct node** h;
    int i, j, swapped;

    for (i = 0; i <= count; i++)
    {

        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++)
        {

            node* p1 = *h;
            node* p2 = p1->link;

            if (p1->val > p2->val)
            {

                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->link;
        }

        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}
//deletion de debut
void delete_debut()
{
        node *ptr;
        if(ptr==NULL)
        {
                printf("\nList is Empty:\n");
                return;
        }
        else
        {
                ptr=Tete;
                Tete=Tete->link ;
                Tete->prec=NULL;
                printf("\nThe deleted element is :%d\t",ptr->val);
                free(ptr);
        }
}
//deletion a fin
void delete_fin()
{
        struct node *temp,*ptr;
        if(Tete==NULL)
        {
                printf("\nList is Empty:");
                exit(0);
        }
        else if(Tete->link ==NULL)
        {// en cas de 1 seul element dans la liste
                ptr=Tete;
                Tete=NULL;
                printf("\nThe deleted element is:%d\t",ptr->val);
                free(ptr);
        }
        else
        {
                ptr=Tete;
                while(ptr->link!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->link;
                }
                temp->link=NULL;
                printf("\nThe deleted element is:%d\t",ptr->val);
                free(ptr);
        }
}


int max_list(){
struct node *temp,*ptr;
node * P=Tete;
int x=0,pos=0,pos_1=0;
    while(P!=NULL)
    {
       if((P->val)>x){
       x=(P->val);
       pos_1=pos+1;
       }else{
       P=P->link;
       pos=pos+1;
       }

    }
//delete_pos(Tete,pos);
//printf("Le nombre max %d \n",x);
//printf("Le nombre  %d ",ptr->val);
   //printf("IF %d\n",x);
alt=x;
return pos_1;

}

int max_j(int jj){
struct node *temp,*ptr;
node * P=Tete;
int x=0,pos=1;
    while(P!=NULL)
    {
       if((P->val)==jj){
       return pos;

       }else{
       P=P->link;
       }
     pos=pos+1;
    }
//delete_pos(Tete,pos);
//printf("Le nombre max %d \n",x);
//printf("Le nombre  %d ",ptr->val);
   //printf("IF %d\n",x);
return pos;

}


int recha_val(node *tot,int pos){
int i=1;
while(i<pos){
    tot=tot->link;
    i=i+1;
}
return tot->val;
}
//tri par supression
node* tri_list(){
node *P,*ptr,*temp,*tat=Tete;
int x=0,pos=1,i;
Tet1=NULL;
i=0;
while(tat!=NULL){
    ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL)
         printf("NULL\n");
    pos=max_list();
    x=recha_val(Tete,pos);
    deleteN(&Tete,pos);
    ptr->val=x;
if(P == NULL){
P=ptr;
Tet1=ptr;
    printf("IF\n");

}else{
    P->link=ptr;
    P=P->link;
    printf("Else\n");

}

}

return Tet1;
}

void deleteN(node** head, int position)
{
    node* temp;
    node* prev;
    temp = *head;
    prev = *head;
    for (int i = 0; i < position; i++) {
        if (i == 0 && position == 1) {
            *head = (*head)->link;
            ((*head)->link)->prec=NULL;
            free(temp);
        }
        else {
            if (i == position - 1 && temp) {
                prev->link = temp->link;
                (temp->link)->prec=prev;
                free(temp);
            }
            else {
                prev = temp;

                // Position was greater than
                // number of nodes in the list
                if (prev == NULL)
                    break;
                temp = temp->link;
            }
        }
    }
}

void deleteN1(node** head, int position)
{
    node* temp;
    node* prev;
    temp = *head;
    prev = *head;
    for (int i = 0; i < position; i++) {
        if (i == 0 && position == 1) {
            *head = (*head)->link;
            free(temp);
        }
        else {
            if (i == position - 1 && temp) {
                prev->link = temp->link;
                free(temp);
            }
            else {
                prev = temp;

                // Position was greater than
                // number of nodes in the list
                if (prev == NULL)
                    break;
                temp = temp->link;
            }
        }
    }
}

//inverser
node *inv(node *head){
node *Queue,*p;

    Queue=head->link;
    head->link=NULL;
    while(Queue != NULL){
    p=Queue;
    Queue=Queue->link;
    p->link=head;
    head=p;
    }

return head;
}
int main()
{
    node *HEAD=NULL,*P=NULL,*TEMP=NULL,*Tete1;
    int n,x,d,pos;

     int choice;
        while(1){

                printf("\n                MENU                             \n");
                printf("\n 1.Cree un liste     \n");
                printf("\n 2.afficher la liste    \n");
                printf("\n 3.Rechercher un element   \n");
                printf("\n 4.Inserer un element   \n");
                printf("\n 5.supprimer un element    \n");
                //printf("\n 6.Trier la liste en utiliser Bulle       \n");
                //printf("\n 7.Trier la liste en utiliser La deletion       \n");
                printf("\n 8.Inverser la liste       \n");
                printf("\n 9.inverser la liste        \n");
                printf("\n 10.Calculer le nombre de occurance       \n");
                printf("\n 11.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                               printf("Voulez vous entrer la taille de list : ");
                               scanf("%d",&n);
                               Tete=creation(n);
                                        break;
                        case 2:
                                        printf("\n");
                                        display(Tete);
                                        printf("\n");
                                        display1(Tete);
                                        break;
                        case 3:
                               printf("\nEntrer l'element a rechercher");
                               scanf("%d",&x);
                               if(reche(x,Tete)==true)
                               printf("L'element est trouve\n");
                               else
                               printf("L'element ne trouve pas\n");
                                        break;
                        case 4:
                               system("cls");
                               printf("\n1.inserer a le debut\n");
                               printf("\n2.inserer a certain position\n");
                               printf("\n3.inserer a la fin\n");
                               scanf("%d",&choice);
                               switch(choice){
                                case 1:
                                    printf("Entrer la valeur de element a ajout : ");
                                    scanf("%d",&pos);
                                    Tete=insert_debut(Tete,pos);
                                    break;
                                case 2:
                                    temp=(node*)malloc(sizeof(node));
                                    temp->link=NULL;
                                    printf("entrer la position a inserer:");
                                    scanf("%d",&d);
                                    insert(temp,Tete,d);
                                        break;

                                case 3:
                                    printf("Entrer la valeur de element a ajout : ");
                                    scanf("%d",&pos);
                                    insert_fin(&Tete,pos);
                                    break;


                                        }
                                        break;


                        case 5:
                               system("cls");
                               printf("\n1.supprimer a le debut\n");
                               printf("\n2.supprimer a certain position\n");
                               printf("\n3.supprimer a la fin\n");
                               scanf("%d",&choice);
                               switch(choice){
                           case 1:
                            delete_debut();
                            break;
                           case 2:

                             printf("\nEntrer la valeur de node a supprimer:\t");
                             scanf("%d",&pos);
                             pos=max_j(pos);
                             printf("%d",pos);
                             deleteN(&Tete,pos);
                            //delete_pos(Tete,pos);
                            break;
                           case 3:
                            delete_fin();
                            break;


                               }
                               break;


                        case 6:
                                        bulle_tri(&Tete,n);
                                        printf("La liste est trier entrer 2 pour afficher la list");
                                        break;
                        case 7:
                                        display(Tet1);
                                        break;
                        case 8:
                                        Tete1=inv(Tete);
                                        Tete=Tete1;
                                        display(Tete1);
                                        break;
                        case 9:
                        TEMP=inv1(Tete);
                        Tete=TEMP;
                        display(TEMP);
                        break;
                        case 10:
                        printf("Entrer le var a rechercher  ");
                        scanf("%d",&pos);
                        pos=reche1(pos,Tete);
                        printf("Le nombre de occurance %d",pos);
                        break;
                        case 11:
                                        exit(0);
                                        break;
                        default:
                                        printf("n Wrong Choice:n");
                                        break;
                }
        }


    //creer La liste chainee

    //afficher La liste chainee

    //rechercher un element

    //inserer un element a certain position

    // afficher un lsite chainee

    //supprimer un element de certain position

    //afficher La liste chainee


    return 0;
}
