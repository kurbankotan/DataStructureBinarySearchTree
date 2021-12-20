//ÝKÝLÝ ARAMA AÐACI ÝÞLEMLERÝ

#include <stdio.h>
#include <stdlib.h>
 
struct tree
{
          struct tree *sol;
          int bilgi;
          struct tree *sag;
};


void ekranTemizle();
void menu();
void Ekle(struct tree **ptr,int data);
void Ara(struct tree **ptr,int data);
void Sil(struct tree **ptr,int data);
void preorder(struct tree *ptr);
void inorder(struct tree *ptr);
void postorder(struct tree *ptr);

 
void main()
{
          menu();
}


void menu()
{
	      struct tree *root = NULL;
          int data,sec, sec1;
          char secim,secim1;
          ekranTemizle();
          
    	do 
          {
                   printf("\n________Agac islemleri_________\n\n");
                   
                   printf("1.Ekle.\n");
                   printf("2.Sil.\n");
                   printf("3.Ara.\n");
                   printf("4.Listele.\n");
                   printf("5.Cik.\n");
                   printf("\nSeciminizi giriniz:");
                   
                   scanf("%d",&sec);
                   switch(sec)
                    {
                             case 1: printf("\nEklenecek dugum degerini giriniz  : ");
                                      scanf("%d",&data);
                                      Ekle(&root,data);
                                      break;
 
                             case 2: printf("\nSilinecek dugum degerini giriniz    :");
                                      scanf("%d",&data);
                                      Sil(&root,data);
                                      break;
                              
							case 3: printf("\nAranacak dugum degerini giriniz   :");
                                      scanf("%d",&data);
                                      Ara(&root,data);
                                      break;          
                                      
 
                            case 4: printf("\n\n1-Preorder\n");
                                      printf("2-Inorder\n");
                                      printf("3-Postorder\n");
                                      printf("\nSeciminizi giriniz: ");
                                      scanf("%d",&sec1);
                                      printf("\n\nSirali Liste:  ");
                                      
                                      switch(sec1)
                                      {
                                                case 1: preorder(root); 
                                                            break;
 
                                                case 2: inorder(root);
                                                            break;
 
                                                case 3: postorder(root);
                                                            break;
                                      }
                                      break;
                             default: exit(0);
                   }
                   
                   fflush(stdin);
          }while(sec!=5);
}


void ekranTemizle() 
{
    //Windows icin
    system("cls");
    
    //Linux icin
    //system("clear");
}
 

 
void Ekle(struct tree **ptr,int data)
{
          if(*ptr==NULL)   // Aðaç boþssa
          {
                   *ptr=(struct tree *)malloc(sizeof(struct tree));
                   (*ptr)->sol=(*ptr)->sag=NULL;
                   (*ptr)->bilgi=data;
                   return;
 
          }
          else
          {
                   if(data<(*ptr)->bilgi) //Küçükse sola ekle
                   {
                             Ekle(&((*ptr)->sol),data);
                   }
                   else               // Büyükse saða ekle
                   {
                             Ekle(&((*ptr)->sag),data);
                   }
                   return;
          }
}
 
 
 
 void Ara(struct tree **ptr,int data)
 
{
          if(*ptr==NULL)   // Aðaç boþssa
          {
                   printf("\nAradiginiz dugum agacta yok ya da agac bos\n");
                   return;
 
          }
          else
          {        if(data == (*ptr)->bilgi)
                       printf("\nAradiginiz deger agacta var");
                   else
				        if(data<(*ptr)->bilgi) //Küçükse soldan aramaya devam et
                            {
                                  Ara(&((*ptr)->sol),data);
                            }
                       else               // Büyükse saðdan aramaya devam et
                           {
                                  Ara(&((*ptr)->sag),data);
                           }
                   return;
          }
}
 
 

 
void Sil(struct tree **ptr,int data)
{
          struct tree *ilerle,*gerile,*temp;
          if(*ptr==NULL)
          {
                   printf("\nAgac Bos..............n");
                   return;
          }
          else
          {
                   ilerle=*ptr;
                   gerile=ilerle;
                   while(ilerle->bilgi!=data)
                   {
                             gerile=ilerle;
                             if(data<ilerle->bilgi)
                             {
                                      ilerle=ilerle->sol;
                             }
                             else
                             {
                                      ilerle=ilerle->sag;
                             }
                   }
 
                   if(ilerle->sol!=NULL&&ilerle->sag!=NULL)
                   {
                             temp=ilerle->sag;
                             while(temp->sol!=NULL)
                             {
                                      gerile=temp;
                                      temp=temp->sol;
                             }
                             ilerle->bilgi=temp->bilgi;
                             ilerle=temp;
                   }
 
                   if(ilerle->sol==NULL&&ilerle->sag==NULL)
                   {
                             if(gerile->sag==ilerle)
                             {
                                      gerile->sag=NULL;
                             }
                             else
                             {
                                      gerile->sol=NULL;
                             }
                             free(ilerle);
                             return;
                   }
 
                   if(ilerle->sol==NULL&&ilerle->sag!=NULL)
                   {
                             if(gerile->sol==ilerle)
                             {
                                      gerile->sol=ilerle->sag;
                             }
                             else
                             {
                                      gerile->sag=ilerle->sag;
                             }
                             free(ilerle);
                             return;
                   }
 
                   if(ilerle->sol!=NULL&&ilerle->sag==NULL)
                   {
                             if(gerile->sol==ilerle)
                             {
                                      gerile->sol=ilerle->sol;
                             }
                             else
                             {
                                      gerile->sag=ilerle->sol;
                             }
                             free(ilerle);
                             return;
                   }
          }
}
 
 
void preorder(struct tree *ptr)
{
          struct tree *ilerle;
          ilerle=ptr;
          
          if(ilerle != NULL)
          {
                   printf(" %d ",ilerle->bilgi);
                   preorder(ilerle->sol);
                   preorder(ilerle->sag);
          }
          else
                   return;
 
}
 
 
void inorder(struct tree *ptr)
{
          struct tree *ilerle;
          ilerle=ptr;
          
          if(ilerle!= NULL)
          {
                   inorder(ilerle->sol);
                   printf(" %d ",ilerle->bilgi);
                   inorder(ilerle->sag);
          }
          else
          return;
}
 
 
void postorder(struct tree *ptr)
{
          struct tree *ilerle;
          ilerle=ptr;
 
          if(ilerle != NULL)
          {
                   postorder(ilerle->sol);
                   postorder(ilerle->sag);
                   printf(" %d ",ilerle->bilgi);
          }
          else
                   return;
}
 
