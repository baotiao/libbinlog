#ifndef ITERATOR_H_
#define ITERATOR_H_

class Iterator {
public:
  Iterator();
  
  virtual bool Valid() const = 0;
  
  virtual bool Next() = 0;

  virtual void Seek(const std::string& target) = 0;

private:

  Iterator(const Iterator&);
  void operator=(const Iterator&);
};


#endif
