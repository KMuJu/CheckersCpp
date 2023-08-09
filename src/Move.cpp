
#include "Move.hpp"

Move::Move(int moveValue) {
  // used to create illegalmove
  this->moveValue = moveValue;
}

Move::Move(int start, int target) {
  // first 6 bits is start, next 6 bits is target
  moveValue = start + (target << 6);
}

Move::Move(int start, int target, int capture) {
  // sets capture bits
  moveValue = start + (target << 6) + (capture << 12) + isCaptureMask;
}

void Move::setPromotion() {
  // sets move to promotion
  moveValue |= isPromotionMask;
}
