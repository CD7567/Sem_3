mov x2, 1

while:
  sdiv x1, x1, x2
  add x2, x2, 1
  cmp x1, 1
  B.ne while

sub x2, x2, 1
exit: