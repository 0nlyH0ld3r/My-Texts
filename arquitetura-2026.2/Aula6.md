# Von Neumann - CISC

Memória -> Dados de Instruções separados.

- Focado para computadores gerais.

# Harvard - RISC

Memória -> Dados e Instruções juntos.

- Focado para embarcados.

# Arquitetura atual

- Uma mistura de ambas.

- Memória RAM   -> Segue a estrutura de Von Neumann. Dados e instruções juntos.

- Memória Cache
    - L1, L2    -> Segue a estrutura de Harvard. Separa dados e instruções.

    - L3        -> Segue a estrutura de Von Neumann. Dados e instruções juntos.

# Processamento paralelo

- Paralelismo real (Dois chips em uma placa) é mais rápido do que um computador com 4 núcleos em um chip.

## Dual CPU

- Mais caro


## Multi core

- Mais barato

- Não é possível utilizar 100% dos núcleos, em contra partida a um computador com múltiplas CPUs.

- Independente disso, CPUs seguem utilizando diversos núcleos. Mesmo com o sacrifício do Bin Packing, 
adicionar núcleos a uma CPU se tornou útil o bastante para se manter.

- GPUs usam paralelismo real, mais similar ao uso de duas CPUs em uma placa.

- Melhorou performance, tornou mais complexo o software

# BIN PACKING

- Problema de Alocação
- Específico de CPUs multi core. Pesquisa melhor para falar sobre.

# O Software é o problema

O hardware evoluiu demais. Muito tempo se passou, o hardware evoluiu de forma colossal e deixou de ser um problemas,
mas agora o que nos assola de fato é o software. O software tá uma merda. O software, mesmo quando não tá uma merda,
ainda não é capaz de utilizar 100% do hardware (Bin packing).
Temos que tornar o software mais software.

# Estudar mais sobre componentes de um computador.
