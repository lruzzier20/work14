#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

void signalhandler(int signal){
  if(signal == SIGINT){
    int g=open("crashlog.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
    char* msg="Closed due to SIGINT";
    write(g,msg,20);
    exit(0);
  }
  if(signal == SIGUSR1){
    printf("%d\n\n\n\n",getppid());
  }
}

int main(){
  signal(SIGINT, signalhandler);
  signal(SIGUSR1, signalhandler);
  while(1){
    printf("PID = %d\n",getpid());
    sleep(1);
  }

  return 0;
}
