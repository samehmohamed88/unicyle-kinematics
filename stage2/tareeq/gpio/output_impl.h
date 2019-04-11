#ifndef OUTPUT_IMPL_
#define OUTPUT_IMPL_

#include "gpio.h"
#include "output.h"

namespace tareeq {
  namespace gpio {
    
    template <typename TChip, typename TLine, typename TLineRequest>
      class OutputImpl : public Output, public Gpio<TChip,TLine,TLineRequest>
    {
      const std::string direction_ = std::string("output");

    public:
    OutputImpl(const int& line_number) : Gpio<TChip,TLine,TLineRequest>(line_number, direction_){};

      virtual const std::string &GetDirection()
      {
	return direction_;
      };
      
      virtual void OutputValue(int value) 
      {
	this->line_.set_value(value);
      };
      
    };
  } // namespace gpio
} // namespace tareeq

#endif // OUTPUT_IMPL_
