#ifndef FULL_GENERATIONAL_REPLACEMENT_HPP
#define FULL_GENERATIONAL_REPLACEMENT_HPP

#include "basic_adult_selection.hpp"

namespace ea
{

class full_generational_replacement : public basic_adult_selection
{
    public:
        full_generational_replacement(bool elitism, std::size_t count) : basic_adult_selection(elitism, count) {}
        virtual void operator()(const std::vector<basic_individual*>&,
                std::vector<basic_individual*>&) const;
};

}

#endif
