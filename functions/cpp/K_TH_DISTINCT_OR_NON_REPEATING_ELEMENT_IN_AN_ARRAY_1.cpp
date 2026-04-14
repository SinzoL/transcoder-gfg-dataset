int f_gold ( int arr [ ], int n, int k ) {
  unordered_map < int, int > h;
  for ( int i = 0;
  i < n;
  i ++ ) h [ arr [ i ] ] ++;
  if ( h . size ( ) < k ) return - 1;
  int dist_count = 0;
  for ( int i = 0;
  i < n;
  i ++ ) {
    if ( h [ arr [ i ] ] == 1 ) dist_count ++;
    if ( dist_count == k ) return arr [ i ];
  }
  return - 1;
}