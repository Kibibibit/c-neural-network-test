#include "neural_network.h"

void neuralNetworkNew(int input_nodes, int output_nodes, int * hidden_layer_nodes) {

    struct NeuralNetwork *network = (struct NeuralNetwork *)malloc(sizeof(struct NeuralNetwork));

    network->input_nodes = input_nodes;
    network->output_nodes = output_nodes;
    network->hidden_layer_nodes = hidden_layer_nodes;

}
