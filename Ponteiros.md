# UMA PEQUENA NOTA SOBRE O MEU TEXTO:

Não leve tudo que foi dito como uma verdade absoluta, experimente, teste o que vier na mente (só cuidado para não escrever
onde não deve) e pesquise sobre. É só um pequeno guia auxiliar para ter uma ideia do que são ponteiros. Estou longe de ser algum especialista,
só decidi ajudar um pouco compartilhando o que sei sobre o assunto.

O texto está em constante revisão, caso aviste algum erro e queira me alertar, pode entrar em contato


- Bruno Vinicius | IFBA Campus Salvador - ADS - 2º Semestre 2026.2

# Uma explicação rápida de ponteiros

## PRIMEIRO: VARIÁVEIS NA MEMÓRIA

Variáveis são armazenadas na memória de acesso aleatório (RAM | Random Access Memory). Cada variável utiliza um tamanho diferente de memória que é, geralmente,
medido em bytes. 1 byte costuma ter 8 bits em sistemas convencionais. O tamanho de uma variável pode mudar dependendo da arquitetura do sistema.
Uma tabela rápida para um sistema convencional x86_64:

```

Character   -> 1  byte
Integers    -> 4  bytes
Float       -> 8  bytes
Pointer     -> 8  bytes
Double      -> 16 bytes

```

Cada variável recebe um endereço na memória. Por exemplo, se você criar uma variável e utilizar printf("%p", variavel) é possível imprimir esse endereço,
que é, representado em hexadecimal.

(Ex:  0x01f2de45c, onde 0x indica que se trata de um hexadecimal)

O endereço de uma variável ocupa o número de bytes do tamanho do tipo da variável. Por exemplo, uma variável **char** possui tamanho de 1 byte assim, é possível ter 
uma variável **char x** em **0x0001** e uma variável **char y** em **0x0002**, mas não é possível ter o mesmo para um **int**, pois esse tem tamanho de 4 bytes.
Assim, dois inteiros conseguintes não podem ser armazenados nos endereços 0x0001 e 0x0002, mas sim 0x0001 e 0x0005 

(Por mais que isso vá ser difícil de representar, afinal, em um programa de verdade, a chance de variáveis isoladas serem armazenadas em endereços conseguintes 
da memória é raro, apesar de ser a regra por de trás de vetores: Elementos em endereços conseguintes de memória).

## EXPLICANDO SOBRE PONTEIROS

Ponteiros são variáveis que guardam algum endereço da memória. Sim, ALGUM e não O DE UMA VARIÁVEL. Em Ponteiros, é possível guardar qualquer endereço de memória.
Uma variável, o nome de um vetor (que é o endereço pro primeiro elemento), o segundo elemento de um vetor, outro ponteiro (Ponteiro para ponteiro), strings digitadas
no código (string hardcoded), endereços de memória que armazenem instruções específicas do hardware que executem algum comando.

```

// String hardcoded (Digitada no código):

char *ptr = "Isso é uma string hard-coded"

// Isso é um ponteiro para um vetor (aponta pro primeiro endereço do vetor)

int vetor[10];
int *ptr2 = vetor;

// Um ponteiro para o sexto elemento de um vetor (que é uma variável)

int ptr3 = vetor[5];

```

### EXEMPLOS:

-   Em um arduíno, cada pino é representado por um endereço de memória. Assim, para acessar e utilizar algum pino no código, é possível utilizar uma MACRO 
(Macros são tipo: #Define ABC 123  , de forma que ABC é a Macro de valor 123), que possui o endereço de memória do pino e utilizar um ponteiro para receber
esse endereço. Um ponteiro em uma função para receber o endereço de n-pino, que será dado como argumento para a função.

- A função abaixo recebe um ponteiro / endereço de memória:

```

void recebe_pino(int *pino);

```

- Um ponteiro recebendo o endereço de uma variável;

```

int *ponteiro = &variavel

```

### Strings Hardcoded

Strings hardcodeds são strings que fora passadas diretamente para um ponteiro, sem nenhum intermediário (como um vetor armazenando a string sendo passado para o 
ponteiro). O que ocorre nesse caso é que, devido à falta de uma estrutura para armazenar a string (ponteiros só armazenam endereços),
a string é armazenada diretamente na memória em um bloco de memória com permissão de somente leitura e então o ponteiro recebe o endereço para o primeiro caractere 
da string. Não é possível modificar o valor dessas strings. Caso tente, há duas opções (sendo a segunda a mais provável).

1- Nada acontece. Literalmente nada.
2- O programa quebra completamente (o correto e mais comum).

```

char *ponteiro_para_string = 
"Essa string está sendo passada para um ponteiro. Como não foi armazenada em nenhum vetor, ela é guardada em um local especial da memória 
que não pode ser modificado. Então, dessa forma, tentar modificar a string pode causar efeitos não esperados"
    
```

Como citado anteriormente, strings hardcoded atribuídas para um ponteiro NÃO PODEM e NÃO DEVEM ser modificadas (apesar de não ser o caso se passadas para um vetor).
São strings fixas. Entretanto, caso deseje mudar a string contida no vetor, há uma forma: Fazendo ele apontar para outra string, ou apontar para um vetor de caracteres,
que permitirá a edição da string (seja com funções ou alterando caracteres individualmente). 


``` 
char *ptr = "Ola"   !=   char string[] "Ola"  /* pois no primeiro a string não pode ser modificada, enquanto no segundo pode.*/
char *ptr = string  ==  string[] "Ola"  !=  char *ptr = "Ola!"  /* Somente os dois primeiros podem modificar a string */

```

(Só um lembrete de que a comparação é meramente ilustrativa e tem função didática. Se você comparar ponteiros e vetores assim, o resultado vai ser quase 
sempre falso, exceto se você fizer o ponteiro receber o vetor string, pois, assim, o ponteiro vai ter o mesmo endereço que
o nome do vetor)


```

char string[] = "Ola!";
char *ptr = string;
printf("%d\n", ptr == string);

```


## DECLARANDO UM PONTEIRO

Ponteiros são declarados da seguinte forma:
 **tipo *nome**
    
Onde tipo de refere ao tipo da variável que o ponteiro deve receber, afinal, como cada variável ocupa n bytes na memória,
ponteiros vão se comportar diferente dependendo do tipo de variável que devem receber.
Ex:  **int *ponteiro**
Ex: **char *ponteiro2**

Obs: É possível também declarar int* ponteiro   ou int * ponteiro, isso depende muito de estética, mas, por minha opinião pessoal,
acho que faz mais sentido utilizar  int *ponteiro (apesar de que não discordo de utilizar o asterísco ao lado do int).
Motivo:  int * ponteiro   faz parecer muito uma multiplicação
Motivo2: para utilizar o valor de uma variável armazenada em um ponteiro, utiliza-se *nome. De tal forma, me faz mais sentido
utilizar uma estrutura semelhante durante a declaração.

## RECEBENDO VALOR PARA UM PONTEIRO.

Como dito anteriormente, ponteiros recebem endereços de memória. De tal forma, para um ponteiro receber um valor, basta somente uma coisa.
Um endereço de memória!
Como conseguir? É possível buscar na sorte algum endereço de memória aleatório (Não recomendado, a não ser que você queira alterar o valor de
algum endereço aleatório na sua RAM, incluindo algo que possa afetar o sistema. Ou, se você souber algum endereço de memória definido com alguma função,
como no caso citado acima de um arduino).
Mas, também, é possível "extrair" o endereço de memória de uma variável utilizando o operador &   (sim, o mesmo do AND bit a bit)
- Exemplo:   int *ptr = &x;
Se trata da mesma sintaxe de um scanf() recebendo variáveis como argumento, pois o scanf() recebe ponteiros para endereços de variáveis para alterar o valor
das mesmas (Como ensinado na aula de Dihego de usar ponteiros para alterar variáveis).

## ACESSANDO VALORES POR MEIO DE PONTEIROS

Bem, ponteiros recebem endereços de memória e isso você já sabe. Mas, deve ter algo que possa ser feito com esses endereços de memória, correto?
Claro. Além de ser possível utilizar um ponteiro ou um endereço de memória para passar uma variável para uma função:

```

int x = 10;
int *ptr = &x
printf("%p, &p", ptr, &x);  /* Ambos produzem o mesmo output, afinal, ambos são a mesma forma de disponibilizar o endereço de x para uma função. */

--------------------------------------------
 output| 0x0001, 0x0001     /* <- Essa é a saída do programa (Apenas simbólico aqui por que o número seria gigante em um sistema real) */

```

É possível acessar os valores do endereço armazenado no ponteiro utilizando, novamente, o operador *
Ex:  

```

printf("%d", *ptr);

--------------------------------------------
 output| 10

```


De tal forma, é possível realizar matemáticas com os endereços (geralmente variáveis) que estão contidas em um ponteiro.

```

*ptr += 5   // Lembrando que ptr == &x  e x = 10;
printf("%d", x)

--------------------------------------------
 output| 15

```

- Inclusive é possível sair printando endereços aleatórios com isso. Só não recomendo tentar alterar o valor nesses endereços
e nem garanto que vá ter algo / algo significativo nesses endereços.

# ALGUNS USOS DE PONTEIROS:

Como vocês devem ter entendido pela aula do dia 24/08 de Estruturas de dados e algoritmos e também pode ser visto no outro arquivo que fala sobre funções:
Funções são blocos de códigos que podem ser evocadas a qualquer momento após a sua criação em outras funções.

ex:  int main(); int somar(); int *funcao_devolve_ponteiro();

Existem duas relações entre ponteiros e funções:

1 - Funções de ponteiro para algum tipo
2 - Funções que recebem ponteiros de algum tipo como argumentos.

## FUNÇÕES DE PONTEIRO

Funções de ponteiros se tratam de funções que retornam um ponteiro após a execução. Da mesma forma que você pode fazer um int soma(int x, int y) que retorna x + y,
você pode fazer uma função int *maior(int x, int y) que retorna o endereço de alguma delas (um ponteiro).

```

int *maior_entre_dois(int *x, int *y) {
    if ( *x < *y) return y; // Se o valor de Y for maior que X, retorna Y.

    return x; // Se não, retorna X
}

int main() {
    int x = 4, y = 5;
    int *ponteiro_para_o_maior = maior_entre_dois(&x, &y);
}

```

Outro uso muito importante para funções que retornam ponteiros é para retornar vetores.
Tente criar uma função que retorne um vetor, independente de qual seja o seu tipo.
Caso sua ideia tenha sido retornar o nome do vetor, ele irá falhar. E retornar um elemento do vetor não é a mesma coisa que retornar o vetor inteiro.
Isso se deve pois, em sua essência, o vetor funciona similarmente a um ponteiro. O nome de um vetor referencia o primeiro elemento do mesmo próprio vetor.
Ou seja: o nome de um vetor se trata, essencialmente, de um ponteiro para o seu primeiro elemento. E, assim como citado anteriormente, os elementos
seguintes são postos em posições conseguintes da memória em relação ao endereço do primeiro elemento. Ou seja:  O vetor **char string[10]**,
que se inicia na posição 0x0001 e termina na 0x0010 (10 elementos de 1 byte), possui como nome **string** e esse nome é um ponteiro para o endereço 0x0001.

- Isso se liga diretamente com aritmética de ponteiros, pois, caso você incremente um ponteiro,
ele avançará o número de bytes do seu tipo em um endereço de memória.

```

int ptr = 0x0001
ptr + 1 == 0x0005

```

# UM POUCO SOBRE ARITMÉTICA DE PONTEIROS

Como foi dito anteriormente, é possível utilizar o endereço de um ponteiro com operações matemáticas para o mover pela memória.
Isso se chama aritmética de ponteiros e não será algo tratado com muita profundidade aqui, mas eu mandei o livro
"Understanding C Pointers | Richard Reese". É um livro focado em ponteiros da linguagem C, é um material indispensável se você pretende se tornar um
desenvolvedor C competente (Ou se quer passar com facilidade nas matérias de C da faculdade). Esse livro vai tratar melhor sobre o assunto inteiro.

## EXPLICAÇÃO RÁPIDA SOBRE ARITMÉTICA DE PONTEIROS

A aritmética de ponteiros é uma técnica que consiste em se mover por endereços da memória utilizando operações de subtração e adição em conjunto com ponteiros
(Incremento e Decremento são, de certa forma, Adição e Subtração)
Como já expliquei anteriormente, ao incrementar / somar / decrementar / subtrair o endereço de um ponteiro irá o fazer andar n-bytes na memória, de acordo o
o tamanho do tipo em que o ponteiro foi declarado (Ponteiros **void** não podem ser utilizados para aritmética de ponteiro, a não ser que seja realizado type cast
neles para o tipo de ponteiro desejado. Se quiser mais informações, pesquise sobre type cast ou leia em algum livro, é algo relativamente simples, mas foge do conteúdo
de ponteiros).
A diferença entre incremento e decremento para adição e subtração, é que incrementar/decrementar um ponteiro irá aplicar a mudança de endereço diretamente no ponteiro.
Quando se trata de alguma operação como ler o conteúdo de uma string uma única vez, fará mais sentido incrementar a string, haja vista que operações de incremento são
mais otimizadas do que adições.

```

## ex INCREMENTO:

char *ptr = "Isso é uma string"
while (*ptr) {
    printf("%c\n", *ptr);
    ++ptr;
}

/* O código acima irá printar cada caracter da string individualmente e criará uma nova linha após ele, incrementando o ponteiro para seguir pro próximo caracter. 
* Nota-se que é utilizado while (*ptr), pois o último elemento de uma string é o \0 (NULL Terminator), que por sua vez tem valor 0 (falso), então ao chegar nele, 
o loop irá parar. */

## ex ADIÇÃO: 

int vetor[5] = { 2, 4, 6, 8, 10};
int *ptr = vetor, i; 
/* É possível declarar um ponteiro e uma variável normal na mesma linha.*/

printf("Digite o número do elemento do vetor que deseja ler (De 0 a 4)")
scanf("%d", &i);
printf("O elemento %d do vetor é:%d\n", i, *(ptr + i) );

```

A explicação do segundo método:
Como o nome do vetor é um ponteiro para o primeiro elemento, *(ptr + 0)  <- Endereço entre parênteses e o operador * para pegar o elemento do endereço
irá pegar o valor do primeiro elemento. Então, caso o x valha 0 (primeiro elemento), ele irá ler o primeiro elemento do vetor.
*(ptr + 4) irá ler o quinto. Se for perceber, utilizar ponteiros dessa forma lembra muito o conceito de indexação de vetores (vetor[0]). Isso se deve ao fato
de que a indexação de vetores tem como base a aritmética de ponteiros (mas a aritmética de ponteiros é mais otimizada, entretanto mais difícil de se ler).

```

int vetor[5] = { 2, 4, 6, 8, 10};
int *ptr = vetor;
printf("%d\n", *(ptr + i) == vetor[1]); // Para printar se os valores são iguais
printf("%d\n", (ptr + i) == &vetor[1]); // Para printar se os endereços são iguais

```
