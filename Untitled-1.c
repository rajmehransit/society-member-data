#include<stdio.h>
#include<stdlib.h>
typedef struct Member
{
  int fno;
  char name[20];
  struct data{
     char phno[10];  
   }data[1];
   
}Member;


void create(){
     Member *s;
     FILE *fp;
     int n,i,j;
     printf("\nNO. of Member you want to add: ");
     scanf("%d",&n);
     s= (Member*)calloc(n,sizeof(Member));

     fp=fopen("mymember.txt","w");


     for(i=0;i<n;i++)
     {
       
       printf("Enter flate_no.of %d: ",i+1);
       scanf("%d",&s[i]);
       fflush(stdin);  
       printf("Enter the Name:");
       scanf("%[^\n]s",s[i].name);
       for(j=0;j<1;j++){
         printf("Enter  phone no. of member:",j+1);
         scanf("%s",&s[i].data[j].phno);
         
       }
       fwrite(&s[i],sizeof(Member),1,fp);
     }
     fclose(fp);
}
void display(){
  Member s1;
  FILE *fp;
  int j;
  fp=fopen("mymember.txt","r");
   while (fread(&s1,sizeof(Member),1,fp))
   {
      printf("\n%-5d%-20s",s1.fno,s1.name);
     for(j=0;j<1;j++){
       printf("%4s",s1.data[j].phno);
     }  
   }
     
    fclose(fp);

}
void append(){
  Member *s;
     FILE *fp;
     int n,i,j;
     printf("\nNO. of Member you want to add: ");
     scanf("%d",&n);
     s= (Member*)calloc(n,sizeof(Member));

     fp=fopen("mymember.txt","a");


     for(i=0;i<n;i++)
     {
       
       printf("Enter flate_no.of %d: ",i+1);
       scanf("%d",&s[i]);
       fflush(stdin);  
       printf("Enter the Name:");
       scanf("%[^\n]s",s[i].name);
       for(j=0;j<1;j++){
         printf("Enter  no. of member:",j+1);
         scanf("%s",&s[i].data[j].phno);
         
       }
       fwrite(&s[i],sizeof(Member),1,fp);
     }
     fclose(fp);

}
void recno(){
  Member s1;
  FILE *fp;
  fp=fopen("mymember.txt","r");
  fseek(fp,0,SEEK_END);
  int n= ftell(fp)/sizeof(Member);
  printf("\nno. of record=%d\n",n);
  fclose(fp);
}
void search(){
  Member s1;
  FILE *fp;
  int j,fno,found=0;
  fp=fopen("mymember.txt","r");
  printf("Enter Flate no. to search member:");
  scanf("%d",&fno);
   while (fread(&s1,sizeof(Member),1,fp))
   { 
      if(s1.fno == fno){
     found=1;
      printf("\n%-5d%-20s",s1.fno,s1.name);
     for(j=0;j<1;j++){
       printf("%4s",s1.data[j].phno);
     }
      }
   }
   if(!found)
    printf("\nRecord Not found\n");
     
    fclose(fp);
}
void update(){
  Member s1;
  FILE *fp,*fp1;
  int j,fno,found=0;
  fp=fopen("mymember.txt","r");
  fp1=fopen("temp.txt","w");
  printf("Enter Flate no. to search member to update data:");
  scanf("%d",&fno);
   while (fread(&s1,sizeof(Member),1,fp))
   { 
      if(s1.fno == fno){
       found=1;
        fflush(stdin);  
        printf("Enter the new Name:");
        scanf("%[^\n]s",s1.name);
        for(j=0;j<1;j++){
         printf("Enter phone new no. of member:",j+1);
         scanf("%s",&s1.data[j].phno);
        }
      }
      fwrite(&s1,sizeof(Member),1,fp1);
   } 
   fclose(fp);
   fclose(fp1);
   if(found){
     fp1=fopen("temp.txt","r");
     fp=fopen("mymember.txt","w");

     while (fread(&s1,sizeof(Member),1,fp1))
     {
       fwrite(&s1,sizeof(Member),1,fp);
     }
     
     fclose(fp1);
     fclose(fp);
   }
   else
    printf("\nRecord Not found\n");
}
void delete(){
  Member s1;
  FILE *fp,*fp1;
  int j,fno,found=0;
  fp=fopen("mymember.txt","r");
  fp1=fopen("temp.txt","w");
  printf("Enter Flate no. to search member to delete data:");
  scanf("%d",&fno);
   while (fread(&s1,sizeof(Member),1,fp))
   { 
      if(s1.fno == fno){
       found=1;
       
        }
        else
        fwrite(&s1,sizeof(Member),1,fp1);
   }
  

   fclose(fp);
   fclose(fp1);
   if(found){
     fp1=fopen("temp.txt","r");
     fp=fopen("mymember.txt","w");

     while (fread(&s1,sizeof(Member),1,fp1))
     {
       fwrite(&s1,sizeof(Member),1,fp);
     }
     
     fclose(fp1);
     fclose(fp);
   }
   else
    printf("\nRecord Not found\n");
}

int main(){
  int x;
  do {
    printf("\n1.CREATE");
    printf("\n2.DISPLAY");
    printf("\n3.APPEND");
    printf("\n4.NO. OF RECORD");
    printf("\n5.SEARCH");
    printf("\n6.update");
    printf("\n7.delete");
    printf("\n0.EXIT");
    
    printf("\nEnter your Choice:");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
      create();
    break;
    case 2:
      display();
    break;
    case 3:
      append();
    break;
    case 4:
      recno();
    break;
    case 5:
      search();
    break;
    case 6:
      update();
    break;
     case 7:
      delete();
    break;
    }

   } while (x!=0);
    
   return 0;
    
}
