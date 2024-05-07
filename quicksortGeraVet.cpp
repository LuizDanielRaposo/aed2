#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

// Função para trocar dois elementos de um vetor
void trocar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Função para dividir o vetor e colocar o pivô em sua posição correta
int particionar(vector<int>& arr, int inicio, int fim) {
    int pivot = arr[fim]; // Pivô é o último elemento
    int i = (inicio - 1); // Índice do menor elemento

    for (int j = inicio; j <= fim - 1; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento
            trocar(arr[i], arr[j]);
        }
    }
    trocar(arr[i + 1], arr[fim]);
    return (i + 1);
}

// Função principal que implementa o algoritmo QuickSort
void quicksort(vector<int>& arr, int inicio, int fim) {
    if (inicio < fim) {
        // Obtém o índice do pivô
        int pi = particionar(arr, inicio, fim);

        // Ordena os elementos antes e depois do pivô
        quicksort(arr, inicio, pi - 1);
        quicksort(arr, pi + 1, fim);
    }
}

// Função de utilidade para imprimir um vetor
void imprimirVetor(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// Função para gerar um vetor de números aleatórios
vector<int> gerarVetorAleatorio(int tamanho, int min, int max) {
    vector<int> vetor;
    // Semente para a geração de números aleatórios baseada no tempo atual
    srand(time(nullptr));

    for (int i = 0; i < tamanho; ++i) {
        int num = min + rand() % (max - min + 1); // Gera um número aleatório entre min e max
        vetor.push_back(num);
    }
    return vetor;
}

int main() {
    // Define o tamanho do vetor e os limites mínimo e máximo dos números aleatórios
    int tamanho = 10;
    int min = 1;
    int max = 100;

    // Gera um vetor de números aleatórios
    vector<int> vetor = gerarVetorAleatorio(tamanho, min, max);

    cout << "Vetor original:" << endl;
    imprimirVetor(vetor);

    // Ordena o vetor usando o algoritmo QuickSort
    quicksort(vetor, 0, vetor.size() - 1);

    cout << "Vetor ordenado:" << endl;
    imprimirVetor(vetor);

    return 0;
}
