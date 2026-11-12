#ifndef REG51_H
#define REG51_H

/*
 * Minimal register definition required by this example.
 * Use the compiler's native syntax when building for an 8051 target;
 * the fallback keeps desktop-editor diagnostics from failing on reg51.h.
 */
#if defined(__C51__) || defined(__CX51__)
sfr P2 = 0xA0;
#elif defined(SDCC)
__sfr __at (0xA0) P2;
#else
static volatile unsigned char P2;
#endif

#endif /* REG51_H */
