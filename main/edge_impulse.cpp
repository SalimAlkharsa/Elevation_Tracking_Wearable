// C++ code
#include "edge-impulse-sdk/classifier/ei_run_classifier.h"
#include "cpp_code.h"
#include "model.c"

// C library
extern "C"
{
    int check_feature_array_size();
    void classifier_loop();
}

// Declare the 'features' array from main.c
extern float features[(9 * 5)]; // 9 features, 5 time steps

// C function to get the data from the 'features' array
int raw_feature_get_data(size_t offset, size_t length, float *out_ptr)
{
    memcpy(out_ptr, features + offset, length * sizeof(float));
    return 0;
}

// C function to print the inference result
void print_inference_result(ei_impulse_result_t result)
{

    // Print how long it took to perform inference
    ei_printf("Timing: DSP %d ms, inference %d ms, anomaly %d ms\r\n",
              result.timing.dsp,
              result.timing.classification,
              result.timing.anomaly);
    ei_printf("Predictions:\r\n");
    for (uint16_t i = 0; i < EI_CLASSIFIER_LABEL_COUNT; i++)
    {
        ei_printf("  %s: ", ei_classifier_inferencing_categories[i]);
        ei_printf("%.5f\r\n", result.classification[i].value);
    }
}

////////////////////////////////////////////////////////////////////
// Below is the C++ function that will be called from the C code //
//////////////////////////////////////////////////////////////////

// C++ function to check the size of the 'features' array above
int check_feature_array_size()
{
    // Check the size of the 'features' array
    if (sizeof(features) / sizeof(float) != EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE)
    {
        ei_printf("Error: Incorrect 'features' array size. Expected %d items, but had %u\n",
                  EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, sizeof(features) / sizeof(float));
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to run the classifier in the while loop
void classifier_loop()
{
    // This is potentially bad practice but I will define the result as a null pointer here
    ei_impulse_result_t result = {nullptr};

    // the features are stored into flash, and we don't want to load everything into RAM
    signal_t features_signal;
    features_signal.total_length = sizeof(features) / sizeof(features[0]);
    features_signal.get_data = &raw_feature_get_data;

    // Run the classifier (using XGB)
    // the implementation of this solution is hacky
    // I first run through the dummy edge impulse model to get the dsp file
    // then I run the XGB classifier (score) with the dsp file

    // Run the dummy edge impulse model
    EI_IMPULSE_ERROR res = run_classifier(&features_signal, &result, false /* debug */);
    if (res != EI_IMPULSE_OK)
    {
        ei_printf("ERR: Failed to run classifier (%d)\n", res);
        printf("ERR: Failed to run classifier (%d)\n", res);
    }

    // Copy the DSP
    double input[(9 * 7)]; // 9 sensors used, 7 flattened features
    double output[5];      // 5 classes
    // Copy the features into the input array

    // // invoke the impulse

    print_inference_result(result);
}
