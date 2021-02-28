#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
void fork7(){
    if(fork()==0){
        printf("terminating child , PID=%d\n",getpid());
        exit(0);
    }
    else{
        printf("running parent , PID=%d\n",getpid());
        while(1)
             ;
    }
}

int main(int argc,char** argv){
     fork7();
}
