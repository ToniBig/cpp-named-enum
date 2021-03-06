// The MIT License (MIT)
//
// Copyright (c) 2016 Nils Zander, Tino Bog
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "../named_enum.hpp"
#include <iostream>
#include <string>

MAKE_NAMED_ENUM_CLASS( Colors, GREEN, YELLOW, RED );

class TrafficLight {
public:
  TrafficLight( Colors color ) :
          color_( color ){
    std::cout << "Initialized signal with: " << get_name( ) << std::endl;
  }

  void set_color( Colors color ){
    color_ = color;
    std::cout << "Set signal to: " << get_name( ) << std::endl;
  }

  Colors get_color( ) const{
    return color_;
  }

  std::string get_name( ) const{
    return named_enum::name( color_ );
  }

private:
  Colors color_;
};

constexpr auto green=named_enum::name(Colors::GREEN);
constexpr auto red=named_enum::name(Colors::RED);
constexpr auto yellow=named_enum::name(Colors::YELLOW);

int main( int argc,
          char **argv ){
  TrafficLight signal( Colors::RED );

  signal.set_color( Colors::YELLOW );

  signal.set_color( Colors::GREEN );

  auto current_color = signal.get_name( );

  std::cout << "current_color: " << current_color << std::endl;

  std::cout << "Available colors are:";

  for ( const auto & color : named_enum::names<Colors>( ) ) {
    std::cout << " " << color;
  }

  std::cout << std::endl;
}
