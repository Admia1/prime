#include <stdio.h>
#define N 1048576 
#define N1 1024 
#define N2 1048576
#define MIL 1000000
int arr[N];
long long prime[N];
int pcount = 0;
int main()
	{
	//printf("2\n");
	long long dirty=0;
	for(int i=0;i<N;i+=2){
		arr[i]=dirty-1;
		}
	for(long long i=3;i<N;i+=2){
		if (arr[i]<dirty){
			long long i2= i+i;
			long long j =i*i;
			prime[pcount++]=i;
			for(; j<N; j+=i2)
				{
				arr[j]=dirty;
				}
			
			prime[pcount]=j;
			pcount++;
			
			}
		}
	int count = pcount+1;
	for(dirty=1;dirty<N2;dirty++)
		{
		//dirty job
		for(int i=0;i<pcount;i+=2)
			{
			long long p2 = prime[i] + prime[i];
			long long j = prime[i+1];
			for(j-=N; j<N; j+=p2)
				{
				arr[j]=dirty;
				}
			prime[i+1]=j;
			}
		//take job
		for(int i=1; i<N; i+=2)
			{
			if(arr[i]<dirty)
				{
				count++;
				//printf("%lld\n", dirty*N+i);
				}
			}
		}
	
	//for(int i=0; i<pcount; i+=2)
		//printf("%lld %lld\n",prime[i],prime[i+1]);
	
	printf("%d",count);
	}

