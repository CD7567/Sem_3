unsigned int patch(unsigned int num) {
  return num & ((1 << 17) - 1);
}