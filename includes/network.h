/**
 * @file network.h
 * @author Minhyuk Park
 * @date 8 Jun 2018
 * @brief header file for network object
 */

#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "layer.h"

/**
 * @brief Network object
 * the network object acts as a layer between the 
 * user and the input,hidden, and output layers
 */

class Network {
    public:
        //! Constructor that calls _init_network
        Network(int _num_layers, int _input_unit, int _layer_unit, int _output_unit);
        matrix* affine_forward(matrix* a, Layer* layer);
        matrix* relu_forward(matrix* z);
        matrix* cross_entropy(matrix* f, matrix* a);
        void** affine_backward(matrix* df, matrix* a, Layer* layer);
        matrix* relu_backward(matrix* df, matrix* a_prev); 
        int import_data(std::string filename);
        int train_network();
        void test();
    private:
        double _update_layers(matrix* current_batch);
        double _calculate_accuracy(matrix* confusion_matrix);
        matrix* _build_confusion_matrix(matrix* f, matrix* current_batch);

        std::vector<Layer*>* _layers;
        std::vector<std::vector<double>>* _training_data;
        int _num_layers;
        int _input_unit;
        int _layer_unit;
        int _output_unit;
        int _EPOCH = 100;
        int _WEIGHT_SCALE = 0.01;
        int _BATCH_SIZE = 128;
        int _POLICY_SIZE = 10000;
        double _LEARNING_RATE = 0.1;
        matrix* _confusion_matrix;
        //! Initializes appropriate member variables
        int _init_network();
};

#endif
