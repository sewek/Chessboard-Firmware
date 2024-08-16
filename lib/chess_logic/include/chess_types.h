#ifndef CHESS_LOGIC_TYPES_H
#define CHESS_LOGIC_TYPES_H

#include <cinttypes>
#include <functional>

#ifndef __cplusplus
#include <stdbool.h>
#endif

using chess_piece_color_t = enum {
  kWhite = 0,
  kBlack,
};

using chess_piece_type_t = enum {
  kPawn = 0,
  kKnight,
  kBishop,
  kRook,
  kQueen,
  kKing,
};

using chess_file_t = enum {
  kA = 1,
  kB,
  kC,
  kD,
  kE,
  kF,
  kG,
  kH,
};

using chess_move_type_t = enum {
  kNormal = 0x0,
  kCapture = 0x1,
  kCastling = 0x2,
  kCheck = 0x4,
  kCheckmate = 0x8,
  kPromotion = 0x10,
  kEnPassant = 0x20,
};

using chess_game_state_t = enum {
  kGameNotStarted = 0,
  kGameInProgress,
  kGameEnded,
};

using chess_game_result_t = enum {
  kResultWhiteWins = 0,
  kResultBlackWins,
  kResultDraw,
};

using chess_piece_t = struct {
  chess_piece_color_t color;
  chess_piece_type_t type;
};

using chess_position_t = struct {
  chess_file_t file;
  uint8_t rank;
};

using chess_move_t = struct {
  chess_position_t from;
  chess_position_t to;
  chess_move_type_t type;
  chess_piece_t piece;
};

enum class ChessEventType {
  GameStarted = 0,
  GameEnded,
  MoveMade,
  HighlightSquare,
  UnhighlightSquare,
};

#endif  // CHESS_LOGIC_TYPES_H
