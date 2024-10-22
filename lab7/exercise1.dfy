method exercise1(x:int, y:int, X:int, Y:int) returns (p:int, q: int)
requires X>Y && ((x==X && y==Y-2*x) || (x==Y && y==X-2*Y))
ensures p==X && q==Y
{
  // implement (and annotate) yourself
}
