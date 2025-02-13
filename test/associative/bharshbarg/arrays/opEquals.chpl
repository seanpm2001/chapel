use Map;

proc pretty(ref a : map) {
  write("{ ");
  var first = true;
  for k in a.keysToArray().sorted() {
    if !first then write(", ", k, " => ", a[k]);
    else {
      write(k, " => ", a[k]);
      first = false;
    }
  }
  writeln(" }");
}

var a = new map(string, int);
a.add("a", 1); a.add("b", 2); a.add("c", 3);
pretty(a);
