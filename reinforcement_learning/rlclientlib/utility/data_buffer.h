#pragma once
#include <string>
#include <vector>

namespace reinforcement_learning { namespace utility {

  class data_buffer {
  public:
    data_buffer();
    void reset();
    std::vector<unsigned char> buffer();
    uint8_t* data();
    size_t size() const;
    void remove_last();
    void append(const unsigned char* data, size_t len);
    std::string str() const;
    void reserve(size_t size);
    data_buffer& operator<<(const std::string& cs);
    data_buffer& operator<<(const char*);
    data_buffer& operator<<(size_t rhs);
    data_buffer& operator<<(float rhs);

  private:
    std::vector<unsigned char> _buffer;
  };

  class buffer_factory {
  public:
    buffer_factory();
    data_buffer* operator()() const;
  };
}}


