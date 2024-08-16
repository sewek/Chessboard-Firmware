#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "chess_types.h"

class ChessBoard {
 public:
  ChessBoard();
  ~ChessBoard();

 protected:
  /**
   * @brief Reset the board to the initial state.
   */
  void resetBoard();

 private:
};

#endif  // CHESS_BOARD_H
