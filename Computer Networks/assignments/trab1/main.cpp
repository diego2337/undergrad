#ifndef __SERVIDOR_H
#include "Servidor.h"
#endif

#ifndef __REQUEST_H
#include "Request.h"
#endif
pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;

/* Tudo que o arquivo "main" realiza é a instanciação de um objeto "Servidor" e a invocação de seu método "run" */
int main(int argc, char *argv[])
{
	if(argv[1] == NULL)
	{
		argv[1] = "8080";
	}
	Servidor server(atoi(argv[1]));
	server.run();
	return 0;
}
