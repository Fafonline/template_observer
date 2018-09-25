#include <template_observer/template_observer.h>

#include <iostream>

//using namespace std;


template <class Type_State>
class MyObservable : public Observable< MyObservable<Type_State> >
{
  public:
    MyObservable(){};
    ~MyObservable(){};

    Type_State &GetState()
    {
        return m_state;
    }

    void SetState(const Type_State &p_state)
    {
        m_state = p_state;
         this->NotifyObserver();
    }

  private:
    Type_State m_state;
};

class MyObserver : public Observer<MyObservable<int> >
{
    public:
    MyObserver()
    {
    }
    ~MyObserver()
    {
    }
    void Update(MyObservable<int> *p_obs)
    {
        int val = p_obs->GetState();
        std::cout << "Val = " << val << std::endl;
    }
};

int
main(int argc, char const *argv[])
{
    /* code */

    MyObservable<int> observable;

    MyObserver observer;

    std::cout << " Test Template Observer" << std::endl;
    
    observable.AddObserver(&observer);

    observable.SetState(4);
    observable.SetState(6);

    return 0;
}
