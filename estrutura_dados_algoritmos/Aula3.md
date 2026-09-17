# O essencial, ou o "grande O"

T(N) = aN + b

- Complexidade não mde segundos, mede a tendência do crescimento do custo de acordo com o tamanho da entrada
- O importante é o expoente mais expressivo e não os coeficientes
-  notação do big O expresa isto:

3n -> O(n)
3n² 5n + 10 -> O(n²)
an³ + bn² + cn + d -> O(n³)

- O número que conta é o número de maior expoente / constante multiplicando.
    - Similar ao cálculo de limites no infinito.

- Dois algoritmos com o mesmo Big O devem ser comparados olhando para T(N).


## O que o big O determina:

1 - Complexidade constante
2 - Complexidade linear
3 - Complexidade logarítmica
4 - Complexidade log-linear
5 - Complexidade quadrática
6 - Complexidade cúbica
7 - Complexidade exponencial
8 - Complexidade fatorial


O(n!) pior
O(x^n)
O(n²)
O(n log(n))
O(n)
O(log(n))

### Complexidade constante:

- Um tamanho fixo de instruções

### Complexidade linear:

- Se dobro a entrada, dobra o tempo de execução

### Complexidade logarítmica

- Menor que o tempo linear. Ocorre em algoritmos que dividem o problema em problemas menores
iguais sucessivamente (divisão, mas sem conquista)

- Dobrar o tamanho da entrada, acrescenta o tempo de uma iteração somente

- Ex: O algoritmo de Busca Binária

### Complexidade Log linear

- Como o próprio nome diz, são algoritmos que têm complexidade O(NlogN)

- Ocorre tipicamente em algoritmos que dividem o problema em problemas menores, porém juntando posteriormente a solução dos problemas menores
(divisão e conquista)

### Complexidade quadrática

- São algoritmos de complexidade O(N²)

- Dobrar a entrada, quadruplica o tempo de execução

- Itens são processados aos pares, geralmente com um loop dentro do outro.

### Complexidade cúbica

- São os algoritmos de complexidade O(N³)

- Dobrar a entrada, octuplica o tempo de execução

- Itens são processados três a três, geralmente com um loop dentro dos outros dois

- Ex: Multiplicação de matrizes

### Complexidade exponencial

- São os algoritmos de complexidade O(2^n)

- Geralmente não são úteis sob o ponto de vista prático

- Adicionar um elemento a entrada, dobra o tempo de execução

- Utilização de "Força Bruta" para resolvêl-los (abordagem simples) para resolver um deteminado problema, geralmente baseada diretamente
no enunciado do problema e nas definições dos conceitos envolvidos)

- Ex: descobrir a senha de um N dígitos gerando possibilidades e testando

### Complexidade fatorial

- O que é complexidade fatorial O(n!)
- Um algoritmo tem complexidad efaotrial quando o número de operações cresce aproximadamente como o fatorial do tamanho da entrada:
    n! = n x (n - 1) x (n - 2) x  ... x 2 x 1

- n! aparece naturalmente quando o algoritmo precisa considerar todas as permutações (todas as ordens possíveis) de n itens.

- Exemplo: Problema do caixeiro-viajante

## Combinação de algoritmos

- Em um código que utilize dois algoritmos. Exemplo: Bubble short pra organizar o vetor e binary-search pra procurar no vetor organizado,
o maior big O prevalecerá.

- Desconsideramos as constantes sempres

# 

- Bubble short

- Insection short

- Selection

- Fatorial

- Fibonacci

## Algoritmos recursivos:

- Fatorial

- Fibonacci

- Busca binária

- Mergesort

- Quicksort
