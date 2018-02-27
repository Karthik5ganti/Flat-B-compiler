declblock{
  int x,y;
  int remainder;
  int gcd;
}
codeblock{
    x=1766;
    y=23234;
    remainder = x%y;
    while (remainder!=0){
      remainder=x%y;
      x=y;
      y=remainder;
    }
    gcd=x;
    print "gcd = ", gcd;
}
