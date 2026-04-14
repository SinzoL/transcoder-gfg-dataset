int f_gold ( int arr [ ], int n ) {
  int sum = 0;
  unordered_set < int > s;
  for ( int i = 0;
  i < n;
  i ++ ) {
    if ( s . find ( arr [ i ] ) == s . end ( ) ) {
      sum += arr [ i ];
      s . insert ( arr [ i ] );
    }
  }
  return sum;
}