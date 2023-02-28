#include <stdio.h>
#include <stdlib.h>
#include "neural_network.h"
#include "linked_list.h"
#include "constants.h"
#include "matrix.h"

struct NeuralNetwork * neuralNetworkNew(int input_nodes, int output_nodes, int hidden_layer_count, int hidden_layer_nodes[]) {

    struct NeuralNetwork *network = (struct NeuralNetwork *)malloc(sizeof(struct NeuralNetwork));

    network->input_nodes = input_nodes;
    network->output_nodes = output_nodes;
    network->hidden_layer_nodes = hidden_layer_nodes;
    network->hidden_layer_count = hidden_layer_count;

    network->weights = linkedListNew();
    network->biases = linkedListNew();

    int i;
    int in_layer_count = input_nodes;
    int out_layer_count = in_layer_count;

    for (i = 0; i < network->hidden_layer_count; i++) {
        in_layer_count = out_layer_count;
        out_layer_count = hidden_layer_nodes[i];
        struct Matrix * weight = matrixNew(in_layer_count, out_layer_count);
        struct Matrix * bias = matrixNew(out_layer_count, 1);

        linkedListAppend(network->weights, weight);
        linkedListAppend(network->biases, bias);
    }

    struct Matrix * weight = matrixNew(out_layer_count, output_nodes);
    struct Matrix * bias = matrixNew(output_nodes, 1);

    linkedListAppend(network->weights, weight);
    linkedListAppend(network->biases, bias);

    return network;
}

void neuralNetworkDispose(struct NeuralNetwork * network) {
    int i;
    for (i = 0; i < network->weights->size; i++) {
        matrixDispose(linkedListGet(network->weights,i));
        matrixDispose(linkedListGet(network->biases,i));
    }
    linkedListDispose(network->weights);
    linkedListDispose(network->biases);
    free(network);
}