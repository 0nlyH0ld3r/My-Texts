# Organização estruturada de computadores - Tanenbaum

O livro explica sobre a arquitetura de computadores de forma organizada e estruturada em níveis (como deve ser),
passando por:
- Hardware

- Microprogramação

- Sistema Operacional

- Linguagem de montagem

- Linguagem orientada a problemas (Alto nível)

# Tipos de computadores

Nesse livro estudaremos 3 tipos de computadores: Computadores pessoais, microcontroladores (computadores embarcados)
e servidores, onde cada um possui a sua diferença e será estudado um processador diferente para cada um desses.

## Computador pessoal

- Intel Pentium 4

Não há muita necessidade de explicação. Um computador pessoal é o que costumamos ter em casa e inclusive o que utilizei
para digitar esse texto. Pode ser tanto um notebook quanto um desktop.

O pentium 4 é o alvo do estudo pois, na época, era extremamente comum se ter um pentium 4. Caso por algum acaso eu perceba
que algumas instruções podem estar desatualizadas, irei juntar o que puder em relação ao conhecimento da quinta edição (pentium 4),
com o conhecimento da sexta edição (Intel core 7).

## Computador embarcado

- 8051

Um computador embarcado / embutido ou microcontrolador seria um chip contendo módulos de CPU, entrada e saída e memória,
tudo em um único chip para permitir fácil integração e integração de menor custo com dispositivos eletrônicos, como, por exemplo um
relógio, carros ou até mesmo em lâmpadas e garrafas com visor de temperatura.
Os microcontroladores são muito comuns no mundo, apesar de nem sempre perceptíveis e sem eles a tecnologia não seria o que é hoje.
A CPU 8051 foi escolhido pois era extremamente comum na época, tanto o 8051 quanto outros da sua família que seriam compatíveis com
o mesmo, tal qual o 8752 e o 8751, que funcionam à base de EPROM, (Erasable Programmable Read Only Memory), o que permitia reprogramar
o chip para testar (diferente do 8051 que funciona à base de ROM. Mas, como foi o precursor da família, é o que será estudado. Entretanto,
tudo que funciona para o 8051 funcionará para outros membros da sua família).

## Servidores

- UltraSPARC III

O USIII (Chamar assim) foi um processador desenvolvido por um estudante de universidade que desejava utilizar Unix em um computador pessoal.
Como Unix na época era muito famoso em universidades, era comum que os estudantes tomasse gosto pelo sistema. Entretanto, nenhum computador
pessoal o executava, o que resultava em seus admiradores terem de utilizar minicomputadores de tempo compartilhado (Tipo lan house), como o
PDP-11 e o VAX. Um estudante alemão de pós graduação em Stanford, frustrado por ter que ir para a central de computadores utilizar o UNIX,
 decidiu resolver esse problema construindo para si mesmo uma estação de trabalho UNIX pessoal, denominada. SUN-1 (Stanford University Network).
 Um indiano de convenceu esse estudante a fundar uma empresa e, juntamente com outro estudante e Bill Joy, o arquiteto principal
 do Berkeley UNIX, os quatro fundaram a Suns MicroSystems.
Após algum tempo de existência da empresa, a mesma desenvolveu uma CPU baseada em RISC II, a SPARC (Scalabe Processor ARChitecture).
E esse UltrarSPARC III, fruto do trabalho da Sun MicroSystems e outras empresas financiadas por ela para a produção de CPUs baseados na
arquitetura SPARC, é o que será estudado nesse capítulo. 

A arquitetura tá morta, vou olhar no outro livro o que é dito sobre.

