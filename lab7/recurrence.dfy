function f(n: nat): int
{
  if n <= 1 then 1-n else 2*f(n-1) + f(n-2)
}

method computeF(n: nat) returns (a: int)
ensures  a == f(n)
{
  // implement and annotate yourself
}
