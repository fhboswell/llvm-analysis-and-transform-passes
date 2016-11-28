

#include<stdio.h>

void foo(); 
void bar();


#include <stdio.h>

int main()
{
    
    printf("\nTarget Program: Hello Begin llvm test program\n \n");
    
    int test = 4;
    int test2 = 4;
    test = test + test2;
    printf("\nTarget Program: Defined some ints and did some addition.\n \n");
    
    foo();
    printf("\nTarget Program: Called a function.\n \n");
    
    while(test >=1){
        test =  test - 1;
        bar();
    }
    printf("\nTarget Program: At the end.\n \n");
    return 0;
}


void foo()
{
    int temp = 1;
    int temp2 = 2;
    temp = temp + temp2;
    printf("\nTarget Program: At the end of function is run before the loop.\n \n");
}


void bar()
{
    int temp = 1;
    int temp2 = 2;
    temp = temp + temp2;
    printf("\nTarget Program: This function is run every iteration of a loop.\n \n");
}
