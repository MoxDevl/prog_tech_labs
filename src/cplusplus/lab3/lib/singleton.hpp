#pragma once


class Singleton {
    Singleton() {};
public:
    Singleton& operator=(const Singleton&) = delete;
    Singleton(const Singleton&) = delete;
    
    static Singleton& getInstance();
};