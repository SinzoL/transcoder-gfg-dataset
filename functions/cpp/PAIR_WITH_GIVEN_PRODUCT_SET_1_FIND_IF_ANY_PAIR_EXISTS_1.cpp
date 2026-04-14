bool f_gold ( int arr [ ], int n, int x ) {
  if ( n < 2 ) return false;
  unordered_set < int > s;
  for ( int i = 0;
  i < n;
  i ++ ) {
    if ( arr [ i ] == 0 ) {
      if ( x == 0 ) return true;
      else continue;
    }
    if ( x % arr [ i ] == 0 ) {
      if ( s . find ( x / arr [ i ] ) != s . end ( ) ) return true;
      s . insert ( arr [ i ] );
    }
  }
  return false;
}