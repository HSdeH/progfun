method mystery(a: nat) returns (q:nat, r:nat)
ensures ???
{
  q,r := 0, a + 1;
  while r >= 4
  {
    q := q + r/4;
    r := r/4 + r%4;
  }
  r := r - 1;
}
