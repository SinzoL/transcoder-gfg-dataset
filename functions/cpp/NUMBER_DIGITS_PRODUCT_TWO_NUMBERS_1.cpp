int f_gold ( int a, int b ) {
  if ( a == 0 || b == 0 ) return 1;
  return floor ( log10 ( abs ( a ) ) + log10 ( abs ( b ) ) ) + 1;
}