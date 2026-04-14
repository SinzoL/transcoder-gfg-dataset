int f_gold ( int x, int y, int z ) {
  int c = 0;
  while ( x && y && z ) {
    x --;
    y --;
    z --;
    c ++;
  }
  return c;
}