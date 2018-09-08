#include <iostream>
using namespace std;

class Shape {
public:
  virtual Shape* clone() const = 0;
}

class Circle : public Shape  {
public:
  // ...
  virtual Circle* clone() const;
  // ...
};

Circle* Circle::clone() const
{
  return new Circle(*this);
}

class Square : public Shape {
public:
  // ...
  virtual Square* clone() const;
  // ...
};

Square* Square::clone() const
{
  return new Square(*this);
}

class Fred {
public:
  // p must be a pointer returned by new; it must not be NULL
  Fred(Shape* p) : p_(p) { assert(p != NULL); }
  ~Fred() { delete p_; }
  Fred(const Fred& f) : p_(f.p_->clone()) { }
  Fred& operator=(const Fred& f)
  {
    if (this != &f)// Check for self-assignment
    {
      Shape* p2 = f.p_->clone();   // Create the new one FIRST...
      delete p_;                   // ...THEN delete the old one
      p_ = p2;
    }
    return *this;
  }
  // ...
private:
  Shape* p_;
};
