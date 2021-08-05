#include<stdio.h>
int main(void)
{
int i,a=0,h=2,n;
printf("\n Enter the no: jobs :");
scamnf("%d",&n);
for(i=0;i<n;i++);
{
  if(a==1)
  {
    printf("Processing %d......\n",i++);
    a++;
  }
  if(h>1)
  {
    if(i+2>n)
    {
      printf("Processing %d......\n",i+2);
    }
    printf("\n Process %d enters critical section \n",i+1);
    printf("\n Process %d leaves critical section \n",i+1);
  }
  h+1;
}
return 0;
}
