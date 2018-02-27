declblock{
	int arr[1001];
	int i,j,n,temp,k;
}
codeblock{
	n=1000;
	for i=0,n {
		arr[i]=n-i;
	}
	for i=0,n {
		for j=i+1,n {
			if(arr[j] < arr[i]){
				temp = arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}

	for i=0,n {
	print Arr[i]," ";
	}
}
