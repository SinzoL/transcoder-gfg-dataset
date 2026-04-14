bool f_gold ( string str ) {
  int zeros = 0, ones = 0;
  for ( char ch : str ) ( ch == '0' ) ? ++ zeros : ++ ones;
  return ( zeros == 1 || ones == 1 );
}