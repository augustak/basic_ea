#include <iostream>
#include <initializer_list>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <sstream>

typedef std::stringstream sstream;

#include "basic_phenotype.hpp"
#include "basic_genotype.hpp"
#include "basic_development.hpp"
#include "one_max_development.hpp"
#include "basic_individual.hpp"
#include "basic_fitness.hpp"
#include "basic_adult_selection.hpp"
#include "full_generational_replacement.hpp"
#include "over_production.hpp"
#include "generational_mixing.hpp"
#include "basic_parent_selection.hpp"
#include "fitness_proportionate.hpp"
#include "sigma_scaling.hpp"
#include "boltzmann_scaling.hpp"
#include "tournament_selection.hpp"
#include "basic_genetic_operator.hpp"
#include "basic_ideal_individual.hpp"
#include "one_max_ideal.hpp"
#include "evolutionary_algorithm.hpp"
#include "csv_writer.hpp"


using namespace ea;

int main(int argc, char** argv)
{

    std::srand(std::time(0));
    // handle command line arguments
    if(argc != 7)
    {
        std::cerr << "wrong arguments" << std::endl;
        return 0;
    }
    // read population size
    sstream ss0(argv[1]);
    std::size_t pop_size;
    ss0 >> pop_size;
    // read mutation rate
    sstream ss1(argv[2]);
    double mut_rate;
    ss1 >> mut_rate;
    // read crossover rate
    sstream ss2(argv[3]);
    double cross_rate;
    ss2 >> cross_rate;
    // read number of generations
    sstream ss3(argv[4]);
    std::size_t num_generations;
    ss3 >> num_generations;
    // read number of runs
    sstream ss4(argv[5]);
    std::size_t num_runs;
    ss4 >> num_runs;
    // read stream name
    sstream ss5(argv[6]);
    std::string out;
    ss5 >> out;

    int success = 0;
    for(std::size_t n = 0; n < num_runs; ++n)
    {
        genotype_vector children;
        for(std::size_t i = 0; i < pop_size; ++i)
        {
            children.push_back(random_basic_genotype(40));
        }
        basic_development* bd = new one_max_development();
        basic_fitness* bf = new basic_fitness();
        basic_adult_selection* bas = new full_generational_replacement();
        basic_parent_selection* bps = new boltzmann_scaling(100, 2);
        basic_genetic_operator* bgo = new basic_genetic_operator();
        basic_ideal_individual* bii = new one_max_ideal();
        evolutionary_algorithm ea(bd, bf, bas, bps, bgo, bii, pop_size, mut_rate, cross_rate, out);
        ea.init_children(children);
        for(std::size_t i = 0; i < num_generations; ++i)
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
        }
    }
    std::cout << "accuracy: " << success << "/" << num_runs << " = " << float(success)/float(num_runs) << std::endl;
    return 0;
}
