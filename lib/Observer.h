/*!
 * @file
 * @brief Template Observer (refer to design pattern)
 */
#pragma once
template <class Type_Observable>
class Observer
{
public:
  Observer(){};
  virtual ~Observer(){};
  virtual void Update(Type_Observable *p_observable) = 0;
};
