#include "sample_lib.hpp"

SampleLib::SampleLib(uint8_t init_data){

    sampleData = init_data;
    status = 0;
    configValue = 0;
}

uint8_t SampleLib::initialize(){

    status = 1; // 初期化成功
    return status;
}

uint8_t SampleLib::checkStatus() {

    return status;
}

uint8_t SampleLib::config(uint8_t config_value) {

    configValue = config_value;

    return configValue;
}

void SampleLib::setData(uint8_t new_data) {

    sampleData = new_data;
}

uint8_t SampleLib::getData() const {

    return sampleData;
}
