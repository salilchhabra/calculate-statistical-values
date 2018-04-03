#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<unistd.h>
   
struct Results{ 
 
	int min;
	int max;
	float average;
 
}Results;
int  *arg; 

int n;
void *Min(void *arg){
 
	int i; 
 
	int *e = (int*)arg;  
 
	Results.min = e[0];
 
	for(i = 0; i < n; i++){	
 
		if(e[i] < Results.min){	
 
			Results.min = e[i];	
 
		}
 
	}
 
 
return NULL;
 
}
 
void *Max(void *arg){
 
	int i;
 
	int *e = (int*)arg; 
 
	for(i = 0; i < n; i++){
 
		if(e[i] > Results.max){	
 
			Results.max = e[i];
 
		}
	}
 
 
return NULL;
 
}
 
void *Average(void *arg){
 
	int i;	 
 
	int *e = (int*)arg; 
 
	for(i = 0; i < n; i++){	
 
		Results.average += e[i];		
 
	}
 
	Results.average = Results.average/n;
 
 
return NULL;
 
}
 
int main(){
 arg=(int * )malloc(sizeof(int)*n);
	
printf("enter how many elements \n");
scanf("%d",&n);
printf("enter elmenets");
	for(int i=0;i<n;i++)
	{
	scanf("%d",&arg[i]);
	}
	pthread_t t1,t2,t3;
		
 	pthread_create(&t1, NULL, Min, (void *)arg);
 pthread_join( t1,NULL);

 
	 
	 pthread_create(&t2, NULL, Max, (void *)arg);
	  pthread_join(t2,NULL);

 
	 
	   pthread_create(&t3,NULL, Average, (void *)arg);
  pthread_join( t3,NULL);

 
		
 	

 				printf("\nThe average is %f\nThe maximum is %d\nThe minimum is %d\n",Results.average, Results.max, Results.min);
	}
 
	
