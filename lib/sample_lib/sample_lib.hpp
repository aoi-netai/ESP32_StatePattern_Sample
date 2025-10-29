#ifndef SAMPLE_LIB_HPP
#define SAMPLE_LIB_HPP

#include <cstdint>

class SampleLib {

    public:

        SampleLib(uint8_t init_data);

        uint8_t initialize();
        uint8_t getData() const;

    private:

        uint8_t sample_data = 0;
};

#endif  // SAMPLE_LIB_HPP