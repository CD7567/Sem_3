lsl w1, w1, 24
lsr w1, w1, 24
mov w2, 1

cmp w1, 0
B.eq exit

while:
  mul w2, w2, w1
  sub w1, w1, 1
  cmp w1, 0
  B.ne while

exit: