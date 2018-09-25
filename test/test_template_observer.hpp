#include <template_observer/template_observer.h>
class MyObservable : public Observable< MyObservable,int >
{
  public:
    MyObservable(){};
    ~MyObservable(){};
};

class MyObserver : public Observer<MyObservable>
{
    public:
    MyObserver()
    {
    }
    ~MyObserver()
    {
    }
    void Update(MyObservable *p_obs)
    {
        int val = p_obs->GetState();
        std::cout << "Val = " << val << std::endl;
    }
};