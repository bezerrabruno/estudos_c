#include <stdio.h>

int main() {
  int operador;
  int x;
  int y;

  printf("Primeiro valor: ");
  scanf("%d", &x);

  printf("Segundo valor: ");
  scanf("%d", &y);

  printf("\nQual operacao matematica deseja fazer?\n");
  printf("(1) Adicao (2) Subitracao (3) Multiplicacao (4) Divisao\n");
  printf("Escolha: ");

  scanf("%d", &operador);

  switch(operador) {
    case 1:
      printf("%d", x + y);
      break;
    case 2:
      printf("%d", x - y);
      break;
    case 3:
      printf("%d", x * y);
      break;
    default:
      printf("%d", x / y);
      break;
  }
}
