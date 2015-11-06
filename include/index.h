#ifndef INDEX_H_
#define INDEX_H_

class Index {
public:

  int EncodeTo();
  int DecodeTo(char *ptr);

private:

  struct Chunk {
    int sid;
    int from;
    int to;
  };
  Chunk now_chunk_;
  queue<Chunk> chunks_;
  int fd_;
};

#endif
