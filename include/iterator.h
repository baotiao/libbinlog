#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <string>

class Iterator {
public:
  Iterator();
  virtual ~Iterator();
  
  virtual bool Valid() const = 0;
  
  virtual void Next() = 0;

  virtual void Seek(const std::string& target) = 0;
  
  virtual void SeekToFirst() = 0;
  
  virtual std::string value() = 0;

private:

  Iterator(const Iterator&);
  void operator=(const Iterator&);
};


#endif
