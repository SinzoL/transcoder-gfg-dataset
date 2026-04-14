int f_gold ( int arr [ ], int n ) {
  unordered_map < int, int > mp;
  for ( int i = 0;
  i < n;
  i ++ ) mp [ arr [ i ] ] ++;
  int ans = 0;
  for ( auto it = mp . begin ( );
  it != mp . end ( );
  it ++ ) {
    int count = it -> second;
    ans += ( count * ( count - 1 ) ) / 2;
  }
  return ans;
}