

static void Adler_32_reduction(struct Adler_32_state*const s) {
  s->sum_a = (s->sum_a & 0xffff) + (s->sum_a >> 16) * (65536 - MOD_ADLER);
  s->sum_b = (s->sum_b & 0xffff) + (s->sum_b >> 16) * (65536 - MOD_ADLER);
}

void Adler_32_init(struct Adler_32_state*const s) {
  s->sum_a = 1;
  s->sum_b = 0;
}

void Adler_32_sum(struct Adler_32_state*const s, const void* buf, size_t len) {
  const uint8_t* p = (const uint8_t*)buf;

  // be sure we start off in a good state, in case the previous call stopped just short of 4096 bytes
  Adler_32_reduction(s);

  while (len--) {
    s->sum_a += *p++;
    s->sum_b += s->sum_a;
    if ((len & (4096-1)) == 0)
      Adler_32_reduction(s);
  }
}

uint32_t Adler_32_finish(struct Adler_32_state*const s) {
  Adler_32_reduction(s);
  if (s->sum_a > MOD_ADLER)
    s->sum_a -= MOD_ADLER;
  if (s->sum_b > MOD_ADLER)
    s->sum_b -= MOD_ADLER;
  return (s->sum_b<<16) + s->sum_a;
}


// One short version, used when the entire buffer is available up front
uint32_t Adler_32(const void* buf, size_t len) {
  const uint8_t* p = (const uint8_t*)buf;
  struct Adler_32_state s;

  Adler_32_init( &s );

  while (len--) {
    s.sum_a += *p++;
    s.sum_b += s.sum_a;
    if ((len & (4096-1)) == 0)
      Adler_32_reduction( &s );
  }

  return Adler_32_finish( &s );

}





