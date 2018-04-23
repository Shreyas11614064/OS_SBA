#include<stdio.h>
#include<math.h>
int main(){
	int i,n,j,k,cyl[5000],total_d = 0;
	for(i=0;i<5000;i++){
		cyl[i] = i;
	}
	printf("\Enter the number of requests:");
	scanf("%d",&n);
	int arr[n],td[n-1];
	printf("\nEnter the positions of drive in order:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++){
		j = arr[i];
		k = arr[i+1];
		td[i] = cyl[j]-cyl[k];
		if(td[i]<0){
			td[i] = -td[i];
		}
	}
	for(i=0;i<n-1;i++){
		total_d = total_d + td[i];
	}
	printf("\nTotal distance travrl by drive is: %d",total_d);
}
