#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int minf(int x){
 int n = 1;
 int k = 3;
 int m = 0;
 bool c = false;
 int l = 0;
 while(x>2){
  if(++m>k){
   k++;
   m = 0;
   c = !c;
   if(c) l++;
   n -= 2*l;
   x--;
  }else{
   n += 2;
  }
 }
 return n;
}
int maxf(int x){
 int n = 1;
 int k = 3;
 int m = 0;
 bool c = false;
 int l = 0;
 while(x>2){
  if(++m>k){
   x--;
   if(x>2){
    k++;
    m = 0;
    c = !c;
    if(c) l++;
    n -= 2*l;
   }
  }else{
   n += 2;
  }
 }
 return n;
}
void space(int n){
 while(n-->0){
  printf(" ");
 }
}
void star(int n){
 while(n-->0){
  printf("*");
 }
}
void plank(int n){
 while(n-->0){
  printf("|");
 }
}

int main(int argc,char *argv[]){
 int n = atoi(argv[1]);
 int min = minf(n+1);
 int max = maxf(n+2);
 int length = max / 2;
 int k = 0;
 while(k++<n){
  int blokmin = minf(k+1);
  int blokmax = maxf(k+2);
  while(blokmin <= blokmax){
   int j = length - blokmin/2;
   space(j);
   star(blokmin);
   blokmin += 2;
   printf("\n");
  }
 }
 k = 0;
 while(k++<n){
  if(n%2==0){
   space(length - n/2 + 1);
  }else{
   space(length - n/2);
  }
  plank(n);
  printf("\n");
 }
 return 0;
}