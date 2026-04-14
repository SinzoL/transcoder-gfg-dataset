long long int f_gold ( long long int y, long long int x ) {
  if ( log2 ( y ) < x ) return y;
  if ( x > 63 ) return y;
  return ( y % ( 1 << x ) );
}