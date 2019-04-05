#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	FILE *f = fopen("imagem.jpg", "rb");
	FILE *w = fopen("img.jpg", "wb");
	if(f && w)
	{
		fseek(f, 0, SEEK_END);
		long fsize = ftell(f);
		fseek(f, 0, SEEK_SET);
		printf("%lu", fsize);
		char *string = (char*)malloc(fsize + 1);
		fread(string, fsize, 1, f);
		fclose(f);

		string[fsize] = 0;
		for(i = 0; i <= fsize; i++)
			printf("%c", string[i]);
		fwrite(string, fsize, 1, w);
		fclose(w);
	}
}