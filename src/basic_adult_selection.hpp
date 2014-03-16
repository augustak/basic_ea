#ifndef BASIC_ADULT_SELECTION
#define BASIC_ADULT_SELECTION

#include <vector>
#include "basic_individual.hpp"

namespace ea
{

class basic_adult_selection
{
    public:
        basic_adult_selection(bool elitism, std::size_t count) : elitism_(elitism), count_(count) {}
        virtual ~basic_adult_selection() {}
        // all the young adults and adults are selected
        virtual void operator()(const std::vector<basic_individual*>&,
                std::vector<basic_individual*>&) const;
        void set_population_size(std::size_t size) { pop_size_ = size; }
    protected:
        bool elitism_;
        std::size_t count_;
        std::size_t pop_size_;
};

}

#endif
