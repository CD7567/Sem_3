mov x3, 0

cmp x2, 0
B.eq exit

while:
  ldr x4, [x1], 8
  add x3, x3, x4
  sub x2, x2, 1
  cmp x2, 0
  B.ne while

exit: