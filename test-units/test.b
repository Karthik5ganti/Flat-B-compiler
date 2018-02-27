declblock{
	int data[10];
	int i, sum,n,j,temp;
}

codeblock{
	i=3;
	n=10;
	sum=temp;
	for i=0,10{
		data[i]=i*-1+sum;
	}
	for i=0,n{
	for j=i+1,n,1{
			if(data[i]>data[j])
			{
				sum=temp;
			}
	}
	}
	print sum;
}
