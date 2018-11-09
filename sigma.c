#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>

static void sighandler(int signo) {
  if (signo==SIGINT){
    printf("\nwow, it seems that SIGINT got hit.\n");
    int copy = open("closure.txt",O_WRONLY|O_CREAT,0644);
    write(copy, "file closed with SIGINT\n", 25);
    close(copy);
    exit(EXIT_SUCCESS);
  } else if (signo==SIGUSR1) {
    printf("my daddy's pid is: %d\n", getppid());
  }
}


int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  
  while (1) {
    printf("my pid is: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
  
