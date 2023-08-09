

#include <cstdint>
struct Move {
  static const unsigned int startMask = 0b111111;
  static const unsigned int targetMask = 0b111111 << 6;
  static const unsigned int captureMask = 0b111111 << 12;
  static const unsigned int isPromotionMask = 1 << 16;
  static const unsigned int isCaptureMask = 1 << 17;

  uint32_t moveValue;
  Move(int moveValue);
  Move(int start, int target);
  Move(int start, int target, int capture);

  void setPromotion();

  int getStart() { return moveValue & startMask; }
  int getTarget() { return (moveValue & targetMask) >> 6; }
  int getCapture() { return (moveValue & captureMask) >> 12; }
  bool isCapture() { return (moveValue & isCaptureMask) != 0; }
  bool isPromotion() { return (moveValue & isPromotionMask) != 0; }
};
