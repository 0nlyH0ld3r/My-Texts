# ARQUITETURA DE VON NEUMANN

## ENTRADA -> PROCESSAMENTO -> SAÍDA

## ARQUITETURA DE VON NEUMANN

### Memória

Dispositivo de armazenamento que serve tanto para dados quanto para instruções.
Dados e instruções são armazenados em uma única memória de leitura e escrita.
O conteúdo da memória é endereçado de acordo com a sua posição.

A memória se comunica bidirecionalmente com a CPU. É ligada com a CPU por um barramento externo
e se liga com a Unidade de Controle e a Unidade Lógica Aritmética por meio de um barramento interno.

Memória: 
- Unidade de controle 
- Unidade Aritmética e lógica

### Unidade de controle

A únidade de controle se comunica com a memória e a ULA por meio de um barramento interno
Dita o funcionamento de todos os componentes do sistemas, desde a própria CPU, barramentos, memória,
GPU e tudo mais. É um absurdo esse cara.
Decide como os componentes interagem entre si e com a CPU.

Acompanha a sequência das instruções que serão executadas.

Unidade de controle:
- Memória

### ULA

A Unidade Lógica Aritmética se comunica com a memória e a UC por meio de um barramento interno e contém o Acumulador

Executa as instruções, que envolvem operações lógicas e aritméticas.
A execução de instruções ocorre de modo sequencial, exceto quando há saltos para sub-rotinas e/ou interrupções.

Unidade Aritmética e lógica:
- Memória
- Acumulador
    - Entrada
    - Saída

### Acumulador

O Acumulador interage com a entrada e a saída por meio de um barramento interno e é contido pela ULA

Acumulador
- Entrada
- Saída

### Entrada e Saída

Interage com o acumulador por meio de um barramento interno e interagem com a CPU por meio de um barramento externo.
Entrada passa para o acumulador e acumulador passa para a saída

A entrada e a saída interagem 
Entrada
- Acumulador

Saída
- Acumulador

### Primeira geração:

Memória: RAM
Não existia Cache
Muitos computadores antigos nem possuíam unidade de armazenamento
Entrada: Cartões perfurados
Saída: Cartões perfurados, monitores rudimentares e impressão de texto (Mais comum o uso de cartões perfurados).
- Impressão matricial (Caíram em desuso em função da adoção de impressoras de jato de tinta).

###

## PRINCIPAL IDEIA DA ARQUITETURA DE VON NEUMANN

Possibilitar que uma máquina digital pudesse armazenar os programas no mesmo espaço de memória que os dados (Programa armazenado).
O programa habita a memória, juntamente aos dados lidos, processados e a serem disponibilizados para saída.
Instruções e dados na memória.
Tudo necessita de memória auxiliar para executar.

## BIOS         <- Basic Input Output System

## Transparente <- Quando o usuário não necessita conhecer os detalhes (Ou foi escolhido que não há necessidade de demonstrar).

## HT <- Hypr thread

Diz respeito ao hardware

Um processador com núcleos capazes de criar núcleos virtuais (threads).
O núcleo físico executa todas as instruções, mesmo as dos núcleos virtuais.
Nem todos os programas de beneficiam por threads, mas, para os que se beneficiam, o paralelismo
é um conceito poderoso.

## MT <- Multithread

Diz respeito ao software.

Cria algo como uma cópia de si mesmo para ser executado em uma thread secundária. Um software
que existe e é executado por diversas threads.
Não é possível realizar multithreading em CPUs sem Hypr thread.

## Famílias de computadores

Z80
8086
80286
80386
80486
80586 - Pentium

x86 <- Se refere à família de processadores do Pentium e outros processadores terminados por 86.
x64 <- CPU com palavra de tamanho de 64 bits.
