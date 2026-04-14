int f_gold ( string str ) {
  int result = 0;
  for ( int i = 0;
  i < str . size ( );
  i ++ ) if ( i == ( str [ i ] - 'a' ) || i == ( str [ i ] - 'A' ) ) result ++;
  return result;
}