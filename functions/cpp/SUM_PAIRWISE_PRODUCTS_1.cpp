long long int f_gold ( int n ) {
  long long int multiTerms = n * ( n + 1 ) / 2;
  long long int sum = multiTerms;
  for ( int i = 2;
  i <= n;
  i ++ ) {
    multiTerms = multiTerms - ( i - 1 );
    sum = sum + multiTerms * i;
  }
  return sum;
}