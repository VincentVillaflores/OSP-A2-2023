#include "ReadDataFile.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::deque<pcb> ReadDataFile::ReadThisDataFile(const std::string& filename){
    std::ifstream datafile(filename);
    std::deque<pcb> pcbDeque;

    if (datafile.is_open()) {
        std::string line;
        while (std::getline(datafile, line)){
            std::stringstream ss(line);
            std::string field;
            std::deque<std::string> fields;

            while (std::getline(ss, field, ',')) {
                fields.push_back(field);
            }

            osp2023::id_type id = toIdType(fields.front());
            osp2023::time_type burstTime = toTimeType(fields.back());
            pcb newPCB = pcb(id, burstTime);

            pcbDeque.push_back(newPCB);
        }
        datafile.close();
    }
    else {
        std::cerr << "Error: datafile could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    return pcbDeque;
}

osp2023::id_type ReadDataFile::toIdType(const std::string& num){
    osp2023::id_type id;
    try {
        id = std::stoi(num);
    } catch (std::invalid_argument const &e) {
        std::cerr << "Bad input in Datafile: std::invalid_argument thrown" << std::endl;
        exit(EXIT_FAILURE);
    } catch (std::out_of_range const &e) {
        std::cerr << "Integer overflow in Datafile: std::out_of_range thrown" << std::endl;
        exit(EXIT_FAILURE);
    }

    return id;
}

osp2023::time_type ReadDataFile::toTimeType(const std::string& num){
    osp2023::time_type burstTime;
    try {
        burstTime = std::stoll(num);
    } catch (std::invalid_argument const &e) {
        std::cerr << "Bad input in Datafile: std::invalid_argument thrown" << std::endl;
        exit(EXIT_FAILURE);
    } catch (std::out_of_range const &e) {
        std::cerr << "Integer overflow in Datafile: std::out_of_range thrown" << std::endl;
        exit(EXIT_FAILURE);
    }

    return burstTime;
}