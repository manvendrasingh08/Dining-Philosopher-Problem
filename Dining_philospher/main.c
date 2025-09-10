#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#define N 5
pthread_mutex_t forks[5];


void signal_handler(int sig){
    char msg [] = "\nAll philosphers will be leaving the table \n";
    write(STDOUT_FILENO, msg, strlen(msg));
    exit(0);
}

void* eating_func(void* args){
    
    int i = *((int*)args);
    int left = i;
    int right = (i+1)%N;
   
    while(1){
        
        printf("The philospher %d is thinking\n", i);
        sleep(1);
        
        pthread_mutex_lock(&forks[left]);
        printf("Philospher %d acquired left spoon (number : %d)\n", i, left);
        
       if(pthread_mutex_trylock(&forks[right])==0){
        printf("Philospher %d aquired right spoon (number : %d)\n", i, right);       
       
        printf("Philospher %d will eat now fior 1 sec\n", i);
        sleep(1);
        
               
        pthread_mutex_unlock(&forks[right]);
       }
       else{
        printf("The %d spoon is held by the other philospher.\nThe spoon %d will be now released....\n",i, i);
       }
       
       pthread_mutex_unlock(&forks[left]);
       
    }
}

int main(){
    
     
     if(signal(SIGINT, signal_handler) == SIG_ERR){
         perror("sigbnal is failed");
         return 1;
    }
    
    pthread_t philosphers[N];
    
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    
    for(int i = 0; i< N ; i++){
        pthread_mutex_init(&forks[i], NULL);
    }
    
    for(int i = 0; i < N; i++){
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&philosphers[i], &attr, eating_func, (void*)id);
    }    
    
    while(1){
        pause();
    }
    
    return 0;
}