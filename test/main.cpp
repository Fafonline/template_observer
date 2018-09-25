
#include <iostream>

#include "test_template_observer.hpp"

int
main(int argc, char const *argv[])
{
    /* code */

    MyObservable observable;

    MyObserver observer;

    std::cout << " Test Template Observer" << std::endl;
    
    observable.AddObserver(&observer);

    observable.SetState(3);
    observable.SetState(5);

    return 0;
}
