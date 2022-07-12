#include <iostream>
#include <vector>
#include "parallel_hashmap/phmap.h"

struct TransactionIndex
{
    uint32_t block;
    uint16_t transaction;
};

using phmap::parallel_flat_hash_map;

struct OutputIndex
{
    uint64_t amount;
    uint64_t color;

    bool operator==(const OutputIndex &o) const
    { 
        return amount == o.amount && color == o.color; 
    }

    friend size_t hash_value(const OutputIndex &p)
    {
        return phmap::HashState().combine(0, p.amount, p.color);
    }
};

typedef parallel_flat_hash_map<OutputIndex, std::vector<std::pair<TransactionIndex, uint16_t>>> outputs_container_mock;

int main(int argc, char **argv) 
{
    TransactionIndex transactionIndex = {0};
    outputs_container_mock m_outputs;

    for(size_t i=0; i < 100000000; i++)
    {
        m_outputs[OutputIndex{i, 0}].push_back(std::make_pair<>(transactionIndex, 0));
    }
    return 0;
}
