#include<stdio.h>                 // BANKER'S ALGORITHM


//simple display function

int disp(int Tres[],int Claim[][10],int Alloc[][10],int Ares[],int Need[][10],int r,int p) {
	int i, j;
	printf("\nResources :");
	for(i=0;i<r;i++)
		printf("R%d\t",i);
	printf("\n");
	for(i=0;i<r;i++)
		printf("\t %d", Tres[i]);
	printf("\nProcess\t\tClaim\t\tAllocation\t\tNeed\t\tAvailable\n");
	printf("\n_______________________________________________________________________________\n");
	for(i=0;i<p;i++)
	{
		printf("\n%d\t\t", i);
		for(j=0;j<r;j++)
			printf(" %d\t\t", Claim[i][j]);
		for(j=0;j<r;j++)
			printf(" %d\t\t", Alloc[i][j]);
		for(j=0;j<r;j++)
			printf("  %d\t\t", Need[i][j]);
		printf("   %d", Ares[i]);
	}		
return 0;
}

//main funtion
int main() {
	/*
	for n resources and m processes
	Tres[] is the total number of resources
	Ares[] is the available resourecs
	Claim[][] is the maximum number of resource a process wants
	Alloc[][] is the resources allocated at a particular 
	Need[][] is the (Claim - Alloc)
	r is the number of resources
	p is the number of processes
	work[] is the array that keeps track of the available resources
	finish[] is used to keep track of the # of jobs finished while looking for deadlock.
	*/
	char ch;
	int Tres[10], Ares[10],Claim[10][10],Need[10][10],Alloc[10][10];
	int i,j,c,r,p,work[10],finish[10],chk,t;
do{

	printf("\n\n\t\t\t\t[[ Banker's Algorithm ]]\n\n");
	printf("\t\t1.Resources \n");
	printf("\t\t2.Process \n");
	printf("\t\t3.Allocation \n");
	printf("\t\t4.Display \n");
	printf("\t\t5.Check for DEADLOCK \n");
	printf("\t\t6.Exit\n");
	printf("\t\tEnter your choice: ");
	scanf("%d",&c);
	switch(c) {
	
	case 1: printf("Enter the number of Resources: ");
		scanf("%d",&r);
		for(i=0;i<r;i++) {
			printf("\n\tenter %d resource: ", i);
			scanf("%d", &Tres[i]);
			Ares[i] = Tres[i];   //asigning the total resources to the available resources
		}
		break;
	case 2: printf("\n\tResource Allocation\n");
		printf("\n\tEnter the number of processes: ");
		scanf("%d",&p);
		for(i=0;i<p;i++) {
			for(j=0;j<r;j++) {
				printf("claim of process %d for resource %d :",i,j);
				while(1) {
					scanf("%d", &Claim[i][j]);
					if(Claim[i][j] < 0 || Claim[i][j] > Tres[j]) {
						printf("\n\tInvalid Choice");
					}
					else {
						Need[i][j]=Claim[i][j];
						Alloc[i][j]=0;
						break;
					}
				}
			}
		}
		break;
	case 3: printf("Enter the allocated resource for processes ");
		for(i=0;i<p;i++) {
			for(j=0;j<r;j++) {
				printf("\n\tEnter the resource %d for process %d :",j,i);
				while(1) {
					scanf("%d", &Alloc[i][j]);
					if(Alloc[i][j]<0 || Alloc[i][j]>Ares[j] || Alloc[i][j] > Claim[i][j]) {
						printf("Invalid Choice...");	
					}
					else {
						Ares[j] = Ares[j] - Alloc[i][j];
						Need[i][j] = Claim[i][j]- Alloc[i][j];
						break;
					}
				}
			}
		}
		break;
	case 4:	disp(Tres,Claim,Alloc,Ares,Need,r,p);
		break;
	case 5: // Main Banker's Algorithm
		// we assign two more lists or arrays work[] and finish[]
		// work holds the available resources in realtime
		// finish keeps the track of the jobs that have finished in the bankers check for a safe allocation
		// 
		//first we copy the Ares[] to the work[] array		
		//secondly we allocate the finish array with 0		==
		for(i=0;i<r;i++) {
			work[i] = Ares[i];
		}
		for(i=0;i<p;i++) {
			finish[i] = 0;
		}
		i=-1;
		chk=0;	
		while(1) {
		// find a process that has finish[i]=0;
		// and then check if need[][] is less than the work[] if yes then perform the operation of terminating
		// the task so that we get the resources back.

			i++;	
			if(finish[i] == 0) {
				t = 0;
				for(j=0;j<r;j++) {  
					if(Need[i][j] <= work[j])  // for ith process comparing the work(avaliable res)
						t++;               // with the need of the process 
				}
				if(t==r) {
					finish[i] = 1;
					chk++;
					printf(":Process %d terminates here...\n", i);
					for(j=0;j<r;j++) 
						work[j]=work[j] + Alloc[i][j];
					i=-1;					
				}
			}
			if(i>=p-1)
				break;
		}
		if(chk==p)
			printf("\nSafe Allocation");
		else
			printf("\n There is a DEADLOCK");
		
		break;
	case 6:	printf("\n\t      Exiting the programe!!!!\n");
		//ch = getchar(); 
		break;
	default:
		printf("Please enter a valid choice!!!");
		
	}
}while(c!=6);

return 0;
}
