#include <math.h>
#include <stdio.h>

double calc(double);
int check();

int main() {
  double radius = 0, result = 0;

  int correct = scanf("%lf", &radius);
  if (correct != 1) correct = 0;
  correct = check();
  if (correct) result = calc(radius);
  correct ? printf("%.0lf", result) : printf("n\a");
  return 0;
}

int check() {
  char c = 0;
  int result = 1;
  while (scanf("%c", &c) && c != '\n') {
    if (c == ' ' || c == '\r') {
      continue;
    } else {
      result = 0;
      break;
    }
  }
  return result;
};

double calc(double r) { return 21500 * (4.0L / 3) * M_PI * pow(r, 3); };
