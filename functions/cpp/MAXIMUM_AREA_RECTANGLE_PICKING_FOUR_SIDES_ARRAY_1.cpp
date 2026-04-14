int f_gold ( int arr [ ], int n ) {
  unordered_set < int > s;
  int first = 0, second = 0;
  for ( int i = 0;
  i < n;
  i ++ ) {
    if ( s . find ( arr [ i ] ) == s . end ( ) ) {
      s . insert ( arr [ i ] );
      continue;
    }
    if ( arr [ i ] > first ) {
      second = first;
      first = arr [ i ];
    }
    else if ( arr [ i ] > second ) second = arr [ i ];
  }
  return ( first * second );
}