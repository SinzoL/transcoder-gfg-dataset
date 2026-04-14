int f_gold ( string str [ ], int n ) {
  unordered_map < string, int > m;
  for ( int i = 0;
  i < n;
  i ++ ) m [ str [ i ] ] += 1;
  int res = 0;
  for ( auto it = m . begin ( );
  it != m . end ( );
  it ++ ) if ( ( it -> second == 2 ) ) res ++;
  return res;
}