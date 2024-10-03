#pragma once



struct bucket 
{
    const static size_t s_data_size{ 4096 };
    const static size_t l_data_size{ 1000000 };

    void set(size_t size)
    {   
        data = new byte[size];
    }

    std::byte* data{nullptr};
};

struct heap
{
    void* allocate(size_t bytes)
    {
        if (bytes > bucket::l_data_size)
        {
            throw std::bad_alloc{};
        }

        size_t size = bytes < bucket::l_data_size ? bucket::s_data_size : bucket::l_data_size;

        for (size_t i{}; i < n_heap_buckets; i++)
        {
            if (!buckets[i].data)
            {
                buckets[i].set(size);
                return buckets[i].data;
            }
        }
        throw std::bad_alloc{};
    }

    void free(void* p)
    {
        for (size_t i{}; i < n_heap_buckets; i++)
        {
            if (buckets[i].data == p)
            {
                delete[] buckets[i].data;
                buckets[i].data = nullptr;
                return;
            }
        }
    }

    static const size_t n_heap_buckets{ 10 };
    bucket buckets[n_heap_buckets];;
};