int binary_seacrh(int* vetor, int len, int valor) {
	int inicio = 0;
	int fim = len - 1;
	while (fim >= inicio) {
		int meio = (inicio + fim) / 2;
		if (vetor[meio] == valor)
			return meio;
		if (vetor[meio] < valor) 
			inicio = meio + 1;
		else
			fim = meio - 1;
	}
	return -1;
}

int juntar_vetor_ordenado(int* vetor_i, int* vetor_j, int tam) {
	int vetor_k[tam * 2];
	for(int i = 0, k = 0; i < tam - 1; ++i, k+=2) {
		if (vetor_i[i] < vetor_j[i]) {
			vetor_k[k] = vetor_i[i];
			vetor_k[k+1] = vetor_j[i];
		}
		else {
			vetor_k[k] = vetor_i[i];
			vetor_k[k+1] = vetor_j[i];
		}
	}
	return 1;
}
