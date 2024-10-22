/* file   :     misdig.dfy                               */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Wed Oct 16 2024                          */
/* version:     1.0                                      */

/* Description:
 * prints the missing digit
 */

include "io.dfy"

method Main()
{
  var a : int, b : int, c : int, i : int;
  i := 0;
  b := 0;
  while i < 9 {
    c := IO.ReadInt();
    b := b + c;
    i := i + 1;
  }

  a := 45 - b;
  print a, "\n";
}
