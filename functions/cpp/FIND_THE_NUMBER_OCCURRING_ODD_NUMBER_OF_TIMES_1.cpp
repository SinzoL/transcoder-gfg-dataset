int f_gold ( int arr [ ], int size ) {
  unordered_map < int, int > hash;
  for ( int i = 0;
  i < size;
  i ++ ) {
    hash [ arr [ i ] ] ++;
  }
  for ( auto i : hash ) {
    if ( i . second % 2 != 0 ) {
      return i . first;
    }
  }
  return - 1;
}