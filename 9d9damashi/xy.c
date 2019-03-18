#include <stdio.h>
#include <math.h>

int main()
{
  double r=12.0;
  double c = 2*r*M_PI;

  double modc = c - floor(c);

  double fudge = 0.155;

  int idx[24];

  printf("  r=%f  c=%f\n", r, c);

  printf(" i  arc arc      x       y\n");
  for (int i=0; i<24; ++i) {
    double x = (double)i - 11.5;
    double y = sqrt(144.0 - x*x);
    double cosine = x/r;
    double arc = r*acos(cosine) + fudge;

    double u;
    
    if (i<12) u = floor(0.5+arc);
    else      u = ceil(0.5+arc);
    printf("%2d %2.0f %6.3f %6.3f %6.3f\n", i, u, arc, x, y);
    idx[i] = 34-u;
  }

  // turn idx int code
  int n = 0;

  for (int i=0; i<24; ++i) {
    int dn = idx[i] - n;
    switch(dn) {
    case 0: 
      break;
    case 1: printf("      inc  r6        ; %d\n", n);   ++n;
      break;
    case 2: printf("      inct r6        ; %d\n", n);   ++n;   ++n;
      break;
    case 3: printf("      inct r6        ; %d\n", n);   ++n;   ++n;
            printf("      inc  r6\n");   ++n;
      break;
    }
    printf("      movb *r6+,*vd  ; %d -> %d\n", n, i);   ++n;

  } 
}

