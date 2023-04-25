// #include "UseRoot.hpp"
// #include <TCanvas.h>
// #include <TFile.h>
// #include <TH1D.h>
// #include <TROOT.h>
// #include <TRandom3.h>
// #include <TTree.h>
#include <array>
#include <chrono>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

void Loop()
{
    auto const loopSize = 100;
    for (auto i = 0; i < loopSize; i++)
    {
        std::cout << i << "\n";
    }
}

auto main() -> int
{
    auto str = std::string{ "asdfsadf" };
    std::cout << str << std::endl;
    return 0;
}
