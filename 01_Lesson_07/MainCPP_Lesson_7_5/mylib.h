#pragma once

#include <iostream>

const size_t uiArraySize = 31;

namespace MyNS
{
    void InitializeArray(float* fArray, const size_t size);
    void PrintArray(const float* fArray, const size_t size);
    void ArrayValuesCount(const float* fArray, const size_t size);
};
