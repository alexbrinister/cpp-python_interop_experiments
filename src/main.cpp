#include <iostream>
#include <random>
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cassert>

class RandomUintGenerator
{
public:
    RandomUintGenerator() : rd{}, engine{rd()}, dist(0, UINT32_MAX) {}

    uint32_t Get()
    {
        return dist(engine);
    }

private:
    std::random_device                        rd;
    std::default_random_engine                engine;
    std::uniform_int_distribution< uint32_t > dist;
};

extern "C"
{
    RandomUintGenerator* RandomUintGenerator_new()
    {
        return new RandomUintGenerator();
    }

    uint32_t RandomUintGenerator_get(RandomUintGenerator* obj)
    {
        return obj->Get();
    }

    void RandomUintGenerator_delete(RandomUintGenerator* obj)
    {
        delete obj;
    }
}

/*
int main()
{
    const size_t size = 5;

    RandomVec* randoVec = RandomVec_new(size);
    const uint32_t* vecArr = RandomVec_Get(randoVec);
    assert(vecArr != NULL);
    printf("Contents of array:\n");
    for(int i = 0; i < size; ++i)
    {
        printf("%u\n", vecArr[i]);
    }

    RandomVec_delete(randoVec);

    return 0;
}
*/
