#include<stdio.h>

int main()
{
	int nf, np, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
 	printf("Enter number of frames: ");
 	scanf("%d", &nf);
 	   
 	printf("Enter number of pages: ");
 	scanf("%d", &np);
 	  
 	printf("Enter page reference string: ");
    
 	for(i = 0; i < np; ++i)
	{
 		scanf("%d", &pages[i]);
    	}
    
    	for(i = 0; i < nf; ++i)
	{
        	frames[i] = -1;
    	}
    
    	for(i = 0; i < np; ++i)
	{
        	flag1 = flag2 = 0;
        
        	for(j = 0; j < nf; ++j)
		{
	        	if(frames[j] == pages[i])
			{
	          		flag1 = flag2 = 1;
	                	break;
	               	}
	       	}
	        
	        if(flag1 == 0)
		{
		        for(j = 0; j < nf; ++j)
			{
		        	if(frames[j] == -1)
				{
		              		faults++;
			              	frames[j] = pages[i];
			                flag2 = 1;
			                break;
		                }
		       }    
        	}
        
        	if(flag2 == 0)
		{
		  	flag3 =0;
            
	            	for(j = 0; j < nf; ++j)
			{
	                	temp[j] = -1;
                
	                	for(k = i + 1; k < np; ++k)
					{
		                    		if(frames[j] == pages[k])
						{
		       	                 		temp[j] = k;
		                        		break;
		                    		}
		               	 	}
	            	}
            
	            	for(j = 0; j < nf; ++j)
			{
	               		if(temp[j] == -1)
				{
	                    		pos = j;
	                    		flag3 = 1;
	                    		break;
		                }
			}	
	            
			if(flag3 ==0)
			{
	                	max = temp[0];
	                	pos = 0;
	                	
	                	for(j = 1; j < nf; ++j)
				{
	                    		if(temp[j] > max)
					{
	                        		max = temp[j];
       		                		pos = j;
        	            		}
        	        	}                
        	    	}
        	    
        	    	frames[pos] = pages[i];
        	    	faults++;
		}
        
        	printf("\n");
        	
        	for(j = 0; j < nf; ++j)
		{
        	    printf("%d\t", frames[j]);
        	}	
	}
    
	printf("\n\nTotal Page Faults = %d", faults);
    
	return 0;
}
