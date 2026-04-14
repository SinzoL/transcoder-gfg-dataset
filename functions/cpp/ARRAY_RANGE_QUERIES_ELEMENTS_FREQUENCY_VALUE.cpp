int f_gold ( int start, int end, int arr [ ] ) {
  unordered_map < int, int > frequency;
  for ( int i = start;
  i <= end;
  i ++ ) frequency [ arr [ i ] ] ++;
  int count = 0;
  for ( auto x : frequency ) if ( x . first == x . second ) count ++;
  return count;
}