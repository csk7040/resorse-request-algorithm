#include<stdio.h>

int n,m,s,ch=0,count=0,ss[100],fi[100],p[100],all[100][100],max[100][100],need[100][100],ava[100],work[100],req[100],req1[100];
int func(int i)
{
	int j;
	for(j=0;j<m;j++)
	{
		if(need[i][j]>work[j])
			return 0;	
	}
	return 1;
}
int main()
{
	printf("enter number of process");
	scanf("%d",&n);
	printf("Enter number of resources");
	scanf("%d",&m);
	int i,j,a;
	printf("Enter the numbers of process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
		fi[i]=0;
	}
	printf("Enter the resources alloted for each process accordingly\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the resources alloted for p[%d]\n",i);
		for(j=0;j<m;j++)
		{
			scanf("%d",&all[i][j]);
		}
	
	}
	printf("Enter the maximum no.of resources needed for each process accordingly\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the maximum no.of resources needed for p[%d]\n",i);
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
		
	}
	printf("enter the available resources\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&ava[i]);	
	}
	printf("choose the request for process");
	printf("0.p0\n1.p1");
	scanf("%d",&ch);
    switch(ch)
    {
    	case 0:
		{
    		for(i=0;i<m;i++)
	     {
	         scanf("%d",&req[i]);
	     }
	
	        for(i=0;i<m;i++)
	       {
		       work[i]=ava[i];
         	}
	        for(i=0;i<n;i++)
	        {
		       for(j=0;j<m;j++)
	           	{
		    	need[i][j]=max[i][j]-all[i][j];
		        }
	        }
	
	        for(i=0;i<n;i++)
	       {
		        if(req[i]<=need[i][j]&&req[i]<=ava[i])
		         {
			        ava[i]=ava[i]-req[i];
			        all[i][j]=all[i][j]+req[i];
			        need[i][j]=need[i][j]-req[i];
	           	}
		
        	}
         	while(count<n)
	        {
	         	s=0;
		        for(i=0;i<n;i++)
	        	{
		          	a=func(i);
			        if(fi[i]==0 && a==1)
		        	{
				        for(j=0;j<m;j++)
				         {
					        work[j]=work[j]+all[i][j];
				         }
			    	ss[count]=i;
				    count++;
				    fi[i]=1;
				    s=1;
		        	}
	        	}
	     	if(s==0)
		    {
		     	printf("\nSystem is not in safe sequence\n");
			break;
	     	}
    	}
	    if(s==1)
      	{
		    printf("\nSystem is in safe sequence and the sequence is: <");	
	    }
      	for(i=0;i<n;i++)
		{
				printf("p[%d],",ss[i]);
			
		}
    	printf("\n");
	
			break;
		}
		case 1:
		{
			
    		for(i=0;i<m;i++)
	     {
	         scanf("%d",&req[i]);
	     }
	
	        for(i=0;i<m;i++)
	       {
		       work[i]=ava[i];
         	}
	        for(i=0;i<n;i++)
	        {
		       for(j=0;j<m;j++)
	           	{
		    	need[i][j]=max[i][j]-all[i][j];
		        }
	        }
	
	        for(i=0;i<n;i++)
	       {
		        if(req[i+1]<=need[i][j]&&req[i+1]<=ava[i])
		         {
			        ava[i]=ava[i]-req[i+1];
			        all[i][j]=all[i][j]+req[i+1];
			        need[i][j]=need[i][j]-req[i+1];
	           	}
		
        	}
         	while(count<n)
	        {
	         	s=0;
		        for(i=0;i<n;i++)
	        	{
		          	a=func(i);
			        if(fi[i]==0 && a==1)
		        	{
				        for(j=0;j<m;j++)
				         {
					        work[j]=work[j]+all[i][j];
				         }
			    	ss[count]=i;
				    count++;
				    fi[i]=1;
				    s=1;
		        	}
	        	}
	     	if(s==0)
		    {
		     	printf("\nSystem is not in safe sequence\n");
			break;
	     	}
    	}
	    if(s==1)
      	{
		    printf("\nSystem is in safe sequence and the sequence is: <");	
	    }
      	for(i=0;i<n;i++)
		{
				printf("p[%d],",ss[i]);
			
		}
    	printf("\n");
	
			break;
			
		}
		default:{
			printf("you didnot entered any request:");
			break;
		}
	}
	return 0;
	
 }



