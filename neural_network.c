#include <stdio.h>
#include <stdlib.h>
#include "neural_network.h"
#include "linked_list.h"
#include "constants.h"
#include "matrix.h"
#include "helpers.h"

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
        struct Matrix * weight = matrixNew(out_layer_count, in_layer_count);
        struct Matrix * bias = matrixNew(out_layer_count, 1);
        matrixRandomize(weight, -1.0, 1.0);
        matrixRandomize(bias, -1.0, 1.0);

        linkedListAppend(network->weights, weight);
        linkedListAppend(network->biases, bias);
    }

    struct Matrix * weight = matrixNew(output_nodes, out_layer_count);
    struct Matrix * bias = matrixNew(output_nodes, 1);

    matrixRandomize(weight, -1.0, 1.0);
    matrixRandomize(bias, -1.0, 1.0);

    linkedListAppend(network->weights, weight);
    linkedListAppend(network->biases, bias);

    return network;
}

void neuralNetworkForwardPropogate(struct NeuralNetwork * network, float inputs[], float outputs[]) {

    struct Matrix * matrix = matrixNew(network->input_nodes, 1);
    int i;

    for (i = 0; i < network->input_nodes; i++) {
        matrixSetValue(matrix,0,i,inputs[i]);
    }

    for (i = 0; i < network->weights->size; i++) {
        struct Matrix * weight = linkedListGet(network->weights,i);
        struct Matrix * bias = linkedListGet(network->biases, i);
        struct Matrix * new_matrix = matrixFromMultiply(weight,matrix);

        matrixAddMatrix(new_matrix, bias);
        matrixDispose(matrix);
        matrix = new_matrix;
    }

    for (i = 0; i < matrix->rows; i++) {
        outputs[i] = matrixGetValue(matrix,0,i);
    }

    matrixDispose(matrix);
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