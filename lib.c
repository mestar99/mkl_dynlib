
#include <stdio.h>
#include <stdlib.h>

#include <mkl.h>

void this_mkl_wrapper()
{
  printf("Hello from library\n");

  MKL_INT n, incx, incy, i;
  float *x, *y;
  float res;
  MKL_INT len_x, len_y;

  n = 5;
  incx = 2;
  incy = 1;

  len_x = 1+(n-1)*abs(incx);
  len_y = 1+(n-1)*abs(incy);
  x = (float *) calloc( len_x, sizeof(float) );
  y = (float *) calloc( len_y, sizeof(float) );
  if( x == NULL || y == NULL ) {
    printf("Cannot allocate memory for arrays\n");
    return;
  }

  for(i=0; i<n; ++i) {
    x[i*abs(incx)] = 2.0;
    y[i*abs(incy)] = 1.0;
  }

  res = cblas_sdot(n, x, incx, y, incy);

  printf("SDOT = %7.3f\n", res);

  free(x);
  free(y);
}
