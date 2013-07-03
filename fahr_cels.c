#include <stdio.h>

void fahr_to_celsius() {
  int lower = 0;
  int upper = 300;
  int step = 20;
  printf("Fahr Celsius\n");
  for (float fahr = lower; fahr <= upper; fahr+=step) {
    float celsius = (5.0/9.0) * (fahr-32.0);
    printf("%4.0f %6.1f\n", fahr, celsius);
  } 
}

void celsius_to_fahr() {
  int lower = -20;
  int upper = 160;
  int step = 20;
  printf("Celsius Fahr\n");
  for (float celsius = lower; celsius <= upper; celsius+=step) {
    float fahr = (9.0/5.0)*celsius + 32.0;
    printf("%6.0f %4.1f\n", celsius, fahr);
  } 
}

int main() {
  fahr_to_celsius();
  return 0;
}