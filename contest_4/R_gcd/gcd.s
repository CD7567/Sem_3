while:
  cmp w1, 0
  B.eq rres
  cmp w2, 0
  B.eq exit

  sdiv w3, w1, w2
  mul w3, w3, w2
  sub w1, w1, w3

  cmp w1, 0
  B.eq rres

  sdiv w3, w2, w1
  mul w3, w3, w1
  sub w2, w2, w3

  B while

rres:
  mov w1, w2

exit: