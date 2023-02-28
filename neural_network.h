#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

struct NeuralNetwork
{
    int input_nodes;
    int output_nodes;
    int * hidden_layer_nodes;
    struct LinkedList * weights;
    struct LinkedList * biases;
};

void neuralNetworkNew(int input_nodes, int output_nodes, int * hidden_layer_nodes);

#endif