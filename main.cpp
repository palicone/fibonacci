////////////////////////////////////////////////////////////////////////////////////
// MIT License                                                                    //
//                                                                                //
// Copyright (c) 2022 primoz.alic@gmail.com                                       //
//                                                                                //
// Permission is hereby granted, free of charge, to any person obtaining a copy   //
// of this software and associated documentation files (the "Software"), to deal  //
// in the Software without restriction, including without limitation the rights   //
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      //
// copies of the Software, and to permit persons to whom the Software is          //
// furnished to do so, subject to the following conditions:                       //
//                                                                                //
// The above copyright notice and this permission notice shall be included in all //
// copies or substantial portions of the Software.                                //
//                                                                                //
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     //
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       //
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    //
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         //
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  //
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  //
// SOFTWARE.                                                                      //
////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

unsigned int Fibonacci(unsigned int n)
{
  unsigned int nSum = 0;
  unsigned int nMid = 1;
  while (n--)
  {
    nSum = nSum + nMid;
    nMid = nSum - nMid;
  }
  return nSum;
}

static unsigned int Fibonacci2(unsigned int n, void(*pfn)(unsigned int) = nullptr)
{
  unsigned int nSum = 0;
  unsigned int nMid = 1;
  while (pfn ? pfn(nSum) : false, n--)
  {
    nSum = nSum + nMid;
    nMid = nSum - nMid;
  }
  return nSum;
}

auto emptyFibonacciCallback = [](unsigned int n) {};

template<typename L = decltype(emptyFibonacciCallback)>
static unsigned int Fibonacci3(unsigned int n, L cb = emptyFibonacciCallback)
{
  unsigned int nSum = 0;
  unsigned int nMid = 1;
  while (cb(nSum), n--)
  {
    nSum = nSum + nMid;
    nMid = nSum - nMid;
  }
  return nSum;
}

int main(int argc, char** argv)
{
  std::cout << Fibonacci(8) << std::endl;
  std::cout << Fibonacci2(2) << std::endl;
  std::cout << Fibonacci3(4) << std::endl;

  Fibonacci2(7, [](unsigned int n)
    {
      std::cout << n << std::endl;
    });

  Fibonacci3(3, [](unsigned int n)
    {
      std::cout << n << std::endl;
    });
  return 0;
}
