#include <iostream>
#include <initializer_list>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>

#include "basic_phenotype.hpp"
#include "basic_genotype.hpp"
#include "basic_development.hpp"
#include "basic_individual.hpp"
#include "basic_fitness.hpp"
#include "basic_adult_selection.hpp"
#include "full_generational_replacement.hpp"
#include "over_production.hpp"
#include "generational_mixing.hpp"
#include "basic_parent_selection.hpp"
#include "fitness_proportionate.hpp"
#include "tournament_selection.hpp"
#include "basic_genetic_operator.hpp"
#include "basic_ideal_individual.hpp"
#include "one_max_ideal.hpp"
#include "evolutionary_algorithm.hpp"
#include "csv_writer.hpp"


using namespace ea;

int main()
{
    std::srand(std::time(0));
    int success = 0;
    std::size_t N = 1;
    for(std::size_t n = 0; n < N; ++n)
    {
    const std::size_t NUM_CHILDREN = 400;
    genotype_vector children;
    for(std::size_t i = 0; i < NUM_CHILDREN; ++i)
    {
        children.push_back(random_basic_genotype(40));
    }
    basic_development* bd = new basic_development();
    basic_fitness* bf = new basic_fitness();
    basic_adult_selection* bas = new full_generational_replacement();
    basic_parent_selection* bps = new fitness_proportionate();
    basic_genetic_operator* bgo = new basic_genetic_operator();
    basic_ideal_individual* bii = new one_max_ideal();
    const std::size_t POP_SIZE = 400;
    evolutionary_algorithm ea(bd, bf, bas, bps, bgo, bii, POP_SIZE);
    ea.init_children(children);
    const std::size_t NUM_LOOPS = 100;
    for(std::size_t i = 0; i < NUM_LOOPS; ++i)
    {
        //std::cout << "****************** Generation " << i << " *********************" << std::endl;
        basic_individual* ind = ea.simulate_generation();
        if(ind)
        {
            //std::cout << "Ideal individual found! @" << i << std::endl;
            ++success;
            //std::cout << ind->info() << std::endl;
            break;
        }
        if(i == NUM_LOOPS-1) std::cout << "not found" << std::endl;
    }
    }
    std::cout << "accuracy: " << success << "/" << N << std::endl;
    return 0;
}
