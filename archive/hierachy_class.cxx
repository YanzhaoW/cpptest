#include <iostream>
#include <string>
#include <vector>

class Base {
   public:
    Base() {
        std::cout << "Initialization of base class" << std::endl;
    }
    virtual ~Base(){
        std::cout << "delete the base class" << std::endl;
    }
    void virtual print(int i) { print(); }
    void virtual print() {print(0);}
};

class B{
    public:
    B(std::string n): name(n)
    {
        std::cout << "Initialization of class B" << std::endl;
    }
    ~B(){
        std::cout << "delete the class B with name: " << name << std::endl;
    }
    std::string GetName() const
    {
        return name;
    }
    private:
        std::string name;
};

class A : public Base {
   public:
    A(){
        std::cout << "Initialization of derived class" << std::endl;
    }
    ~A(){
        std::cout << "delete the derived class" << std::endl;
    }
    void print(int i) { std::cout << "this is class A with " <<i << std::endl; }
    void Set(std::unique_ptr<B> b) { obj = std::move(b);}
    void Init(){
        if (!obj)
            obj = std::make_unique<B>("default");
    }
    B* GetObj() const
    {
        return obj.get();
    }

   private:
    std::unique_ptr<B> obj;
};


int main() {
    auto a = new A();
    auto b = std::unique_ptr<B>(new B("new"));

    a->Init();
    a->Set(std::move(b));

    std::cout << a->GetObj() ->GetName() << std::endl;;
    delete a;
}
