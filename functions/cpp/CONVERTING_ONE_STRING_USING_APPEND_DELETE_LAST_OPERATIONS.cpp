bool f_gold ( string str1, string str2, int k ) {
  if ( ( str1 . length ( ) + str2 . length ( ) ) < k ) return true;
  int commonLength = 0;
  for ( int i = 0;
  i < min ( str1 . length ( ), str2 . length ( ) );
  i ++ ) {
    if ( str1 [ i ] == str2 [ i ] ) commonLength ++;
    else break;
  }
  if ( ( k - str1 . length ( ) - str2 . length ( ) + 2 * commonLength ) % 2 == 0 ) return true;
  return false;
}