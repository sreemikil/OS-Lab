#include<stdio.h>

#include<unistd.h>

int main()

{

 int pipefds1[2],pipefds2[2];

 int returnstatus1,returnstatus2;

 int pid;

 char pipe1writemsg[20];

 char pipe2writemsg[20];

 printf("Enter the message that is needed to written by parent and child:\n");

 fgets(pipe1writemsg,20,stdin);

 fgets(pipe2writemsg,20,stdin);

 char readmessage[20];

 returnstatus1=pipe(pipefds1);

 if(returnstatus1==-1)

 {

  printf("Unable to create pipe1\n");

  return 1;

 }

 returnstatus2=pipe(pipefds2);

 if(returnstatus2==-1)

 {

  printf("Unable to create pipe2\n");

  return 1;

 }

 pid=fork();

 if(pid!=0)

 {

  close(pipefds1[0]);

  close(pipefds2[1]);

  printf("In Parent: Writing to pipe1 message is %s\n",pipe1writemsg);

  write(pipefds1[1],pipe1writemsg,sizeof(pipe1writemsg));

  read(pipefds2[0],readmessage,sizeof(readmessage));

  printf("In Parent: Reading from pipe2 message is %s\n",readmessage);

 }

 else

 {

  close(pipefds1[1]);

  close(pipefds2[0]);

  read(pipefds2[0],readmessage,sizeof(pipe2writemsg));
  printf("In Child: Reading from pipe1 message is %s\n",readmessage);
 printf("In Child: Writing to pipe2 message is %s\n",pipe2writemsg);
read(pipefds2[1],pipe2writemsg,sizeof(pipe2writemsg));

 }

 return 0;

} 
