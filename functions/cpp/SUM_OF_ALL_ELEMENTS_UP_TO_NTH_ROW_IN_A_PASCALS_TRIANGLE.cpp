long long int f_gold ( int n ) {
  long long int sum = 0;
  for ( int row = 0;
  row < n;
  row ++ ) {
    sum = sum + ( 1LL << row );
  }
  return sum;
}