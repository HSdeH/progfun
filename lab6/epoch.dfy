/* file   :     epoch.dfy                                */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Wed Oct 16 2024                          */
/* version:     1.0                                      */

/* Description:
 * prints what day it is at a certain unix time
 */

include "io.dfy"

method Main()
{
  var a : int;
  a := IO.ReadInt();
  a := a / 86400;
  a := a % 7;

  match a {
    case 0 => print "Thursday";
    case 1 => print "Friday";
    case 2 => print "Saturday";
    case 3 => print "Sunday";
    case 4 => print "Monday";
    case 5 => print "Tuesday";
    case _ => print "Wednesday";
  }
  print "\n";
}