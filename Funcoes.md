# EXPLICANDO UM POUCO SOBRE FUNÇÕES

Uma explicação breve pra funções é: 
Um bloco de código que recebe um nome para ser utilizado repetidamente em outros blocos de códigos.
Tal qual funções matemáticas (  f(x)  ), as funções de programação executam alguma ação (No caso das funções matemáticas, operações matemáticas,
e as de programação, código).

Funções, no geral, possuem um tipo (que determina o tipo de dado que irá retornar para o código que a chamar) e podem possuir parâmetros,
que funcionam similarmente ao **x** em uma função **f(x)**, em que a variável (ou constante) que for colocada como um parâmetro para a função terá
seu valor copiado para ser utilizado dentro da função (Chamada por valor).


# A DECLARAÇÃO DE UMA FUNÇÃO

A declaração de uma função possui dois métodos, mas, no geral, uma função será declarada da seguinte forma:
    O **tipo** da função antecedendo seu **nome**. O tipo de uma função determina qual valor era será devolvido pelo comando **return**. Seu tipo pode ser de qualquer
    válido, desde tipos primitivos até ponteiros e structs. Por exemplo: uma função int (que devolve inteiros), float (que devolve float), 
    ponteiro pra char (que devolve o endereço de memória pra uma string), e até mesmo **void**, caso não retorne nada (Será tratado em um próximo tópico).
Para ser utilizada por outro bloco de código, a função deve ser declarada antes do bloco de código (Por exemplo, para serem utilizadas na main, as funções devem ser
declaradas antes main).
Funções não podem ser declaradas antes de outros blocos de código (Como por exemplo seria feito em Python declarando uma função dentro da outra).
Ou seja: Não é possível declarar uma função dentro de outra função. É necessário declarar ela fora de qualquer outra função. Mas, ainda assim, funções podem ser CHAMADAS
dentro de outras funções caso tenham sido declaradas antes da função que a chama.

```

## Método 1: Protótipo de função

tipo nome(tipo parâmetro, tipo parâmetro...);


tipo nome(tipo parâmetro, tipo parâmetro...) {
    bloco de código
}

```

```

## Método 2: Declaração direta (Necessária mesmo quando se utiliza o protótipo de uma função)

tipo nome(tipo parâmetro, tipo parâmetro...) {
    bloco de código
}

```

## DECLARAÇÃO DIRETA:

Funções, tal qual variáveis, precisam ser declaradas antes de serem utilizadas. O primeiro método (Que nomeei de declaração direta por fins didáticos, mas o correto
seria "forma geral de declaração de funções") irá declarar a função normalmente, juntamente com o bloco de código que ela executa.
O maior problema desse tipo de declaração é que mesmo para um código com somente 3 funções e a função main, haverá 3 funções antecedendo a main, que, por sua vez,
será posicionada ao final do arquivo, abaixo de muitas outras linhas de código, para que todas as outras funções sejam declaradas antes dela e possuam ser utilizadas
nela.

```
## Ex:

int soma(int x, int y) {
    return x + y;
}

int multiplicar(int x, int y) {
    return x * y;
}

int dividir(int x, int y) {
    return x / y;
}

int main() {
    int x = soma(2, 2);
    int x += multiplicar(x, 10)
    int y = dividir(x, 3);
    printf("%d", soma(x,y));
}

---------------------------------------------------------------
    output| 32

```

## PROTÓTIPOS DE FUNÇÕES:

Conhecendo essa limitação da linguagem C que forçava desenvolvedores a terem linhas gigantes de código antes da função main, ou separar a main em um arquivo próprio,
os protótipos de funções foram desenvolvidos (não foi somente isso que ocasionou no desenvolvimento dos protótipos, mas é um dos motivos).
Com os protótipos de funções, é possível declarar a função sem definir o seu bloco de código, somente seu tipo, nome e parâmetros. Apesar disso, a função 
irá requerir que em algum lugar do arquivo (exceção com header files, que será algo que provavelmente veremos na aula de Laboratório de Programação em breve)
a forma geral seja utilizada, pois o protótipo serve somente para que o compilador saiba da sua existência antes da execução, mas é sim necessário adicionar seu código 
(mesmo ao final do código, como demonstrado abaixo).

```
## Ex:

int soma(int x, int y);
int multiplicar(int x, int y);
int dividir(int x, int y);

int main() {
    int x = soma(2, 2);
    int x += multiplicar(x, 10)
    int y = dividir(x, 3);
    printf("%d", soma(x,y));
}

int soma(int x, int y) {
    return x + y;
}

int multiplicar(int x, int y) {
    return x * y;
}

int dividir(int x, int y) {
    return x / y;
}

---------------------------------------------------------------
    output| 32
```

## Fatores importantes para a declaração de uma função:

Um dos motivos para o compilador não permitir que funções sejam utilizadas antes da declaração é, tanto para conhecer o endereço onde a função se inicia,
quanto por motivos de segurança. O compilador precisa saber o que a função devolve, de qual tipo e quantos argumentos recebe.
Caso permitisse a execução sem saber de tais informações, erros inesperados poderiam ocorrer. Desde chamar uma função aleatória por não saber o endereço correto,
aceitar argumentos que não deveria ou aceitar a chamada da função sem argumentos, mesmo que existam parâmetros os aguardando. Pode não parecer grande coisa às vezes,
mas em muitos sitemas isso pode alterar o valor de uma outra variável, ocasionar em comportamentos inesperados ou mesmo operar em algo que não deveria ser operado.
Por exemplo, no código de um sistem operacional, ocasionaria em, eventualmente, alguma falha crítica.
por exemplo:

```

int main() {
    kill_by_id(); /* Imagina executar isso sem comando, entrar lixo, desligar um processo essencial e matar o sistema operacional inteiro? */
    return 0;
}

int kill_by_id(unsigned int id) {
    char command[50];
    snprintf(command, sizeof(command), "kill %d", id);
    system()
}

/* Não se importem com o conteúdo dessa função, é só um exemplo rápido que e figurativo. 
* Mas, pra quem quiser saber: Um sistema operacional não funciona assim (obviamente),
tanto que essa função usa um comando já existente do sistema operacional (O comando **kill** presente em sistemas Unix-like), junto
com a função system() pra executar comandos do sistema (presente na stdlib.h) */

```

A função kill_by_id() tem como parâmetro a variável inteira sem sinal **id** e mata (termina) o processo daquele respectivo id.
Caso não fosse garantido um argumento para id, haveria a chance de lixo ser encontrado e esse lixo poderia ser o id de algum outro processo.
A chance seria sim rara, entratanto não nula.
Então, para evitar esse tipo de erro, o compilador não permite que uma função seja chamada antes de ser declarada.
É necessário pelo menos o protótipo dessa função para que compilador saiba seus parâmetros e evite erros inesperados por chamar uma função sem passar os argumentos 
necessários (Não compila se não passar os argumentos).

## RETORNANDO VALORES

Funções de código podem (Ou não) retornar valores pelo comando **return**.
O valor retornado por uma função depende do tipo declarado dela, então uma **int func()** retorna somente valores int, que podem ser recebidos por outras
variáveis, ou até mesmo funções.

### RETURN EM FUNÇÕES

O comando return tem duas utilidades:  Acabar a função após o bloco de código (ou até mesmo dentro de uma condição para acabar antes do bloco de código inteiro
ser executado, caso não haja mais necessidade de executar a função, como, por exemplo, se o valor passado dentro de um argumento seja inválido, tenha executado
tudo o que foi necessário para os argumentos passados ou determinado valor passado seja a condição pra parar a função)
Toda função que o tipo não seja void DEVE retornar algum valor.

```

## ex:

int eh_par(int x) {
    if (x % 2 == 0) return 1;   /* Se o número for par, a função retorna 1 */

    return 0                    /* Se o número for impar, a função retorna 0 */
}

## ex2:

int numero_certo(int x) {
    if (x != 4) return 0;       /* A função para se o número não for 4 e retorna 0 pra indicar falso, ou seja, que não foi o certo. */

    printf("Esse é o número certo! Escola o procedimento que deseja fazer com ele:") /* Executa mais blocos de código caso a função não encontre o return acima. */
    ...
    return x; /* Finaliza a função retornando o valor de x, pois todas as funções devem retornar um valor, exceto as do tipo void. */
}

```

Uma peculiaridade é o return para **void func()**, que não irá retornar um valor, mas sim finalizar a função (Pode ser usada da mesma forma que na função acima,
basta mudar o tipo para void e tirar o valor returnado pelo **return**, deixando ele puro pra "cancelar" a chamada da função).


Retornar uma variável não irá literalmente retornar as variáveis em si, mas sim o seu valor (funções que retornam ponteiros, irá retornar algum endereço).
Dessa forma, é necessário que outra variável ou função receba o valor.

```

int dobro(int x) {
    return x * 2;
}

int main() {
    int x = dobro(4);
    printf("%d", x);

---------------------------------------------------------------
    output| 8
}

```

#### FUNÇÕES SEM TIPO (VOID)

Funções tabém podem ser passadas com o tipo vazio, o que, consequentemente, dirá ao compilador que ela não retorna nenhum valor. 
Ou seja: Funções que somente alteram alguma coisa. Geralmente são funções que recebem variáveis pra alterar seu valor, funções que somente realizam ações
simples e que não há necessidade de receber algum valor pra determinar o resultado a execução (Como strncpy que retorna 0 caso as strings sejam iguais e etc).
Por exemplo, uma função que somente modifica algo sem chance ou sem necessidade de verificar se deu erro (como mudar o valor de uma variável, ou uma main que apenas
printa Hello World!).

```

void dobro(int *x) {
    return x * 2;
}

int main() {
    int x = 2;
    dobro(&x);

    printf("%d", x);

---------------------------------------------------------------
    output| 4
}

```

A função acima é uma função void que recebe o endereço para uma variável inteira e dobra o seu valor.
Diferente de outras funções que poderiam ter o valor atribuído para uma variável, ou utilizado como argumento de outra função, as funções void não são capazes disso.
Logo, é impossível replicar o que é feito com a função  **int dobro()** do segundo exemplo acima, com a função **void dobro()** do exemplo logo acima

## PARÂMETROS X ARGUMENTOS

Uma explicação rápida da diferença entre parâmetros e argumentos:  Os parâmetros são as variáveis dentro do bloco de código da função que recebem o valor do que for
posto dentro da função (o que for posto como argumento) durante a sua chamada (tem exemplo abaixo pra explicar).
Argumentos são variáveis (ou constantes) colocadas entre os parênteses da função durante a sua chamada.
ex:

```

void func(char *parametro) {
    if (!strncpy(parametro, "Isso é um parâmetro")) {
        puts(parametro);
    }
}

int main() {
    char *argumento = "Isso é um argumento";
    func(argumento);
}

```

### PASSANDO FUNÇÕES SEM PARÂMETROS

Funções também podem ser passadas sem parâmetros. Para passar funções sem parâmetros, basta declara-las sem parâmetro algum.
Mas, é uma boa prática também declarar com o parâmetro void (Vazio), que, essencialmente, é somente uma forma explícita de declarar a falta de parâmetros
de uma determinada função.
ex:

```

int numero_4();
int Ola_mundo(void);
/* Resultam na mesma coisa. Eu uso a primeira versão, mas nos livros que li foi recomendado a segunda,
apesar de não fazer diferença alguma no código. */

```


### Funções como argumentos.

Há duas formas de passar funções como argumentos:
Passar o resultado de uma função como argumento (Funções de tipos válidos retornam uma constante com o valor da variável/constante que passou paro o return).
Passar literalmente a função (passando seu nome sem os parênteses após ele).

#### PASSANDO O RESULTADO DE UMA FUNÇÃO COMO ARGUMENTO

```

int soma(int x, int y);
int elevar_ao_quadrado(int x);

int main() {
    printf("%d", elevar_ao_quadrado(soma(4, 2)));
}

```

Sei que passar uma função como argumento de uma função argumento de outra função parece meio feio, mas não é tão incomum. Agora, passar uma função como argumento
de outra função (2 camadas) é bem normal. (Isso não significa que não deva ser utilizado assim, somente que EU não vi muitas, mas meu repertório não é tão grande
        assim).


#### SOBRE O SEGUNDO MÉTODO:

O segundo método é algo que não vi muitos exemplos por aí, acredito não ser algo muito convencional e não me recordo sobre (afinal, não utilizei). Mas, caso queiram
saber sobre, podem pesquisar ou ler o livro que mandei no grupo. Ele trata sobre. Mas, o conceito é possível pois, para a linguagem C, o nome de uma função é um
ponteiro para um bloco de código. Se você usar printf("%p", funcao) sem os parênteses após o nome da função, será possível ver seu endereço
Outra coisa também é que as funções void não podem ser passadas pelo primeiro método, mas podem por esse método, só não irão dar valor a nada. Melhor pesquisar pra
entender.

ex:

```

int x(void);
int main(){
	printf("%p\n", x); // Vai printar o endereço da função x.
}

int x(void) {
	printf("Ola mundo!");
}

```

Assim será possível ver o endereço da função. 
(Lembrete de que, para acessar o endereço de uma variável é necessário usar &variavel, mas para ponteiros, vetores, matrizes e funções, não. Com exceção de algum 
elemento em específico de um vetor (Ou seja, um vetor indexado vetor[0], vetor[4] e etc).
Ex:  printf("%p, %p, %p, %p %p", &variavel, &vetor[0], ponteiro, vetor, funcao);

# CHAMADA POR VALOR X CHAMADA POR REFERÊNCIA

Isso vai ser algo tratado depois por ponteiros, mas irei citar aqui sobre a diferença entre os dois tipos de chamada, começando pela chamada por valor.

## CHAMADA POR VALOR

A chamada por valor se trata de somente usar o valor de uma variável. Aqui está o motivo de se diferenciar parâmetros de argumentos (por mais que seja uma
distinção técnica e que muitas pessoas ignoram, chamando ambos tanto de parâmetros quanto argumentos. Mas é bom manter a distinção).
O parâmetro de uma função é algo totalmente separado do argumento. Quando você passa um argumento pra uma função (como no exemplo abaixo)
o que acontece é que a função recebe o valor do argumento como o valor do parâmetro. Ambos são variáveis diferentes, mas com o mesmo valor, logo: Mudanças
ocorridas no parâmetro não afetam o argumento. Você pode fazer o quanto quiser, mas a variável **x** declarada na main nunca vai mudar de valor, pois o
parâmetro **x** na função elevar_a_um_numero() somente recebe o valor do argumento.

```

void elevar_a_um_numero(int x, int y) {
    elevar(x,y); // Só figurativo mesmo
}

int main() {
    int x = 2;
    elevar_a_um_numero(x, 2)
    printf("%d", x);
}

```


## CHAMADA POR REFERÊNCIA

Agora vem a chamada por referência. Ela funciona por meio de ponteiros. É esse o segredo. Assim como na chamada por valor, a chamada por referência utiliza um parâmetro 
que copia o valor do argumento, mas com o diferencial de que o valor a ser copiado será um ponteiro, ou seja: Um endereço de memória.
Assim como já deve ter sido visto no outro arquivo tratando sobre ponteiros:  Ponteiros são variáveis que recebem endereços de memória pra outras variáveis.
Com esse endereço, é possível alterar o valor da variável utilizando o ponteiro.
De tal forma, quando o parâmetro de uma função é um ponteiro, ele irá receber um endereço ou um ponteiro com um endereço, permitindo então alterar o valor que está
guardado em tal endereço.
ex:

```

void elevar_a_um_numero(int *x, int y) {
        elevar(x,y); // Só figurativo mesmo
}

int main() {
        int x = 2;
            elevar_a_um_numero(&x, 2)
                printf("%d", x);
}

```

Detalhe que, assim como já mencionado antes, o endereço de memória de uma variável e de um elemento específico do vetor só pode ser selecionado utilizando 
o operador &

### UM PEQUENO DETALHE SOBRE A CHAMADA POR REFERÊNCIA

A chamada por referência é sim muito útil, mas tem um pequeno detalhe: Se você abusar de chamadas por referência no seu código, em algum momento você vai pagar o
preço. A chamada de referência em si não é nada maligno, mas, caso diversas funções em um algoritmo chamem por referência e alterem o valor de uma variável no
código, se tornará muito difícil o diagnóstico do mesmo.
Imagine que em uma base de código com 30 funções, 9 funções diferente estão modificando a mesma variável.
Um sistema com algumas dezenas de arquivos, onde, em um arquivo específico, entre 9 funções, uma única variável concorrida por várias funções ocasionou em um erro
fatal. O trabalho pra achar isso seria gigantesco. Mas, e se fosse ainda maior? Centenas de arquivos e 20 funções concorrendo pela mesma variável?

Não é preciso evitar ao máximo utilizar chamadas por referência, afinal é um recurso extremamente útil, especialmente em sistemas com escassez de recursos (como um
microcontrolador, que possui apenas alguns Kilobytes [kb] de memória disponíveis). Antes de o utilizar a chamada por referência, se questione se não há alguma outra 
forma de alcançar o mesmo resultado. É realmente necessário? O hardware por onde seu sistema passará é limitado o bastante pra te fazer poupar o máximo de memória
possível (apesar de que é bom sim poupar memória, tornar o código complexo demais de se manter não é uma boa opção se há recursos o suficiente pra utilizar um pouco a
mais e garantir que nenhuma variável aleatória será alterada indevidamente).
