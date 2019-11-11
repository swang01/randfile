#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include "randheader.h"

int main() {
  int buff[10];
  printf("Generating random numbers:\n");
  int i;
  for(i = 0; i < 10; i++){
    buff[i] = rand_num();
    printf("random %d: %d\n", i, buff[i]);
  }
  int fd = open("file.txt", O_CREAT | O_WRONLY, 666);
  if (fd < 0){
    printf("errno %d error: %s\n", errno, strerror(errno));
  }
  printf("Writing numbers to file...\n\n");
  write(fd, buff, sizeof(buff));
  if (errno){
    printf("errno %d error: %s\n", errno, strerror(errno));
  }
  close(fd);

  printf("Reading numbers from file...\n");
  int file = open("file.txt", O_RDONLY);
  if (file < 0){
    printf("errno %d error: %s\n", errno, strerror(errno));
  }
  int new[10];
  printf("Verification that written values were the same:\n");
  fd = open("file", O_RDONLY);
  read(fd, new, sizeof(new));
  if (errno){
    printf("errno %d error: %s\n", errno, strerror(errno));
  }
  for(i = 0; i < 10; i++){
    printf("random %d: %d\n", i, new[i]);
  }
  close(file);
  return 0;
}
