#include <stdio.h>
#include <stdlib.h>
#include "RNTree.h"

int main() {
	RNTree* tree = new RNTree();

	int n;
	
	scanf("%d", &n);
	while(n > 0){
	  tree->add(n);
	  tree->print();
	  printf("\n\n");
	  scanf("%d", &n);	
	}
	
	

	delete tree;
	return 0;
}
