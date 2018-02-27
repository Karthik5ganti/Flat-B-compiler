declblock{
  int n,p,i;
  int prime[1001];
}
codeblock{
  n = 1000;
  for i = 0,1000 {
    prime[i] = 1;
  }

  for p =2,32 {
    if(prime[p] == 1){
      for i = p*2 ,n,p {
        prime[i] = 0;
      }
    }
  }

  for p = 2, n,1{
    if(prime[p] == 1){
      println p," ";
    }
  }
}
