#ifndef BASIC_ADULT_SELECTION
#define BASIC_ADULT_SELECTION

#include <vector>
#include "basic_individual.hpp"

namespace ea
{

class basic_adult_selection
{
    public:
        virtual ~basic_adult_selection() {}
        // all the young adults and adults are selected
        virtual void operator()(const std::vector<basic_individual*>&,
                std::vector<basic_individual*>&) const;
        void set_population_size(std::size_t size) { POP_SIZE = size; }
    protected:
        std::size_t POP_SIZE;
};

}

#endif
