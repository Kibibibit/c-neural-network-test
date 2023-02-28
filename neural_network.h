#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

struct NeuralNetwork
{
    int input_nodes;
    int output_nodes;
    int * hidden_layer_nodes;
    int hidden_layer_count;
    struct LinkedList * weights;
    struct LinkedList * biases;
};

struct NeuralNetwork * neuralNetworkNew(int input_nodes, int output_nodes, int hidden_layer_count, int hidden_layer_nodes[]);

void neuralNetworkDispose(struct NeuralNetwork * network);

void neuralNetworkForwardPropogate(struct NeuralNetwork * network, float inputs[], float outputs[]);

#endif