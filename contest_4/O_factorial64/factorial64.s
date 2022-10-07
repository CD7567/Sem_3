lsl x1, x1, 56
lsr x1, x1, 56
mov x2, 1

cmp x1, 0
B.eq exit

while:
  mul x2, x2, x1
  sub x1, x1, 1
  cmp x1, 0
  B.ne while

exit: