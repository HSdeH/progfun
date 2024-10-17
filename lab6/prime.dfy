/* file   :     prime.dfy                                */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Wed Oct 16 2024                          */
/* version:     1.0                                      */

/* Description:
 * desc
 */

include "io.dfy"

method Main()
{
  var a : int, b : bool;
  a := IO.ReadInt();
  b := isRightTruncPrime(a);
  if (b) {
    print "YES\n";
  } else {
    print "NO\n";
  }
}

method isRightTruncPrime(n: int) returns (r: bool)
{
  var a := n;
  var b : bool;
  while a > 0 
  {
    b := isPrime(a);
    if !b
    {
      return false;
    }
    a := a/10;
  }
  r := true;
}

method isPrime(n: int) returns (r: bool)
{
  if n <= 1 {
    return false;
  }
  if n == 2 {
    return true;
  }
  if n % 2 == 0 {
    return false;
  }
  var i := 3;
  while i*i <= n {
    if n % i == 0
    {
      return false;
    }
    i := i +2;
  }
  return true;
}