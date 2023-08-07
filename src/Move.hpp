

#include <cstdint>
struct Move {
  static const int startMask = 0b111111;
  static const int targetMask = 0b111111 << 6;
  static const int captureMask = 0b111111 << 12;
  static const int isPromotion = 1 << 16;

  uint32_t moveValue;
  Move(int moveValue);
  Move(int start, int target);
  Move(int start, int target, int capture);

  void setPromotion();

  int getStart();
  int getTarget();
  int getCapture();
};
