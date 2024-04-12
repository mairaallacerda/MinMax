<h1 align="center"> MINMAX </h1>

</div>

<div style="display: inline-block;">
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
</a> 
</div>



<h2 align="center"> Tópicos </h2>
    <h4 align="center"> 
        
 [Introdução](#introdução)

 [Objetivo do Código](#objetivo-do-código)
  
 [Funcionamento](#funcionamento)

 [Resoluções](#resoluções)

 [Gnuplot](#gnuplot)
 
 [Resultados](#resultados)
 
 [Compilação e Execução](#compilação-e-execução)

 [Contato](#contato)
 <h4>


<h2 align="center"> <strong><em>Introdução</em></strong> </h2>
        <p align="justify">
Este é um projeto que implementa algoritmos para encontrar o mínimo e o máximo em um vetor de inteiros. O código contém três algoritmos diferentes para realizar essa tarefa e também inclui uma função para avaliar o desempenho desses algoritmos com diferentes tamanhos de entrada e tipos de dados.
<p align="justify">
Além da codificação dos algoritmos, o programa conduz uma análise de desempenho minuciosa. Cada algoritmo é executado repetidamente, 10 vezes para cada combinação de tamanho de vetor (1000, 10000, 100000, 500000) e padrão de ordenação (aleatório, crescente, decrescente). Os tempos de execução são registrados e a média dessas 10 execuções é calculada para cada cenário. Essas médias são então armazenadas em um arquivo CSV para análise posterior. 
<p align="justify">
Após essa etapa, são gerados gráficos com base nos dados do arquivo CSV, oferecendo uma representação visual clara das discrepâncias de desempenho entre os algoritmos para diferentes situações de entrada.


<h2 align="center"> Objetivo do código</h2>
       <p align="justify">
O objetivo deste código é fornecer implementações eficientes para encontrar o mínimo e o máximo em um vetor de inteiros, além de realizar uma avaliação do desempenho dessas implementações com diferentes tipos de entrada (aleatório, crescente e decrescente) e tamanhos de vetor.

<h2 align="center"> Funcionamento </h2>
     <p align="justify">
É importante compreender que todas as implementações estão distribuídas em três arquivos, os quais estão detalhados na figura abaixo, juntamente com a funcionalidade de cada um deles.
    <p align="justify">
    <p align="center">
     <img height="100rem" src="/Imagens/src.png">
    </p>
        </p>

   - **_main.cpp_**: serve como o ponto de entrada para o programa de avaliação de desempenho dos algoritmos de busca de mínimo e máximo, coordenando a execução das funções necessárias para essa finalidade.
     <p align="justify">
- **_minMax.hpp_**: declara a classe MinMax, que contém três métodos estáticos: **minMax1**, **minMax2**, e **minMax3**. Esses métodos são responsáveis por encontrar os valores mínimo e máximo em um vetor de inteiros, cada um utilizando uma abordagem diferente para realizar essa tarefa.
          <p align="justify">
     </p> Além disso, o cabeçalho declara três funções fora da classe MinMax para gerar vetores com valores aleatórios, em ordem crescente e em ordem decrescente.
      <p align="justify">
  </p> Este cabeçalho oferece uma interface limpa e organizada para utilizar os algoritmos de busca de mínimo e máximo, bem como funções auxiliares para gerar dados de entrada e analisar os resultados dos testes.

  <p align="justify">
- **_minMax.cpp_**: implementa uma série de funções para analisar o desempenho de diferentes algoritmos de busca de mínimo e máximo em vetores de inteiros. Ele oferece três algoritmos diferentes, denominados minMax1, minMax2, e minMax3, cada um com uma abordagem ligeiramente diferente para encontrar os valores mínimo e máximo em um vetor.
      </p> Além disso, o código inclui funções para gerar vetores com valores aleatórios, em ordem crescente e em ordem decrescente, para permitir a avaliação do desempenho dos algoritmos em diferentes tipos de dados de entrada.
  <p align="justify">
     </p> Em resumo, o código _minmax.cpp_ proporciona uma estrutura para avaliar e comparar o desempenho de diferentes algoritmos de busca de mínimo e máximo em diversos cenários de dados de entrada. Isso pode ser útil para entender como esses algoritmos se comportam em diferentes situações e para tomar decisões informadas sobre sua aplicação em problemas do mundo real.


 <h2 align="center"> Resoluções</h2>
       <p align="justify">  
       
## Implementando o código
<p align="justify">
Inicialmente, foi definida a classe MinMax, que encapsula as operações relacionadas à manipulação de matrizes para o MinMax.
Logo depois, cria o _minMax1_:

* Nesta função, o algoritmo percorre o vetor uma única vez. Ele inicializa as variáveis _min_val_ e _max_val_ com o primeiro elemento do vetor. Em seguida, itera sobre os elementos restantes do vetor, comparando cada elemento com _min_val_ e _max_val_. Se o elemento atual for maior que _max_val_, ele atualiza _max_val_. Se for menor que _min_val_, atualiza _min_val_.
* Ao final do loop, _min_val_ e _max_val_ conterão os valores mínimo e máximo do vetor, respectivamente.
* O tempo de execução é medido utilizando a função clock() para calcular a diferença entre o início e o fim da execução do algoritmo.

```c++
void MinMax::minMax1(const vector<int> &vet, double &tempo_execucao, int &min_val, int &max_val)
{
    clock_t inicio = clock();
    min_val = vet[0];
    max_val = vet[0];

    for (int i = 1; i < vet.size(); ++i)
    {
        if (vet[i] > max_val)
        {
            max_val = vet[i];
        }
        if (vet[i] < min_val)
        {
            min_val = vet[i];
        }
    }

    clock_t fim = clock();
    tempo_execucao = static_cast<double>(fim - inicio) / CLOCKS_PER_SEC;
}


```
<p align="justify">

Depois de criar o minMax1, são criados minMax2 e minMax2, respectivamente.

- _minMax2_: é semelhante à _minMax1_, mas utiliza uma estrutura de controle diferente para verificar e atualizar os valores mínimo e máximo. Em vez de usar duas instruções if independentes, esta função usa um if seguido de um else if. O restante do algoritmo é idêntico ao _minMax1_.

    * Ele ainda percorre o vetor apenas uma vez e atualiza _min_val_ e _max_val_ conforme necessário. 
    * O tempo de execução também é medido da mesma maneira que em minMax1.
   
```c++
void MinMax::minMax2(const vector<int> &vet, double &tempo_execucao, int &min_val, int &max_val)
{
    clock_t inicio = clock();
    min_val = vet[0];
    max_val = vet[0];

    for (int i = 1; i < vet.size(); ++i)
    {
        if (vet[i] > max_val)
        {
            max_val = vet[i];
        }
        else if (vet[i] < min_val)
        {
            min_val = vet[i];
        }
    }

    clock_t fim = clock();
    tempo_execucao = static_cast<double>(fim - inicio) / CLOCKS_PER_SEC;
}
  
```
<p align="justify">
- _minMax3_: este algoritmo utiliza uma abordagem um pouco diferente. Ele começa verificando se o vetor está vazio. Se não estiver vazio, inicializa _min_val_ e _max_val_ com o primeiro elemento do vetor. Em seguida, percorre o restante do vetor e atualiza _min_val_ e _max_val_ conforme necessário, da mesma forma que em _minMax1_ e _minMax2_.
   * O tempo de execução é medido da mesma maneira que nos outros algoritmos.
     
 ```c++
    void MinMax::minMax3(const vector<int> &vet, double &tempo_execucao, int &min_val, int &max_val)
{
    clock_t inicio = clock();
    int n = vet.size();
    if (n > 0)
    {
        min_val = max_val = vet[0];
        for (int i = 1; i < n; ++i)
        {
            if (vet[i] > max_val)
                max_val = vet[i];
            else if (vet[i] < min_val)
                min_val = vet[i];
        }
    }
    else
    {
        min_val = max_val = 0; // Vetor vazio, min e max são ambos zero
    }
    clock_t fim = clock();
    tempo_execucao = static_cast<double>(fim - inicio) / CLOCKS_PER_SEC;
}
```

 Após a implemntação dos MinMax's, foram criadas as funções *gerarVetorAleatorio*, *gerarVetorCrescente*, *gerarVetorDecrescente* e *avaliarMetodos*
   
1. *gerarVetorAleatorio*:  Esta função cria um vetor de inteiros com o tamanho especificado (size). Ela percorre o vetor e atribui a cada elemento um número inteiro aleatório entre 0 e 1000 (inclusive) usando a função _rand()_ em conjunto com o operador de módulo % para garantir que o número gerado esteja dentro do intervalo desejado. Por fim, retorna o vetor preenchido com os valores aleatórios.
  ```c++
   std::vector<int> gerarVetorAleatorio(int size)
{
    vector<int> vet(size);
    for (int i = 0; i < size; ++i)
    {
        vet[i] = rand() % 1001; // Números aleatórios entre 0 e 1000
    }
    return vet;
}
   ```

2. *gerarVetorCrescente*: Assim como a função anterior, esta também cria um vetor de inteiros com o tamanho especificado (size). Primeiramente, preenche o vetor com valores aleatórios, da mesma forma que gerarVetorAleatorio. Após isso, o vetor é ordenado em ordem crescente utilizando a função _std::sort(vet.begin(), vet.end())_. Isso garante que os valores dentro do vetor estejam em ordem crescente ao final do processo.
```c++
std::vector<int> gerarVetorCrescente(int size)
{
    vector<int> vet(size);
    // Preencher o vetor com valores aleatórios entre 0 e 1000
    for (int i = 0; i < size; ++i)
    {
        vet[i] = rand() % 1001;
    }
    // Ordenar o vetor em ordem crescente
    std::sort(vet.begin(), vet.end());

    return vet;
}

```
3.  *gerarVetorDecrescente*: Similar à função anterior, esta também cria um vetor de inteiros com o tamanho especificado (size). Novamente, preenche o vetor com valores aleatórios. Após isso, o vetor é ordenado em ordem decrescente utilizando _std::sort(vet.rbegin(), vet.rend())_. A diferença aqui é que a função _std::sort_ é chamada com os iteradores inversos _(rbegin() e rend())_, o que resulta na ordenação do vetor em ordem decrescente.

```c++
std::vector<int> gerarVetorDecrescente(int size)
{
    vector<int> vet(size);
    // Preencher o vetor com valores aleatórios entre 0 e 1000
    for (int i = 0; i < size; ++i)
    {
        vet[i] = rand() % 1001;
    }
    // Ordenar o vetor em ordem decrescente
    std::sort(vet.rbegin(), vet.rend());

    return vet;
}
```
4. *avaliarMetodos*: realiza a avaliação de três métodos (_minMax1_, _minMax2_, _minMax3_) para encontrar o mínimo e o máximo em um vetor de inteiros. Ela avalia o desempenho desses métodos com diferentes tamanhos de entrada e com vetores de três tipos diferentes: aleatórios, ordenados em ordem crescente e ordenados em ordem decrescente.
   - Abertura do arquivo e verificação de erro: a função começa tentando abrir um arquivo chamado "resultados.csv" para armazenar os resultados. 
   - Definição dos tamanhos de entrada e número de execuções: um vetor chamado sizes é definido para armazenar os diferentes tamanhos de entrada que serão avaliados. A variável numExecutions define quantas vezes (segundo o trabalho precisa ser 10 vezes) cada método será executado para calcular a média do tempo de execução.
   - Execução dos métodos e medição do tempo: para cada tamanho de entrada, são gerados três tipos de vetores (aleatório, crescente e decrescente) usando as funções _gerarVetorAleatorio_, _gerarVetorCrescente_ e _gerarVetorDecrescente_.
   </p> O tempo de execução de cada chamada é registrado em vetores separados para posterior cálculo da média.
   
   - Cálculo das médias dos tempos de execução: para cada tipo de vetor (aleatório, crescente e decrescente) e para cada método, são calculadas as médias dos tempos de execução das 10 execuções. As médias são convertidas para milissegundos e armazenadas em variáveis correspondentes.
     
   - Impressão dos resultados na saída padrão: os resultados são impressos na saída padrão, mostrando o tamanho do vetor e a média do tempo de execução para cada método e tipo de vetor.
   
   - Escrita dos resultados no arquivo CSV: os resultados são escritos no arquivo "resultados.csv", com cada linha representando uma execução com um determinado tamanho de entrada, tipo de vetor e método. Cada linha contém o tamanho do vetor, o tipo de vetor, o método utilizado e a média do tempo de execução em milissegundos.

 </p> Essa função permite comparar o desempenho dos métodos para diferentes cenários de entrada e é útil para avaliar a eficiência dos algoritmos em diferentes situações.

```c++
void avaliarMetodos()
{
    ofstream arquivo("./datasets/resultados.csv");

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return;
    }
vector<int> sizes = {1000, 10000, 100000, 500000};
    int numExecutions = 10;

    for (int size : sizes)
    {
        vector<double> tempos_minMax1_aleatorio, tempos_minMax1_crescente, tempos_minMax1_decrescente;
        vector<double> tempos_minMax2_aleatorio, tempos_minMax2_crescente, tempos_minMax2_decrescente;
        vector<double> tempos_minMax3_aleatorio, tempos_minMax3_crescente, tempos_minMax3_decrescente;

        for (int i = 0; i < numExecutions; ++i)
        {
            vector<int> vetorAleatorio = gerarVetorAleatorio(size);
            vector<int> vetorCrescente = gerarVetorCrescente(size);
            vector<int> vetorDecrescente = gerarVetorDecrescente(size);

            double tempo_execucao;
            int min_val, max_val;

            // Executar minMax1 e registrar o tempo de execução para vetores aleatórios
            MinMax::minMax1(vetorAleatorio, tempo_execucao, min_val, max_val);
            tempos_minMax1_aleatorio.push_back(tempo_execucao);

            // Executar minMax1 e registrar o tempo de execução para vetores crescentes
            MinMax::minMax1(vetorCrescente, tempo_execucao, min_val, max_val);
            tempos_minMax1_crescente.push_back(tempo_execucao);

            // Executar minMax1 e registrar o tempo de execução para vetores decrescentes
            MinMax::minMax1(vetorDecrescente, tempo_execucao, min_val, max_val);
            tempos_minMax1_decrescente.push_back(tempo_execucao);

            // Executar minMax2 e registrar o tempo de execução para vetores aleatórios
            MinMax::minMax2(vetorAleatorio, tempo_execucao, min_val, max_val);
            tempos_minMax2_aleatorio.push_back(tempo_execucao);

            // Executar minMax2 e registrar o tempo de execução para vetores crescentes
            MinMax::minMax2(vetorCrescente, tempo_execucao, min_val, max_val);
            tempos_minMax2_crescente.push_back(tempo_execucao);

            // Executar minMax2 e registrar o tempo de execução para vetores decrescentes
            MinMax::minMax2(vetorDecrescente, tempo_execucao, min_val, max_val);
            tempos_minMax2_decrescente.push_back(tempo_execucao);

            // Executar minMax3 e registrar o tempo de execução para vetores aleatórios
            MinMax::minMax3(vetorAleatorio, tempo_execucao, min_val, max_val);
            tempos_minMax3_aleatorio.push_back(tempo_execucao);

            // Executar minMax3 e registrar o tempo de execução para vetores crescentes
            MinMax::minMax3(vetorCrescente, tempo_execucao, min_val, max_val);
            tempos_minMax3_crescente.push_back(tempo_execucao);

            // Executar minMax3 e registrar o tempo de execução para vetores decrescentes
            MinMax::minMax3(vetorDecrescente, tempo_execucao, min_val, max_val);
            tempos_minMax3_decrescente.push_back(tempo_execucao);
        }

        /// Cálculo das médias dos tempos de execução para cada caso
        double media_tempo_minMax1_aleatorio_ms = accumulate(tempos_minMax1_aleatorio.begin(), tempos_minMax1_aleatorio.end(), 0.0) / numExecutions * 1000;
        double media_tempo_minMax1_crescente_ms = accumulate(tempos_minMax1_crescente.begin(), tempos_minMax1_crescente.end(), 0.0) / numExecutions * 1000;
        double media_tempo_minMax1_decrescente_ms = accumulate(tempos_minMax1_decrescente.begin(), tempos_minMax1_decrescente.end(), 0.0) / numExecutions * 1000;

        double media_tempo_minMax2_aleatorio_ms = accumulate(tempos_minMax2_aleatorio.begin(), tempos_minMax2_aleatorio.end(), 0.0) / numExecutions * 1000;
        double media_tempo_minMax2_crescente_ms = accumulate(tempos_minMax2_crescente.begin(), tempos_minMax2_crescente.end(), 0.0) / numExecutions * 1000;
        double media_tempo_minMax2_decrescente_ms = accumulate(tempos_minMax2_decrescente.begin(), tempos_minMax2_decrescente.end(), 0.0) / numExecutions * 1000;

        double media_tempo_minMax3_aleatorio_ms = accumulate(tempos_minMax3_aleatorio.begin(), tempos_minMax3_aleatorio.end(), 0.0) / numExecutions * 1000;
        double media_tempo_minMax3_crescente_ms = accumulate(tempos_minMax3_crescente.begin(), tempos_minMax3_crescente.end(), 0.0) / numExecutions * 1000;
        double media_tempo_minMax3_decrescente_ms = accumulate(tempos_minMax3_decrescente.begin(), tempos_minMax3_decrescente.end(), 0.0) / numExecutions * 1000;

        // Impressão dos resultados em milissegundos
        std::cout << "Size: " << size << std::endl;
        std::cout << "minMax1:" << std::endl;
        std::cout << "Dados Aleatório: Média do tempo de execução: " << media_tempo_minMax1_aleatorio_ms << " milissegundos" << std::endl;
        std::cout << "Dados Crescente: Média do tempo de execução: " << media_tempo_minMax1_crescente_ms << " milissegundos" << std::endl;
        std::cout << "Dados Decrescente: Média do tempo de execução: " << media_tempo_minMax1_decrescente_ms << " milissegundos" << std::endl;

        std::cout << "minMax2:" << std::endl;
        std::cout << "Dados Aleatório: Média do tempo de execução: " << media_tempo_minMax2_aleatorio_ms << " milissegundos" << std::endl;
        std::cout << "Dados Crescente: Média do tempo de execução: " << media_tempo_minMax2_crescente_ms << " milissegundos" << std::endl;
        std::cout << "Dados Decrescente: Média do tempo de execução: " << media_tempo_minMax2_decrescente_ms << " milissegundos" << std::endl;

        std::cout << "minMax3:" << std::endl;
        std::cout << "Dados Aleatório: Média do tempo de execução: " << media_tempo_minMax3_aleatorio_ms << " milissegundos" << std::endl;
        std::cout << "Dados Crescente: Média do tempo de execução: " << media_tempo_minMax3_crescente_ms << " milissegundos" << std::endl;
        std::cout << "Dados Decrescente: Média do tempo de execução: " << media_tempo_minMax3_decrescente_ms << " milissegundos" << std::endl;

        std::cout << std::endl;

        // Escreve no arquivo
        arquivo << size << "," << "Aleatório" << "," << "minMax1" << "," << media_tempo_minMax1_aleatorio_ms << "\n";
        arquivo << size << "," << "Crescente" << "," << "minMax1" << "," << media_tempo_minMax1_crescente_ms << "\n";
        arquivo << size << "," << "Decrescente" << "," << "minMax1" << "," << media_tempo_minMax1_decrescente_ms << "\n";

        arquivo << size << "," << "Aleatório" << "," << "minMax2" << "," << media_tempo_minMax2_aleatorio_ms << "\n";
        arquivo << size << "," << "Crescente" << "," << "minMax2" << "," << media_tempo_minMax2_crescente_ms << "\n";
        arquivo << size << "," << "Decrescente" << "," << "minMax2" << "," << media_tempo_minMax2_decrescente_ms << "\n";

        arquivo << size << "," << "Aleatório" << "," << "minMax3" << "," << media_tempo_minMax3_aleatorio_ms << "\n";
        arquivo << size << "," << "Crescente" << "," << "minMax3" << "," << media_tempo_minMax3_crescente_ms << "\n";
        arquivo << size << "," << "Decrescente" << "," << "minMax3" << "," << media_tempo_minMax3_decrescente_ms << "\n";
    }

    // Fecha o arquivo
        arquivo.close();
        std::cout << "Dados foram escritos com sucesso no arquivo.\n";
}

```

 </p> 
 <p align="justify">

 *Observação:* Foram usado as as funções _push_back()_ e _accumulate()_, essas funções são úteis para lidar com os dados dinâmicos gerados durante a execução dos métodos e para calcular estatísticas como média, que são usadas para avaliar o desempenho dos métodos.
 
 1. A função _push_back()_ é usada para adicionar elementos a um vetor dinâmico um vetor de double. Durante o loop de execução dos métodos para diferentes vetores e diferentes tipos de dados, os tempos de execução de cada chamada são registrados em vetores separados.
Como o número de execuções (numExecutions) não é conhecido antecipadamente, é mais conveniente usar _push_back()_ para adicionar os tempos de execução à medida que são calculados, permitindo que o vetor cresça dinamicamente conforme necessário.

 2. A função _accumulate()_ é usada para calcular a soma de todos os elementos em um intervalo de valores em um contêiner (como um vetor). No código é usada para calcular a soma de todos os tempos de execução registrados em um vetor. Após executar o método várias vezes para um determinado tipo de vetor (aleatório, crescente ou decrescente), a média dos tempos de execução é calculada dividindo a soma total dos tempos de execução pelo número total de execuções. Isso é feito através do uso de _accumulate()_ para somar todos os tempos de execução registrados, e então dividindo pelo número total de execuções (numExecutions).


### Código facilitador
<p align="justify">

Para facilitar a visualização e análise de resultados experimentais, foi criado um código que organiza os tempos de execução dos diferentes métodos em conjuntos de dados variados. Ele analisa os resultados do arquivo 'resultados.csv' e os armazena em um formato adequado para plotagem de gráficos, em 3 arquivos CSV. Isso permite uma análise comparativa do desempenho dos métodos em diferentes situações, facilitando a interpretação dos resultados experimentais.

```c++
void reorganizarResultados() {
    ifstream arquivo("./datasets/resultados.csv");

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo resultados.csv" << endl;
        return;
    }

    string linha;
    vector<string> minMax1Aleatorio, minMax1Crescente, minMax1Decrescente;
    vector<string> minMax2Aleatorio, minMax2Crescente, minMax2Decrescente;
    vector<string> minMax3Aleatorio, minMax3Crescente, minMax3Decrescente;

    // Lendo o arquivo e separando os dados
    while (getline(arquivo, linha)) {
        size_t pos = 0;
        vector<string> tokens;
        while ((pos = linha.find(',')) != string::npos) {
            tokens.push_back(linha.substr(0, pos));
            linha.erase(0, pos + 1);
        }
        tokens.push_back(linha); // O que resta é a última parte da linha

        string algoritmo = tokens[2];
        string tipoEntrada = tokens[1];
        string linhaFormatada = tokens[0] + "," + tokens[1] + "," + tokens[2] + "," + tokens[3];

        if (algoritmo == "minMax1") {
            if (tipoEntrada == "Aleatório") {
                minMax1Aleatorio.push_back(linhaFormatada);
            } else if (tipoEntrada == "Crescente") {
                minMax1Crescente.push_back(linhaFormatada);
            } else if (tipoEntrada == "Decrescente") {
                minMax1Decrescente.push_back(linhaFormatada);
            }
        } else if (algoritmo == "minMax2") {
            if (tipoEntrada == "Aleatório") {
                minMax2Aleatorio.push_back(linhaFormatada);
            } else if (tipoEntrada == "Crescente") {
                minMax2Crescente.push_back(linhaFormatada);
            } else if (tipoEntrada == "Decrescente") {
                minMax2Decrescente.push_back(linhaFormatada);
            }
        } else if (algoritmo == "minMax3") {
            if (tipoEntrada == "Aleatório") {
                minMax3Aleatorio.push_back(linhaFormatada);
            } else if (tipoEntrada == "Crescente") {
                minMax3Crescente.push_back(linhaFormatada);
            } else if (tipoEntrada == "Decrescente") {
                minMax3Decrescente.push_back(linhaFormatada);
            }
        }
    }

    // Escrevendo os resultados em arquivos separados
    ofstream arquivoMinMax1("./datasets/resultados_minMax1.csv");
    ofstream arquivoMinMax2("./datasets/resultados_minMax2.csv");
    ofstream arquivoMinMax3("./datasets/resultados_minMax3.csv");

    if (!arquivoMinMax1.is_open() || !arquivoMinMax2.is_open() || !arquivoMinMax3.is_open()) {
        cerr << "Erro ao criar os arquivos de saída." << endl;
        return;
    }

    for (const auto& linha : minMax1Aleatorio) {
        arquivoMinMax1 << linha << endl;
    }

    for (const auto& linha : minMax1Crescente) {
        arquivoMinMax1 << linha << endl;
    }

    for (const auto& linha : minMax1Decrescente) {
        arquivoMinMax1 << linha << endl;
    }

    for (const auto& linha : minMax2Aleatorio) {
        arquivoMinMax2 << linha << endl;
    }

    for (const auto& linha : minMax2Crescente) {
        arquivoMinMax2 << linha << endl;
    }

    for (const auto& linha : minMax2Decrescente) {
        arquivoMinMax2 << linha << endl;
    }

    for (const auto& linha : minMax3Aleatorio) {
        arquivoMinMax3 << linha << endl;
    }

    for (const auto& linha : minMax3Crescente) {
        arquivoMinMax3 << linha << endl;
    }

    for (const auto& linha : minMax3Decrescente) {
        arquivoMinMax3 << linha << endl;
    }

    cout << "Resultados reorganizados com sucesso!" << endl;

    // Fechando os arquivos
    arquivo.close();
    arquivoMinMax1.close();
    arquivoMinMax2.close();
    arquivoMinMax3.close();
}

```
<p align="justify">

Nesse código, os resultados de um arquivo CSV são reorganizados para facilitar a análise e visualização. Primeiro, o arquivo é aberto e lido linha por linha. Cada linha é dividida em tokens com base nas vírgulas. Os dados são então agrupados de acordo com o algoritmo usado (minMax1, minMax2 ou minMax3) e o tipo de entrada (aleatório, crescente ou decrescente).

Depois, os dados são escritos em arquivos separados para cada algoritmo e agrudpa dentro de cada aquivo o tipo de entrada. Por exemplo, os resultados de minMax1 para entradas aleatórias, crescente e decrescente são escritos em um arquivo, enquanto os resultados para minMax2 e minMax3 são escritos em outro. Isso facilita a análise específica de cada cenário de entrada para cada algoritmo.

Fim da implementação do minmax.cpp

<h2 align="center"> Gnuplot</h2>
       <p align="justify">
       O Gnuplot foi escolhido para gerar gráficos a partir dos dados do arquivo 'resultados.csv'. Analisando o desempenho de alguns algoritmos com seus processos em diferentes condições (Aleatório, Crescente e Decrescente) e para diferentes tamanhos de amostra.

Como podemos ver na imagem, foram criados 9 scripts para a criação dos gráficos

  <p align="center">
  <img height="200rem" src="/Imagens/scripts.png">
  </p>
      </p>


###  Gráficos 
<p align="justify">

Os scripts dos gráficos foram simples, primeniramente foi definido o separador de campos no arquivo de dados como vírgula. Isso é importante para garantir que o Gnuplot interprete corretamente as colunas do arquivo CSV. Logo depois, foi definido o terminal de saída como um arquivo PNG com uma largura de 900 pixels e altura de 400 pixels, e o nome do arquivo. Isso especifica o tamanho e nome da imagem de saída.

A instrução principal para plotar o gráfico está definida na última linha. Ela diz ao Gnuplot para usar os dados do arquivo '../datasets/resultados_minMax1.csv' e plotar apenas as linhas selecionadas. A coluna 1 é usada para o eixo x e a coluna 4 é usada para o eixo y. 

Um exepmlo de script é o _minmax1_aleatorio_:  A coluna 1 é usada para o eixo x e a coluna 4 é usada para o eixo y, pegando somente os dados gerados para o mimmax1 aleatório de todos os 4 vetores.

```gnuplot
set datafile separator ","
set terminal png size 900,400
set output 'MinMax1 Aleatório.png'
set title 'Tempo de execução para MinMax1'
set xlabel 'Tamanho do vetor'
set ylabel 'Tempo de execução (ms)'  
plot '../datasets/resultados_minMax1.csv' every ::1::4 using 1:4 with lp lw 2 lc rgb 'blue' title 'MinMax1 - Aleatório'

```

  - Em geral, todos os scripts foram criados da forma acima e mudam somente o nome do arquivo de entrada e a linhas que seram lidas.
    
<h2 align="center"> Resultados</h2>
       <p align="justify">

### Parte do Arquivo `resultados.csv`:
 Aqui está uma amostra de parte do arquivo `resultados.csv`, que contém os dados utilizados para gerar os gráficos:
```csv
1000,Aleatório,minMax1,0.0051
1000,Crescente,minMax1,0.0089
1000,Decrescente,minMax1,0.0087
1000,Aleatório,minMax2,0.005
1000,Crescente,minMax2,0.0082
1000,Decrescente,minMax2,0.0093
1000,Aleatório,minMax3,0.004
1000,Crescente,minMax3,0.0095
1000,Decrescente,minMax3,0.0077
10000,Aleatório,minMax1,0.0553
10000,Crescente,minMax1,0.0638
10000,Decrescente,minMax1,0.0632
10000,Aleatório,minMax2,0.0531
10000,Crescente,minMax2,0.0618
10000,Decrescente,minMax2,0.0631
10000,Aleatório,minMax3,0.0388
10000,Crescente,minMax3,0.0469
10000,Decrescente,minMax3,0.0488
100000,Aleatório,minMax1,0.441
100000,Crescente,minMax1,0.4543
100000,Decrescente,minMax1,0.4511
100000,Aleatório,minMax2,0.4409
100000,Crescente,minMax2,0.4532
100000,Decrescente,minMax2,0.4516
100000,Aleatório,minMax3,0.3217
100000,Crescente,minMax3,0.3338
100000,Decrescente,minMax3,0.3317
500000,Aleatório,minMax1,2.2101
500000,Crescente,minMax1,2.2215
500000,Decrescente,minMax1,2.2197
500000,Aleatório,minMax2,2.2051
500000,Crescente,minMax2,2.2216
500000,Decrescente,minMax2,2.2169
500000,Aleatório,minMax3,1.6101
500000,Crescente,minMax3,1.6124
500000,Decrescente,minMax3,1.6143

```
### Arquivo organizado 
  Aqui está uma amostra de parte do arquivo `resultados_minmax1.csv`, que contém os dados utilizados para gerar os gráficos:
```csv
1000,Aleatório,minMax1,0.0051
10000,Aleatório,minMax1,0.0553
100000,Aleatório,minMax1,0.441
500000,Aleatório,minMax1,2.2101
1000,Crescente,minMax1,0.0089
10000,Crescente,minMax1,0.0638
100000,Crescente,minMax1,0.4543
500000,Crescente,minMax1,2.2215
1000,Decrescente,minMax1,0.0087
10000,Decrescente,minMax1,0.0632
100000,Decrescente,minMax1,0.4511
500000,Decrescente,minMax1,2.2197

```

### Gráficos criados 
 Foram plotados 9 gráficos para a analise dos MinMax's. 

 1. MinMax1 Aleatório 
 2. MinMax1 Crescente
 3. MinMax1 Decrescente
 4. MinMax2 Aleatório 
 5. MinMax2 Crescente
 6. MinMax2 Decrescente
 7. MinMax3 Aleatório 
 8. MinMax3 Crescente
 9. MinMax3 Decrescente

### Conclusão

Analisando os Gráficos

1. MinMax1 Aleatório, MinMax2 aleatório e MinMax3 Aleatório

*  minMax1:
 </p>
 
- 1000 amostras: 0.0051
- 10000 amostras: 0.0553
- 100000 amostras: 0.441
- 500000 amostras: 2.2101

<p align="center">
  <img height="200rem" src="/Imagens/MinMax1 Aleatório.png">
  </p>
      </p>
Esses valores indicam um aumento significativo no tempo de execução à medida que o tamanho da amostra aumenta. Isso é esperado, já que o tempo de execução tende a aumentar com o tamanho dos conjuntos de dados.

* minMax2:
</p>

- 1000 amostras: 0.0078
</p>
- 10000 amostras: 0.071
</p>
- 100000 amostras: 0.6783
</p>
- 500000 amostras: 3.4126

<p align="center">
  <img height="200rem" src="/Imagens/MinMax2 Aleatório.png">
  </p>
      </p>
Os valores para minMax2 também mostram um aumento no tempo de execução com o aumento do tamanho da amostra, seguindo uma tendência semelhante à observada para minMax1. No entanto, os tempos de execução para minMax2 são um pouco maiores do que para minMax1 em todos os tamanhos de amostra.

* minMax3:
</p>

- 1000 amostras: 0.0058
</p>
- 10000 amostras: 0.0517
</p>
- 100000 amostras: 0.4993
</p>
- 500000 amostras: 2.4644
</p>

<p align="center">
  <img height="200rem" src="/Imagens/MinMax3 Aleatório.png">
  </p>
      </p>

Assim como nos casos anteriores, os valores para minMax3 mostram um aumento no tempo de execução com o aumento do tamanho da amostra. Os tempos de execução para minMax3 estão entre os valores observados para minMax1 e minMax2, mas seguem uma tendência semelhante.


* Análise geral:
</p>
- Todos os três métodos (minMax1, minMax2 e minMax3) mostram um aumento no tempo de execução à medida que o tamanho da amostra aumenta, o que é esperado.
</p>
- O método minMax1 parece ser o mais eficiente em termos de tempo de execução, seguido por minMax3 e minMax2, respectivamente.
</p>
- No entanto, a diferença de tempo de execução entre os métodos não é tão significativa, especialmente para tamanhos menores de amostra.
</p>
Essa análise sugere que, para o modo aleatório, o método minMax1 pode ser preferível devido ao seu menor tempo de execução em comparação com os outros métodos, pelo menos nos tamanhos de amostra observados. No entanto, é importante considerar outros aspectos do problema, como precisão e eficácia, ao escolher um método de minMax.


2. MinMax1 Crescente, MinMax2 Crescente e MinMax3 Crescente


<p align="center">
  <img height="200rem" src="/Imagens/MinMax1 Crescente.png">
  </p>
      </p>

<p align="center">
  <img height="200rem" src="/Imagens/MinMax2 Crescente.png">
  </p>
      </p>

<p align="center">
  <img height="200rem" src="/Imagens/MinMax3 Crescente.png">
  </p>
      </p>


- 


3. MinMax1 Decrescente, MinMax2 Decrescente e MinMax3 Decrescente


<p align="center">
  <img height="200rem" src="/Imagens/MinMax1 Decrescente.png">
  </p>
      </p>

<p align="center">
  <img height="200rem" src="/Imagens/MinMax2 Decrescente.png">
  </p>
      </p>

<p align="center">
  <img height="200rem" src="/Imagens/MinMax3 Decrescente.png">
  </p>
      </p>

- 

  <h2 align="center"> Compilação e Execução</h2>
       <p align="justify">

O código disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

       
| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

 <h2 align="center"> Contato</h2>
       <p align="justify">
<a href="https://instagram.com/mairaallacerda" target="_blank"><img loading="lazy" src="https://img.shields.io/badge/-Instagram-%23E4405F?style=for-the-badge&logo=instagram&logoColor=white" target="_blank"></a>
<a href = "mailto:mairaallacerd@gmail.com"><img loading="lazy" src="https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white" target="_blank"></a>
</div>



