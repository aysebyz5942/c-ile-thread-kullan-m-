                                                   //öğrenci_no:[181213053]
                                                   // Ad:[Ayşe Beyza Ünal]
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc,char *argv[]) 
{ 
    int n=atoi(argv[1]);
    srand(time(NULL));
    int rdeger;
    for(int i=0;i<n;i++) 
    {   
        sleep(2);
        rdeger=rand()%100;
        if(fork() == 0) 
        {   
            printf("%d process /random deger: %d\n",i+1,rdeger); 
            exit(0); 
        } 
    } 
    for(int i=0;i<n;i++) wait(NULL);
    printf("tamamlandi...\n"); sleep(2); 
}