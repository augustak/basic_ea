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
#include "basic_genetic_operator.hpp"
#include "evolutionary_algorithm.hpp"

using namespace ea;

int main()
{
    std::srand(std::time(0));
    /*
    std::vector<basic_individual*> young_adults;
    for(int i = 0; i < 10; ++i)
    {
        basic_genotype* gen = random_basic_genotype(32);
        basic_development dev;
        basic_phenotype* phen = dev(gen);
        young_adults.push_back(new basic_individual(gen, phen));
    }
    std::cout << "young adults" << std::endl;
    print_individuals(young_adults);

    std::vector<basic_individual*> adults;
    for(int i = 0; i < 10; ++i)
    {
        basic_genotype* gen = random_basic_genotype(32);
        basic_development dev;
        basic_phenotype* phen = dev(gen);
        adults.push_back(new basic_individual(gen, phen));
    }
    std::cout << "adults" << std::endl;
    print_individuals(adults);

    basic_adult_selection bas;
    std::vector<basic_individual*> new_adults = bas(young_adults, adults);
    std::cout << "all" << std::endl;
    print_individuals(new_adults);
    free_individuals(new_adults);
    */

    /*
    basic_development dev;

    basic_genotype* gen1 = random_basic_genotype(32);
    basic_phenotype* phen1 = dev(gen1);
    basic_individual* ind1 = new basic_individual(gen1, phen1);
    
    basic_genotype* gen2 = random_basic_genotype(32);
    basic_phenotype* phen2 = dev(gen2);
    basic_individual* ind2 = new basic_individual(gen2, phen2);
    std::cout << "other" << std::endl;
    std::cout << ind1->info() << std::endl;
    std::cout << ind2->info() << std::endl;
    basic_genetic_operator op;
    genotype_vector children = op(gen1, gen2);
    basic_genotype* new_geno1 = children[0];
    basic_genotype* new_geno2 = children[1];
    basic_phenotype* new_pheno1 = dev(new_geno1);
    basic_phenotype* new_pheno2 = dev(new_geno2);
    basic_individual* new_ind1 = new basic_individual(new_geno1, new_pheno1);
    basic_individual* new_ind2 = new basic_individual(new_geno2, new_pheno2);
    std::cout << new_ind1->info() << std::endl;
    std::cout << new_ind2->info() << std::endl;
    delete ind1;
    delete ind2;
    delete new_ind1;
    delete new_ind2;
    */

    const std::size_t NUM_CHILDREN = 5;
    genotype_vector children;
    for(std::size_t i = 0; i < NUM_CHILDREN; ++i)
    {
        children.push_back(random_basic_genotype(16));
    }
    evolutionary_algorithm ea;
    ea.init_children(children);
    const std::size_t NUM_LOOPS = 2;
    for(std::size_t i = 0; i < NUM_LOOPS; ++i)
    {
        ea.simulate_generation();
    }
    return 0;
}
