#pragma once

#include <cstdio>

template<typename T>
struct SimpleUniquePointer
{
    SimpleUniquePointer() = default;
    SimpleUniquePointer(T* pointer) : pointer{pointer} {}
    ~SimpleUniquePointer() 
    {
        if (pointer) delete(pointer);
    }
    SimpleUniquePointer(const SimpleUniquePointer&) = delete;
    SimpleUniquePointer& operator=(const SimpleUniquePointer&) = delete;

    SimpleUniquePointer(SimpleUniquePointer&& other) noexcept
        : pointer{other.pointer}
    {
        other.pointer = nullptr;
    }

    SimpleUniquePointer& operator=(SimpleUniquePointer&& other)
    {
        if (pointer) delete(pointer);
        pointer = other.pointer;
        other.pointer = nullptr;
        return *this;
    }

    T* get() 
    {
        return pointer;
    }

private:
    T* pointer;
};

struct Tracer
{
    Tracer(const char* name) : name{ name }
    {
        printf("%s constructed.\n", name);
    }
    ~Tracer() 
    {
        printf("%s destructes.\n", name);
    }

private:
    const char* const name;
};


void consumer(SimpleUniquePointer<Tracer> consumer_ptr)
{
    printf("consumer 0x%p\n", consumer_ptr.get());
}