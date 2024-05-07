#include <iostream>
#include <vector>

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
void imprimirVetor(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Exemplo de uso
int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    cout << "Vetor original:" << endl;
    imprimirVetor(arr);
    quicksort(arr, 0, n - 1);
    cout << "Vetor ordenado:" << endl;
    imprimirVetor(arr);
    return 0;
}
