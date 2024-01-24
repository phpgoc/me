#include <stdio.h>
#include "24-swap.h"

typedef struct t{
   int a;
   int b;
   int c[10];
} T;

void print_t(T *t){
   printf("a: %d\n", t->a);
   printf("b: %d\n", t->b);
   printf("c: ");
   for(int i = 0; i < 10; i++){
      printf("%d ", t->c[i]);
   }
   printf("\n\n");
}

int main(){
   T t1,t2;
    t1.a = 1;
    t1.b = 2;
    t2.a = 3;
    t2.b = 4;
    for(int i = 0; i < 10; i++){
       t1.c[i] = i;
       t2.c[i] = 10 - i;
    }
    print_t(&t1);
    print_t(&t2);
    swap_without_tmp((void *)&t1, (void *)&t2, sizeof(T));
    print_t(&t1);
    print_t(&t2);

   return 0;
}