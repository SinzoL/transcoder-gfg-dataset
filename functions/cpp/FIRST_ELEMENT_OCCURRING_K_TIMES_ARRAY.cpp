int f_gold ( int arr [ ], int n, int k ) {
  unordered_map < int, int > count_map;
  for ( int i = 0;
  i < n;
  i ++ ) count_map [ arr [ i ] ] ++;
  for ( int i = 0;
  i < n;
  i ++ ) if ( count_map [ arr [ i ] ] == k ) return arr [ i ];
  return - 1;
}