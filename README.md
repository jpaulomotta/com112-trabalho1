# com112-trabalho1
Repositorio do trabalho de COM112 - Estrutura de Dados II - Grupo 7.

O trabalho consiste em implementar o algoritmo heap sort e aplicar um benchmark
para medir o desempenho de:

- Tempo de processamento
- Numero de comparação de chaves
- Numero de copias de registro

E então comparar o desempenho com um algoritmo de Selection Sort ordenando os mesmos 
vetores.

Os vetores serão gerados aleatoriamente.

O enunciado do trabalho pode ser encontrado no link: https://sites.google.com/site/vanessavcos/disciplinas/com112/Trabalho1_2015_CCO.pdf?attredirects=0&d=1

## Modularização

Para facilitar o desenvolvimento remoto em equipe o codigo está organizado nos 
seguintes modulos com os sequintes **prefixos**

- **BEN**_Benchmark.h : Modulo que retorna um tipo Benchmark que gerencia as medições
- **HEA**_Heap.h : Modulo que implementa o heapsort. Tem como dependencia o modulo BEN_Benchmark
- **SEL**_Selection.h : Modulo que implementa o selection sort; Tem como dependencia o modulo BEN_Benchmark
- **ARR**_Array_Utils : Modulo para facilitar a manipulação, criação e comparação de arrays 

- **TST_Suite.h : Biblioteca de testes automatizados. É fundamental que nossos 
modulos sejam testados e estejam funcionando sem erros para não interferirmos no 
trabalho do parceiro.

### Modulos executaveis

Os seguintes artefatos são responsaveis pela execução do aplicativo
- Trabalho_Main.c : Executa a tarefa proposta no trabalho. Le o arquivo de entrada 
e gera um arquivo de saida com os resultados
- Heap_Test.c : Testa o heap sort
- Selection_Test.c : Testa o selection sort
- Array_Utils_Test.c : Testa o modulo array utils
- Benchmark_Test.c : Testa o benchmark


# API

Estas são as funções publicas, presentes no arquivo de cabeçario (.h)

## BEN Benchmark

### Tipos exportados (typedef)

#### medida -> unsigned long long
Alias para unsigned long long. Usado para retornar as medidas

#### tempo -> clock_t
Encapsula o tipo clock_t. O tipo clock_t é um encapsulamento de algum tipo do sistema para 
o retorno do tempo de processamento;


#### Benchmark BEN_criar();
Retorna um objeto benchmark. O a medição não iniciada e nenhuma metrica 
é registrada.

#### Benchmark BEN_destruir(Benchmark benchmark);
Destroi o objeto benchmark removendo ele da memoria.

#### void BEN_iniciar_medicao(Benchmark benchmark);
Inicia a medição. Apartir deste ponto o objeto benchmark começa a medir o tempo 
de processamento

#### void BEN_terminar_medicao(Benchmark benchmark);
Termina a medição. O tempo de processamento para de ser medido.

#### void BEN_comparou_chave(Benchmark benchmark);
Registra uma comparação de chave.

#### void BEN_copiou_registro(Benchmark benchmark);
Registra que uma copia de registro foi feita.

#### tempo BEN_tempo_processamento(Benchmark benchmark);
Retorna o tempo de processamento total do benchmark.

#### medida BEN_chaves_comparadas(Benchmark benchmark);
Retorna a quantidade de chaves comparadas medidos pelo benchmark

#### medida BEN_registros_copiados(Benchmark benchmark);
Retorna a quantidade de registros copiados medidos pelo benchmark



 




