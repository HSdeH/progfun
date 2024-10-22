method preserveSum(x: int, y:int, a:int) returns (p: int, q: int)
ensures p + q == x + y
{
  p := x + a;
  q := y - a;
}

method preserveSumProduct(x: int, y:int) returns (p: int, q: int)
ensures p + q == x + y && p*q < 0
{
   // implement (and annotate) yourself
}

