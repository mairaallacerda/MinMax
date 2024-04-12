#include "minmax.hpp"
#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(nullptr)); // Inicializar a semente para gerar números aleatórios

    avaliarMetodos();
    reorganizarResultados();

    return 0;
}
