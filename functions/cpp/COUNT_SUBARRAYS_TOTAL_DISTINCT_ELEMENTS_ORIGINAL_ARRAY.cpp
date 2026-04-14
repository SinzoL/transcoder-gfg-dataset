int f_gold ( int arr [ ], int n ) {
  unordered_map < int, int > vis;
  for ( int i = 0;
  i < n;
  ++ i ) vis [ arr [ i ] ] = 1;
  int k = vis . size ( );
  vis . clear ( );
  int ans = 0, right = 0, window = 0;
  for ( int left = 0;
  left < n;
  ++ left ) {
    while ( right < n && window < k ) {
      ++ vis [ arr [ right ] ];
      if ( vis [ arr [ right ] ] == 1 ) ++ window;
      ++ right;
    }
    if ( window == k ) ans += ( n - right + 1 );
    -- vis [ arr [ left ] ];
    if ( vis [ arr [ left ] ] == 0 ) -- window;
  }
  return ans;
}