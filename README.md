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


## Compilando e executando
Para compilar e executar use os scripts auxilares. É necessario ter o gcc instalado.

Trabalho (MAIN)
```sh
sh compile_trabalho.sh
./trabalho1.out 30 entrada.txt saida.txt
```


Teste do benchmark
```sh
sh compile_benchmark_test.sh
./benchmark_test.out
```

Teste da suite de testes.
```sh
sh compile_suite_test.sh
./suite_test.out
```

**Favor ao adcionar dependencias continuar seguindo o padrão.**


## Modularização

Para facilitar o desenvolvimento remoto em equipe o codigo está organizado nos 
seguintes modulos com os sequintes **prefixos**

- **BEN**_benchmark.h : Modulo que retorna um tipo Benchmark que gerencia as medições
- **HEA**_heap.h : Modulo que implementa o heapsort. Tem como dependencia o modulo BEN_Benchmark
- **SEL**_selection.h : Modulo que implementa o selection sort; Tem como dependencia o modulo BEN_Benchmark
- **ARR**_array_Utils : Modulo para facilitar a manipulação, criação e comparação de arrays 
- **TST**_suite.h : Biblioteca de testes automatizados. É fundamental que nossos 
modulos sejam testados e estejam funcionando sem erros para não interferirmos no 
trabalho do parceiro.

### Modulos executaveis

Os seguintes artefatos são responsaveis pela execução do aplicativo
- trabalho_main.c : Executa a tarefa proposta no trabalho. Le o arquivo de entrada 
e gera um arquivo de saida com os resultados
- heap_test.c : Testa o heap sort
- selection_test.c : Testa o selection sort
- srray_utils_Test.c : Testa o modulo array utils
- benchmark_test.c : Testa o benchmark

# API

Estas são as funções publicas, presentes no arquivo de cabeçario (.h)

## BEN Benchmark

### Tipos exportados (typedef)

#### MEDIDA -> unsigned long long
Alias para unsigned long long. Usado para retornar as medidas

#### Benchmark -> _benchmark*
Alias para um ponteiro para o struct de tipo _benchmark. Este struct fica encapsulado 
dentro do modulo e não é possivel acessar seus valores diretamente.

## Funções



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

#### clock_t BEN_tempo_processamento(Benchmark benchmark);
Retorna o tempo de processamento total do benchmark.

#### MEDIDA BEN_chaves_comparadas(Benchmark benchmark);
Retorna a quantidade de chaves comparadas medidos pelo benchmark.

#### MEDIDA BEN_registros_copiados(Benchmark benchmark);
Retorna a quantidade de registros copiados medidos pelo benchmark.

#### void BEN_imprimir(Benchmark benchmark);
Imprime na saida padrão o resultado final ou parcial do benchmark de forma legivel 
por humanos.


## HEA Heap
A função de heap sort deve receber o benchmark inicializado. (Com a medição **não** iniciada)
###Funções
#### void HEA_sort(int vet[], int n, Benchmark b);


## SEL Select
A função de select sort deve receber o benchmark inicializado. (Com a medição **não** iniciada)
###Funções
#### int* SEL_sort(int vet[], int n, Benchmark b);

## Arr Array Utils
### Funções
#### int ARR_equals(int vet_a[], int vet_b[], int n);
Compara se dois arrays são iguais. Retorna 0 caso não sejam, e != 0 caso sejam iguais

#### int* ARR_copiar(int vet[], int n);
Retorna um array identico a vet

#### int* ARR_criar_aleatorio(int n, unsigned int semente);
Aloca e retorna um array aleatorio de tamanho n e semente para o gerador de numero aleatorios.


## TST Suite
Os testes devem ser implementados em programas diferentes.

### Funções
#### void TST_iniciar();
Inicia a suite de testes. Requerido no inicio dos testes.

#### void TST_assert(int condicao, char* mensagem);
Verifica se a condição é verdadeira, diferente de 0. (O Teste passou). Uma 
mensagem em string deve ser passada explicando qual é a asserção.

#### void TST_assert_not(int condicao);
Verifica se a condição é falsa, igual a zero. (O teste não passou)

#### void TST_finalizar(int condicao);
Finaliza a suite de testes e imprime o resultado na tela. As mensagens das 
aserções que falharam são imprimidas na tela.





 




