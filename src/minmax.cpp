#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Para accumulate
#include <ctime>   // Para clock_t, clock
#include <cstdlib> // Para rand
#include <fstream>
#include "minmax.hpp"

using namespace std;

// Função para encontrar o mínimo e o máximo em um vetor de inteiros
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

// Função para gerar um vetor com valores aleatórios entre 0 e 1000
std::vector<int> gerarVetorAleatorio(int size)
{
    vector<int> vet(size);
    for (int i = 0; i < size; ++i)
    {
        vet[i] = rand() % 1001; // Números aleatórios entre 0 e 1000
    }
    return vet;
}

// Função para gerar um vetor com valores em ordem crescente
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

// Função para gerar um vetor com valores em ordem decrescente
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
// Função para executar e avaliar os métodos com diferentes tamanhos de entrada
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