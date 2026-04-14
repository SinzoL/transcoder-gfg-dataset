int f_gold ( char s [ ], char t [ ] ) {
  int count = 0;
  for ( int i = 0;
  i < strlen ( t );
  i ++ ) {
    if ( count == strlen ( s ) ) break;
    if ( t [ i ] == s [ count ] ) count ++;
  }
  return count;
}