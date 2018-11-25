#include "BinaryTree.h"

#ifndef __stdio_h
#include <stdio.h>
#include <iostream>
using namespace std;
#endif

int main(void)
{
  BinaryTree bt;
  int n, h;
  scanf("%d", &n);
  while(n > 0)
  {
    bt. add(n);
    scanf("%d", &n);
  }
  h = bt.height(bt.retRoot());
  bt.completa();
  /*(for(i = 1; i <= h; i++)
  {
    cout << "\nNível " << i << ":";
    bt.inLevel(bt.retRoot(), 1, i);  
  }
  printf("\n");
  
  Node* p;
  bt.add(30);
  bt.add(18);
  bt.add(40);
  bt.add(53);
  bt.add(38);
  bt.add(6);    
  bt.add(12);    
  bt.add(27);    
  bt.add(20);    
  
  bt.preOrdTree(bt.retRoot());
  p = bt.suc(53);
  if(p != NULL)
    printf("Sucessor: %d\n", p->value);

  bt.remove(30);
  bt.preOrdTree(bt.retRoot());
  bt.height();

  printf("\n");*/
  return 0;
}
