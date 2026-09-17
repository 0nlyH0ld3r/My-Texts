# Máquina de Von Neumann

## Ciclo de fetch (Ciclo de execução)

- O ciclo de fetch (fetch cicle) consiste no ciclo de execução de um programa, onde a
CPU procura a instrução na memóra (fetch), decodifica (dcode) e executa a instrução.

### Iremos estudar ISA no futuro (Instruction Set Architecture)

## Gargalo de Von Neumann

A arquitetura de Von Neumann determina que a memória e o processador deverão se comunicar
por meio de um barramento único. Considerando que a CPU atual trabalha em Giga hertz de latência,
enquanto a memória trabalha em Mega hertz de latência, a CPU encontra nessa diferença colossal de 
velocidade um gargalo. Esperar os dados e instruções da memória é um grande atraso para a CPU.


## Componentes de von Neumann na arquitetura moderna:

### CPU

- Processador

### BARRAMENTO

- Placa mãe

### MEMÓRIA

- Cache
- Registradores
- RAM
- Disco

### E/S 

## Barramento: Serial x Paralelo

A transmissão em paralelo não era tão em paralelo assim, pois uma transmissão em paralelo de fato
poderia causar interferência entre bits. Considerando que os bits são energia e possuem campos magnéticos,
enviar uma grande sequência de bits em paralelo poderia ocasionar em uma grande onde de interferência.

De tal forma, se provou mais conveniente e seguro a transmissão serial. De tal forma, houve muito investimento
na transmissão serial (Barramentos seriais), ultrapassando a diferença de velocidade entre os dois modelos de transmissão.


# Arquitetura de Harvard

## Duas memórias

- Diferindo da arquitetura de Von Neumann, na arquiteteura de Harvard, havia dois barramentos para comunicação da memória
(duas memórias): Memória de dados e Memória de instruções.
Não havia muita diferença entre as duas, exceto que a arquitetura de Harvard possuia esses dois barramentos e poderia, em um
único clock, ler instruções e dados.
