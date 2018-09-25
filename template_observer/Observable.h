/*!
 * @file
 * @brief Template Observable (refer to design pattern)
 */
#pragma once
#include <vector>
#include <iterator>
#include <algorithm>
#include <template_observer/Observer.h>

template <class Type_Observable, class Type_State>
class Observable
{
public:
  Observable(){};
  ~Observable(){};

  int AddObserver(Observer<Type_Observable> *p_observer)
  {
    int l_status = 1;
    if (NULL != p_observer)
    {
      m_observerList.push_back(p_observer);
    }
    return (l_status);
  }
  int RemoveObserver(Observer<Type_Observable> *p_observer)
  {
    int l_status = 1;

    class std::vector<Observer<Type_Observable> *>::iterator l_it = std::find(m_observerList.begin(), m_observerList.end(), p_observer);

    if (l_it != m_observerList.end())
    {
      m_observerList.erase(l_it);
    }
    return (l_status);
  }
    Type_State &GetState()
    {
        return m_state;
    }

    void SetState(const Type_State &p_state)
    {
        m_state = p_state;
         this->NotifyObserver();
    }


protected:
  void NotifyObserver()
  {

    typename std::vector<Observer<Type_Observable> *>::iterator l_itb = m_observerList.begin();
    typename std::vector<Observer<Type_Observable> *>::const_iterator l_ite = m_observerList.end();
    for (; l_itb != l_ite; ++l_itb)
    {
      (*l_itb)->Update(static_cast<Type_Observable*>(this));
    }
  }

private:
  std::vector<Observer<Type_Observable> *> m_observerList;
  Type_State m_state;
};
