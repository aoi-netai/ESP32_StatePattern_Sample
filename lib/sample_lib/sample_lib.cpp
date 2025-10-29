#include "sample_lib.hpp"

SampleLib::SampleLib(uint8_t init_data){

    sample_data = init_data;
}

uint8_t SampleLib::initialize(){

    // なにもしない

    return sample_data;
}

uint8_t SampleLib::getData() const{

    return sample_data;
}