long long int f_gold ( int n ) {
  long long int sum = 0;
  for ( int i = 1;
  i <= n;
  i ++ ) for ( int j = i;
  j <= n;
  j ++ ) sum = sum + i * j;
  return sum;
}