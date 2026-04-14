int f_gold ( int n ) {
  int l = sqrt ( n );
  int sq = l * l;
  if ( sq == n ) return l * 4;
  else {
    long long int row = n / l;
    long long int perimeter = 2 * ( l + row );
    if ( n % l != 0 ) perimeter += 2;
    return perimeter;
  }
}