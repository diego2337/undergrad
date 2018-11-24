begin:
	int opcao, tipo;
	char opcao2, nome;
	printf("#-----------------------#-------------------------#\n\n");
	printf("Bem-vindo ao hotel Paçoca. Escolha o que deseja:\n");
	printf("Realizar Check-in: 1\n");
	printf("Procurar por um hóspede: 2\n");
	printf("Realizar Check-out: 3\n");
	printf("Procurar por quartos disponíveis: 4\n");
	scanf("%d", &opcao);
	if(opcao == 1)
	{
		printf("Digite seu primeiro nome e o tipo de quarto que deseja se hospedar.\n");
		scanf("%c %d", &nome, &tipo);
		checkin(argc, argv[]);
	}
	else if(opcao == 2)
	{
		pesquisar(argc, argv[]);
	}
	else if(opcao == 3)
	{
		checkout();
	}
	else
	{
		printf("Comando inválido.\n");
		goto begin;
	}
		printf("Operação realizada com sucesso. Deseja mais alguma coisa? 'y' para sim ou 'n' para não.\n");
		scanf("%c", &opcao2);
		if(opcao2 == 'y');
		goto begin;
		else if(opcao2 == 'n')
		{
			system(pause);
			exit(0);
		}	















	while(esq <= dir)
	{
		meio = (esq+dir)/2;
		if(strcmp(&nameroom, &aux2[meio].nompess) == 0)
		{
			return meio;
		}
		else if(strcmp(&nameroom, &aux2[meio].nompess) > 0)
		{
			esq = meio + 1;
		}
		else
		{
			dir = meio - 1;
		}
	}
	return -1;







	if(type == 2)
		{
			counter = 11;
			printf("hey ho lets go\n");
			if(size == 0)
			{
				desocupado = 1;
				counter = 11;
			}
			for(i = 11; i < 15 && desocupado == 0; i++)
			{
					printf("hey ho lets go1\n");
				if(fscanf(quartos, "%d %d\n", &numquarto, &index) == counter)
				{
						printf("hey ho lets go2\n");
					counter++;
				}
				else if(fscanf(quartos, "%d", &numquarto) > 15)
				{
					counter = 15;
				}
				else if(fscanf(quartos, "%d", &numquarto) != counter)
				{
						printf("hey ho lets go3\n");
					desocupado = 1;
				}	
			}
			if(desocupado == 1)
			{
				cadastro(checkin, counter, type, date, name);
			}
		}






hotelbin = fopen("hotel.bin", "ab+"); // Abrindo o arquivo
	// O ponteiro sera resetado para apontar para a primeira posicao, caso ele foi alterado em utilizaçoes previas
	rewind(hotelbin);
	// Se o arquivo for diferente de NULL, significa que há quartos ocupados nele.
	if(hotelbin != NULL)
	{
		// No arquivo hotel.c, definimos "quarto" como uma estrutura de dados ("struct").
		// Essa parte do codigo sera executada ate que chegue no fim do arquivo bin (ou seja, NULL).
		while(fread(&aux, sizeof(quarto), numbytes, hotelbin)); // onde aux e a variavel auxiliar onde sera armazenado o struct, sizeof e o "modelo" que sera armazenado, o numero de bytes necessarios e de onde os dados estao sendo extraidos.
		// Como o quarto começa a partir do 1, iremos fazer a associaçao ao vetor.
		vetor[aux.numero_quarto-1] = aux.ocupado;
		// Se o numero escrito em "ocupado" for 1, deve ser informado o nome da pessoa, data de check-in e tipo de quarto.
		printf("Nome do hospede: %s\n", aux.nome);
		printf("Data de check-in: %s\n", aux.data_check_in);
		printf("Tipo de quarto: %d\n", aux.tipo_quarto);
	}
		// Ao sair do "while", se houver algum quarto vazio, ele devera ser informado
		for(i = 0; i < 15; i++)
		{
			if(vetor[i] == 0)
			printf("O quarto %d esta vazio.\n", i+1);
		}
