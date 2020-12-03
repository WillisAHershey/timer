//Willis A. Hershey
//WillisAHershey@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

int main(int args,char *argv[]){
  //This program expects at least one non-program-name argument, or it aborts with error message
  if(args<2){
	fprintf(stderr,"USAGE: %s exec arg1 arg2 ...\n",argv[0]);
	exit(EXIT_FAILURE);
  }
  //Produces an array of string-lengths of the arguments as well as a sum of their lengths
  size_t len=0;
  size_t *lens=malloc(sizeof(size_t)*(args-1));
  for(int c=1;c<args;++c){
	size_t l=strlen(argv[c]);
	lens[c-1]=l;
	len+=l+1;
  }
  //Allocates a string large enough for every argument with a space between each
  char *command=malloc(len);
  //And fills that string with the arguments
  char *pt=command;
  for(int c=1;c<args;++c){
	strcpy(pt,argv[c]);
	pt+=lens[c-1];
	*pt=' ';
	++pt;
  }
  *(pt-1)='\0';
  //Frees array of lengths
  free(lens);
  //Gets process-id of this execution environment
  pid_t pid=getpid();
  //Prints process id and command to stdout
  printf("==%ld==  =====Command is: %s\n",(long)pid,command);
  struct timeval s,e;
  printf("==%ld==  =====Starting timer now=====\n",(long)pid);
  //Gets timestamp before...
  gettimeofday(&s,NULL);
  system(command);
  //...and after command is executed
  gettimeofday(&e,NULL);
  //Computes the difference
  unsigned long seconds=e.tv_sec-s.tv_sec;
  signed long mils=e.tv_usec-s.tv_usec;
  free(command);
  if(mils<0){
	--seconds;
	mils+=1000000;
  }
  //And prints it as a decimal representing number of seconds
  printf("==%ld==  =====%lu.%06ld seconds elapsed=====\n",(long)pid,seconds,mils);
}
