#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo) {
  if (signo==SIGINT) {
    printf("\nwow, it seems that SIGINT got hit.\n");
    exit(EXIT_SUCCESS);
  } else if (signo==SIGUSR1) {
    printf("my daddy's pid is %d\n", getppid());
  }
}


int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  
  while (1) {
    printf("my pid be: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
  
