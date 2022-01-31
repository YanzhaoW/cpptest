#include <iostream>
#include <string>
#include <vector>
#include <math.h>

class ErrorHandle{
    public:
        enum ErrorLevel{
            PaperNotEnough = 1,
            OtherError
        };
        ErrorHandle() = default;
        ErrorHandle(const char* ms, ErrorLevel t):fms(ms), type(t){
        };
        
        void Print(){
            std::cerr <<"Error type "<<type << ": " << fms << std::endl;
        };

    private: 
        const char* fms {""};
        ErrorLevel type{ OtherError };
};



class Printer{
    public:
        Printer() = default;
        Printer(std::string name, int num):fname(name), fnum(num){};
        void Print(std::string str){
            int pnum = ceil(str.length()/5);
            if(pnum > fnum){
                throw ErrorHandle("not enough of paper", ErrorHandle::PaperNotEnough);
            }else{
                id++;
                std::cout <<id <<": "<< str << std::endl;
                fnum -= pnum;
            }
        };

    private:
        std::string fname{"A0"};
        int fnum {0};
        int id {0};
};



int main() {
    Printer A1 {"A1", 30};
    try{
        A1.Print("this is the first experimental result");
        A1.Print("this is the first experimental result");
        A1.Print("this is the first experimental result");
        A1.Print("this is the first experimental result");
        A1.Print("this is the first experimental result");
        A1.Print("this is the first experimental result");
    }
    catch(ErrorHandle ex){
        ex.Print();
    }
    return 0;
}
