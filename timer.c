#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int main(int args,char *argv[]){
  if(args<2){
	printf("USAGE: %s exec arg1 arg2 ...\n",argv[0]);
	exit(EXIT_FAILURE);
  }
  int len=0;
  int *lens=malloc(sizeof(int)*(args-1));
  for(int c=1;c<args;++c){
	int l=strlen(argv[c]);
	lens[c-1]=l;
	len+=l+1;
  }
  char *command=malloc(len);
  char *pt=command;
  for(int c=1;c<args;++c){
	strcpy(pt,argv[c]);
	pt+=lens[c-1];
	*pt=' ';
	++pt;
  }
  *(pt-1)='\0';
  free(lens);
  printf("Command is: %s\n",command);
  struct timeval s,e;
  printf("=====Starting timer now=====\n");
  gettimeofday(&s,NULL);
  system(command);
  gettimeofday(&e,NULL);
  unsigned long seconds=e.tv_sec-s.tv_sec;
  signed long mils=e.tv_usec-s.tv_usec;
  if(mils<0){
	--seconds;
	mils+=1000000;
  }
  printf("=====%lu.%06ld seconds elapsed=====\n",seconds,mils);
  free(command);
}
