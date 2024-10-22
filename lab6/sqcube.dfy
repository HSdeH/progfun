include "io.dfy"

method SquareCube(n: int) returns (sq: int, cb: int)
  requires n >= 0
  ensures sq == n*n && cb == n*n*n
{
  sq, cb := n,n;
  while (cb < n*n*n || sq < n*n)
    decreases n*n*n-cb+n*n-sq
    invariant cb <= n*n*n && sq <= n*n && (n*n*n - cb >= 2 || n*n*n - cb == 0) && (n*n - sq >= 2 || n*n - sq == 0)
  {
    if (sq < n*n) {
      if n*n - sq == 3 {
        sq := sq + 3;
      } else if n*n - sq >= 2{
        sq := sq + 2;
      }
    }

    if (cb < n*n*n) {
      if n*n*n - cb == 3 {
        cb := cb + 3;
      } else if n*n*n - cb >= 2{
        cb := cb + 2;
      }
    }
  }
}

method Main()
{
  // Do not change the following code. It is used for Themis testing

  var n := IO.ReadNat();
  var square,cube := SquareCube(n);
  print n, "*", n, "=", square," ",n, "*", n, "*", n, "=", cube, "\n";
}
