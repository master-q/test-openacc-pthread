#include <stdio.h>
#include <dlfcn.h>

int main() {
  void *handle = dlopen ("libtestacc.so", RTLD_LAZY);
  if (handle == NULL) {
    printf ("%s\n", dlerror());
    return(1);
  }

  void (*func)(void) = dlsym(handle, "wrap_acc_init");
  if (func == 0) {
    fprintf(stderr, "%s\n", dlerror());
    return 1;
  }

  func();

  dlclose(handle);
  return 0;
}
