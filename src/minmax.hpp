#ifndef MINMAX_HPP
#define MINMAX_HPP
#include <iostream>
#include <vector>

// using namespace std;
class MinMax
{
public:
    static void minMax1(const std::vector<int> &vet, double &tempo_execucao, int &min_val, int &max_val);
    static void minMax2(const std::vector<int> &vet, double &tempo_execucao, int &min_val, int &max_val);
    static void minMax3(const std::vector<int> &vet, double &tempo_execucao, int &min_val, int &max_val);
};

static std::vector<int> gerarVetorAleatorio(int size);
static std::vector<int> gerarVetorCrescente(int size);
static std::vector<int> gerarVetorDecrescente(int size);

void avaliarMetodos();
void reorganizarResultados();

#endif // MINMAX_HPP
