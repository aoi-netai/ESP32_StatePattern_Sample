#ifndef SAMPLE_LIB_HPP
#define SAMPLE_LIB_HPP

#include <cstdint>

class SampleLib {

    public:

        SampleLib(uint8_t init_data);

        uint8_t initialize();
        uint8_t checkStatus();
        uint8_t config(uint8_t config_value);

        void setData(uint8_t new_data);
        uint8_t getData() const;

    private:

        uint8_t sampleData;
        uint8_t status;
        uint8_t configValue;
};



#endif  // SAMPLE_LIB_HPP