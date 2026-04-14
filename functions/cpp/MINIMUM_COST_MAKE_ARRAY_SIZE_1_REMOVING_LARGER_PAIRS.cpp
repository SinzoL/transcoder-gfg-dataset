int f_gold ( int a [ ], int n ) {
  return ( n - 1 ) * ( * min_element ( a, a + n ) );
}