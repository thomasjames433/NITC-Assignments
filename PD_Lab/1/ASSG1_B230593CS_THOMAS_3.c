#include <stdio.h>
#include <string.h>

int main(){
  int n;
  printf("Enter number ");
  scanf("%d",&n);
  struct Product{
    char name[20];
    int price;
  };
  struct Product s[n];
  for(int i=0;i<n;i++){
    scanf("%s",s[i].name);
    scanf("%d",&s[i].price);
  }
  for(int i=0;i<n;i++){
  int min=s[i].price;
  int c=0;
  int a;
  char new[20];
  for(int j=i+1;j<n;j++){
    if(s[j].price<min){
    min= s[j].price;
    strcpy(new,s[j].name);
    a=j;
    c++;
    }
  }
  
    if(c!=0){
    s[a].price=s[i].price;
    strcpy(s[a].name,s[i].name);
    s[i].price=min;
    strcpy(s[i].name,new);
  }

}
 for(int i=0;i<n;i++){
  printf("%s ",s[i].name);
}
printf(" \n");
for(int i=0;i<n;i++){
  printf("%d ",s[i].price);

}
}