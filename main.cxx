#include "UseRoot.hpp"
#include <TCanvas.h>
#include <TFile.h>
#include <TH1D.h>
#include <TROOT.h>
#include <TRandom3.h>
#include <TTree.h>
#include <array>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

auto func(int num = 10) -> int { return num; }

auto main() -> int
{
    auto inte = func(10);
    return 0;
}
