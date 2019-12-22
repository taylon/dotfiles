#pragma once

#include "quantum.h"

#define LAYOUT(                       \
                                      \
  k00,k01,k02,k03,k04,k05,            \
  k10,k11,k12,k13,k14,k15,            \
  k20,k21,k22,k23,k24,k25,            \
  k30,k31,k32,k33,k34,k35,            \
  k40,k41,k42,k43,k44,                \
                          k55,k50,    \
                              k54,    \
                      k53,k52,k51     \
                                      \
)                                     \
                                      \
/* matrix positions */                \
{                                     \
 { k00, k01, k02, k03, k04, k05,   }, \
 { k10, k11, k12, k13, k14, k15,   }, \
 { k20, k21, k22, k23, k24, k25,   }, \
 { k30, k31, k32, k33, k34, k35,   }, \
 { k40, k41, k42, k43, k44, KC_NO, }, \
 { k50, k51, k52, k53, k54, k55    }, \
}

