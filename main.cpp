#include <iostream>
#include "Generator.h"
#include "Methods.h"
#include "fstream"
#include "Paramethers.h"

int main() {
    /*Koncepcja jest taka :
     * Rozmnazanych 10% najlepszych z 5 % najgorszych
     * Populacja rozrasta sie do max 3 krotnego rozmiaru poczatkowego
     * P mutacji wynosi = 6
     * Po rozrosnieciu sie populacji usuwane są nadmiarowe, najgorsze osobniki
     * Prawdopodbienstwo mutacji zmniejsza sie z czasem
    */
    Paramethers params;
    //Test algorytmu:
    //1. Tworzenie populacji
    Generator generator(params.rozmiar_populacji,params.ilosc_maintancow);
    generator.GenerateTasks();
    generator.GenerateMaintances();
    vector<Operation> pom;
    vector<Operation> pom2;
    vector<Solution> population;
    int prev_size=0;
    for(int i =0;i<params.rozmiar_populacji;i++){
        Solution pom(generator);
        population.push_back(pom);
    }
    prev_size = population.size();
    ofstream file;
    file.open("test.csv");
    int end_time;
    for(int i=0;i<params.ilosc_iteracji;i++){
        end_time = 0;
        //mutacja
        if(genRandom(1,100)<params.p_mutacji){
            int j = genRandom(0,params.rozmiar_populacji-1);
            pom = population[j].getMachineA();
            pom =  mutate(pom);

            pom2 = population[j].getMachineB();
            pom2 =  mutate(pom2);

            compare(pom,pom2);
            population[j].setMachineA(pom);
            population[j].setMachineB(pom2);
        }
        //krzyzowanie
        int k;
        vector<Solution> children;
        for(k=0;k<population.size()/params.procent_krzyzowania;k++){
            Solution pom(generator);
            pom.setMachineA(crossover(population[k].getMachineA(),population[prev_size-k-1].getMachineA()));
            pom.setMachineA(crossover(population[k].getMachineB(),population[prev_size-k-1].getMachineB()));
            compare(pom.machineA,pom.machineB);
            children.push_back(pom);
        }
        for(auto item: children){
            population.push_back(item);
        }
        if(i%10) selection(population,generator);
        for(int k=0;k<population.size();k++){
            end_time+=fitness(population[k].getMachineA(),population[k].getMachineB());
            end_time = end_time/(int)population.size();
        }
        file<<i<<"\t"<<end_time<<"\n";
    }

    file.close();




}