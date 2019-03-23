void main()
{
	char* toplft = (char*)0xb800; // Esse ponteiro ira apontar para o comeco da memoria de video (ou seja, para o canto superior esquerdo da tela)
	*toplft = 'x'; // Imprime a palavra "SO" na tela
}
