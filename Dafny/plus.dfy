method Plus(x: int, y: int) returns (r: int)
{
  r := x+y;
}

method Main() {
  var r := Plus(2,3);
  print r;
}
