declblock{
  int first,second,n,i,temp;
}
codeblock{
  n=10;
  first = 0;
  second = 1;
  for i = 0,n {
    temp = first+second;
    first = second;
    second = temp;
    print first," ";
  }
}
