#ifndef CHESS_LOGIC_TYPES_H
#define CHESS_LOGIC_TYPES_H

#include <cinttypes>
#include <functional>

#ifndef __cplusplus
#include <stdbool.h>
#endif

enum class chess_piece_color_t {
  kWhite = 0,
  kBlack,
};

enum class chess_piece_type_t {
  kPawn = 0,
  kKnight,
  kBishop,
  kRook,
  kQueen,
  kKing,
};

enum class chess_file_t {
  kA = 1,
  kB,
  kC,
  kD,
  kE,
  kF,
  kG,
  kH,
};

enum class chess_move_type_t {
  kNormal = 0x0,
  kCapture = 0x1,
  kCastling = 0x2,
  kCheck = 0x4,
  kCheckmate = 0x8,
  kPromotion = 0x10,
  kEnPassant = 0x20,
};

enum class chess_game_state_t {
  kGameNotStarted = 0,
  kGameInProgress,
  kGameEnded,
};

enum class chess_game_result_t {
  kResultWhiteWins = 0,
  kResultBlackWins,
  kResultDraw,
};

typedef struct {
  chess_piece_color_t color;
  chess_piece_type_t type;
} chess_piece_t;

typedef struct {
  chess_file_t file;
  uint8_t rank;
} chess_position_t;

typedef struct {
  chess_position_t from;
  chess_position_t to;
  chess_move_type_t type;
  chess_piece_t piece;
} chess_move_t;

enum class ChessEventType {
  GameStarted = 0,
  GameEnded,
  MoveMade,
  HighlightSquare,
  UnhighlightSquare,
};

#endif  // CHESS_LOGIC_TYPES_H
