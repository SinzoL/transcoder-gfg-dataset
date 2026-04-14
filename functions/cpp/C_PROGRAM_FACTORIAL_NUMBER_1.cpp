int f_gold ( unsigned int n ) {
  int res = 1, i;
  for ( i = 2;
  i <= n;
  i ++ ) res *= i;
  return res;
}