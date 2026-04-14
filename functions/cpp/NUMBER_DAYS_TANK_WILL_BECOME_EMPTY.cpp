int f_gold ( int C, int l ) {
  if ( l >= C ) return C;
  double eq_root = ( std :: sqrt ( 1 + 8 * ( C - l ) ) - 1 ) / 2;
  return std :: ceil ( eq_root ) + l;
}