#ifndef _CHESS_LOGIC_H_
#define _CHESS_LOGIC_H_

#include <vector>

#include "chess_board.h"
#include "chess_events.h"
#include "chess_game.h"
#include "chess_types.h"

class Chess : public ChessEvents, public ChessGame, public ChessBoard {
 public:
  Chess();
  ~Chess();
};

#endif  // _CHESS_LOGIC_H_
