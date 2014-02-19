#ifndef SIGMA_SCALING_HPP
#define SIGMA_SCALING_HPP

#include "basic_individual.hpp"
#include "basic_parent_selection.hpp"

namespace ea
{

class sigma_scaling : public basic_parent_selection
{
    public:
        virtual individual_pair_vector operator()(const individual_vector&);
};

double sigma(basic_individual*, double, double);

}

#endif
