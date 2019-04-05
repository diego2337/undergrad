# include <stdio.h>

typedef struct{
  int x;
  int y;
} Racional;

/* recebe inteiros não negativos x e y, 
   e devolve 0 se x = y = 0 e
   mdc (x, y) caso contrário */
int mdc (int x, int y){
  if (x < 0) x = -x;
  if (y < 0) y = -y;

  while (y > 0){
    int resto = x % y;
    x = y;
    y = resto;
  }
  return x;
}

void imprimaRacional (Racional a){
  printf ("%d/%d\n", a.x, a.y);
}

Racional soma (Racional a, Racional b){
  int m = mdc (a.x * b.y + b.x * a.y, a.y * b.y);
  Racional c;
  
  c.x = (a.x * b.y + b.x * a.y)/m;
  c.y = a.y * b.y / m;

  return c;
}

Racional subtracao (Racional a, Racional b){
  int m = mdc (a.x * b.y - b.x * a.y, a.y * b.y);
  Racional c;

  c.x = (a.x * b.y - b.x * a.y)/m;
  c.y = a.y * b.y / m;

  return c;
}

Racional multiplicacao (Racional a, Racional b){
  int m = mdc (a.x * b.x, a.y * b.y);
  Racional c;
  
  c.x = a.x * b.x/m;
  c.y = a.y * b.y/m;  

  return c;
}

Racional divisao (Racional a, Racional b){
  int m = mdc (a.x * b.y, a.y * b.x);
  Racional c;

  c.x = a.x * b.y / m;
  c.y = a.y * b.x / m;

  if (c.y < 0) c.y = -c.y, c.x = -c.x;

  return c;
}

/* devolve positivo se a > b, 0 se a = b, negativo se a < b */
int raccmp (Racional a, Racional b){
  return a.x * b.y - b.x * a.y;
}

