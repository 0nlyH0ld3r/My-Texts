


int main() {
	int size = 8;
	int vetor[8];

	for (int i = 0; i < size - 1; ++i) {
		int menor = i;

		for (int j = i + 1; j < size; ++j) {
			if (vetor[j] < vetor[menor]) {
				menor = j;
			}
		}

		if (menor != i) {  
			int tmp = vetor[i];
			vetor[i] = vetor[menor];
			vetor[menor] = tmp; 
		}
	}
}



