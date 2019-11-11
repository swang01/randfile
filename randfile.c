#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include "randheader.h"

int rand_num(){
  int fd = open("/dev/random", O_RDONLY);
  if (fd < 0){
    printf("errno %d error: %s\n", errno, strerror(errno));
  }
  int buff;
  read(fd, &buff, sizeof(int));
  if(errno){
    printf("Error: %d\n", errno);
  }
  close(fd);
  return buff;
}
