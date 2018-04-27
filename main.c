#include <pthread.h>
#include <stdio.h>
#include <dlfcn.h>

void *thread(void *ptr) {
  void (*func)(void) = ptr;

  func();

  return ptr;
}

int main() {
  pthread_t thr;

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

  pthread_create(&thr, NULL, *thread, (void *) func);
  pthread_join(thr, NULL);

  dlclose(handle);
  return 0;
}
