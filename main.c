#include <stdio.h>
#include "neural_network.h"


int main()
{

    int hidden_layers[] = {10,5,5};
    struct NeuralNetwork * network = neuralNetworkNew(4,3,3,hidden_layers);
    
    neuralNetworkDispose(network);

}