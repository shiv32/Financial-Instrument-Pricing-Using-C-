#include <iostream>
#include <memory>

template <typename T>
using SP = std::shared_ptr<T>;
using value_type = double;

// memory deleter
template <typename T>
struct Deleter
{
    void operator()(T *t) const
    {
        std::cout << "delete memory from funtion object\n";
        delete t;
    }
};

int main()
{
    // std::cout<<"hello world"<<std::endl;
    /*
    // empty shared ptr
    SP<value_type> sp1;

    // empty shared ptr for c++11 nullptr
    SP<value_type> sp2(nullptr);

    // ptr owning raw ptr
    SP<value_type> sp3(new value_type(148.413));

    // share ownership with sp3
    SP<value_type> sp4(sp3);

    // share ownership with sp3 and sp4
    SP<value_type> sp5(sp4);

    // the number of shared owners
    std::cout << "sp2 shared # " << sp2.use_count() << '\n';
    std::cout << "sp3 shared # " << sp3.use_count() << '\n';
    std::cout << "sp4 shared # " << sp4.use_count() << '\n';

    sp3 = sp2; // sp3 now shares ownership with sp2
    // sp3 no longer has ownership of its previous resourse

    std::cout << "sp3 shared # " << sp3.use_count() << '\n';
    std::cout << "sp4 shared # " << sp4.use_count() << '\n';
    */
    //--------------------------------------------------------------------------
    // deleter as function object
    SP<value_type> sp(new value_type(148.413), Deleter<value_type>());

    // deleter as lambda funtion
    SP<value_type> sp2(new value_type(148.413), [](value_type *p)
                       {
                 std::cout<<"bye\n";
                 delete p; });

    // stored lambda funtion as deleter
    auto deleter = [](value_type *p)
    {
        std::cout << "bye deleter\n";
        delete p;
    };

    SP<value_type> sp3(new value_type(148.413), deleter);

    //##

    return 0;
}