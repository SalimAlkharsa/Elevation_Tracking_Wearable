// C++ code
#include "edge-impulse-sdk/classifier/ei_run_classifier.h"

// C library
extern "C"
{
    int check_feature_array_size(int);
    void classifier_loop();
}

// Define the features array
static const float features[] = {
    0.0132, 1.5444, 0.6336, 0.7634, 95849.0234, 0.0068, 1.5303, 1.0000, 0.5878, 95849.0234, 0.0200, 1.5342, 0.9771, 0.7328, 95867.0938, 0.0215, 1.5049, 0.8779, 0.7099, 95849.0234, 7.9990, 1.5391, 0.4198, 0.7557, 95867.0938, 0.0166, 1.4307, 1.0763, 0.7710, 95867.0938, 0.0098, 1.5425, 0.6794, 0.7481, 95867.0938, 0.0239, 1.4717, 1.2748, 0.6870, 95867.0938, 0.0249, 1.4941, 1.1221, 0.6031, 95867.0938, 7.9990, 1.5049, 0.4809, 0.6183, 95867.0938, 0.0151, 1.5244, 0.7252, 0.6107, 95867.0938, 0.0229, 1.5405, 0.6718, 0.6947, 95867.0938, 0.0015, 1.5659, 0.8092, 0.8473, 95867.0938, 0.0269, 1.4590, 0.9389, 0.6489, 95867.0938, 0.0024, 1.5264, 1.0000, 0.6183, 95867.0938, 0.0117, 1.5151, 0.8626, 0.7634, 95846.4453, 0.0171, 1.4868, 0.9160, 0.6031, 95867.0938, 0.0146, 1.4175, 1.4504, 0.5649, 95846.4453, 0.0264, 1.4697, 0.8779, 0.7176, 95867.0938, 0.0063, 1.5620, 0.6336, 0.7786, 95846.4453, 0.0127, 1.5674, 0.7176, 0.5573, 95867.0938, 0.0264, 1.4038, 0.7252, 0.7252, 95867.0938, 0.0054, 1.5884, 0.9313, 0.8015, 95846.4453, 0.0234, 1.5405, 0.8015, 0.6718, 95846.4453, 0.0112, 1.5371, 0.7939, 0.7023, 95846.4453, 0.0190, 1.4365, 0.9771, 0.6947, 95846.4453, 0.0083, 1.6011, 0.6336, 0.6641, 95846.4453, 0.0361, 1.4121, 0.9466, 0.6260, 95846.4453, 7.9951, 1.5620, 1.4886, 0.7252, 95846.4453, 0.0205, 1.4141, 0.7710, 0.6412, 95846.4453, 7.9990, 1.6162, 0.8321, 0.6641, 95867.0938, 0.0156, 1.4014, 1.2137, 0.5725, 95867.0938, 0.0112, 1.5605, 0.8473, 0.5878, 95867.0938, 0.0098, 1.5415, 0.6870, 0.6718, 95846.4453, 0.0078, 1.5293, 0.7863, 0.7023, 95867.0938, 0.0186, 1.4341, 1.3053, 0.6336, 95846.4453, 0.0000, 1.5923, 0.6412, 0.7252, 95867.0938, 0.0317, 1.4463, 1.0153, 0.7023, 95846.4453, 0.0010, 1.5151, 1.0000, 0.6870, 95846.4453, 0.0195, 1.4438, 0.6565, 0.6718, 95846.4453};

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
int check_feature_array_size(int i)
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

    // invoke the impulse
    EI_IMPULSE_ERROR res = run_classifier(&features_signal, &result, false /* debug */);
    if (res != EI_IMPULSE_OK)
    {
        ei_printf("ERR: Failed to run classifier (%d)\n", res);
        printf("ERR: Failed to run classifier (%d)\n", res);
    }

    print_inference_result(result);
}
