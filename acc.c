#include <openacc.h>
#include <stdio.h>

void wrap_acc_init(void) {
  printf("*** acc_init called!\n");
  acc_init(acc_get_device_type());
}
