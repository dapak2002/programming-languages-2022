//while (x != 0 ) do z:=z+y;  x:= x-1 done
method Example1(n: int, m: int, k:int) returns (z: int)
  requires 0 <= n 
  ensures z == n*m + k
{
    var x := n;
    z := k;
    while x != 0 
      invariant z == (n-x)*m+k
    {
        z := z+m;
        x := x-1;
    }
}
method Main() {
  var r := Example1(2,3,1);
  print r;
}
