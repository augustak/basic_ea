#ifndef BOLTZMANN_SCALING_HPP
#define BOLTZMANN_SCALING_HPP

#include "basic_individual.hpp"
#include "basic_parent_selection.hpp"

namespace ea
{

class boltzmann_scaling : public basic_parent_selection
{
    public:
        boltzmann_scaling(double, double);
        virtual individual_pair_vector operator()(const individual_vector&);
    private:
        double temp_;
        double d_temp_;
};

}

#endif
