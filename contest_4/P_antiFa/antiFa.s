mov w2, 1

while:
  sdiv w1, w1, w2
  add w2, w2, 1
  cmp w1, 1
  B.ne while

sub w2, w2, 1
exit: