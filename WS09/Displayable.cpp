// Sean Ramolete
// 155074198

#include "Displayable.h"
namespace sict{
  std::ostream& operator<<(std::ostream& os, const Displayable& D){
    return D.display(os);
  }
}