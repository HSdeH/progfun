include "io.dfy"

method SquareCube(n: int) returns (sq: int, cb: int)
requires n >= 0
ensures sq == n*n && cb == n*n*n
{
  sq := n*n;
  cb := n*sq;
}

method Main()
{
  // Do not change the following code. It is used for Themis testing

  var n := IO.ReadNat();
  var square,cube := SquareCube(n);
  print n, "*", n, "=", square," ",n, "*", n, "*", n, "=", cube, "\n";
}
