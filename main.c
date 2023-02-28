#include <stdio.h>
#include "neural_network.h"


int main()
{

    int hidden_layers[] = {10,5,5};
    struct NeuralNetwork * network = neuralNetworkNew(4,3,3,hidden_layers);
    
    float inputs[] = {1.0,2.0,3.0,3.0};
    float outputs[network->output_nodes];

    neuralNetworkForwardPropogate(network, inputs, outputs);

    for (int i = 0; i < network->output_nodes; i++) {
        printf("%f\n",outputs[i]);
    }

    neuralNetworkDispose(network);

}