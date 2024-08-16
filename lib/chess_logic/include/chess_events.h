#ifndef CHESS_EVENTS_H
#define CHESS_EVENTS_H

#include <functional>
#include <vector>

#include "chess_position.h"
#include "chess_types.h"

using ChessCallbackEmpty = std::function<void()>;
using ChessCallbackWithMove = std::function<void(chess_move_t)>;
using ChessCallbackWithPosition = std::function<void(ChessPosition)>;

class ChessEvents {
 public:
  ChessEvents();
  ~ChessEvents();

  void addListener(ChessEventType event, ChessCallbackEmpty callback);
  void addListener(ChessEventType event, ChessCallbackWithMove callback);
  void addListener(ChessEventType event, ChessCallbackWithPosition callback);

  void removeListener(ChessEventType event, ChessCallbackEmpty callback);
  void removeListener(ChessEventType event, ChessCallbackWithMove callback);
  void removeListener(ChessEventType event, ChessCallbackWithPosition callback);

 private:
  std::vector<ChessCallbackEmpty> callbacksGameStarted_;
  std::vector<ChessCallbackEmpty> callbacksGameEnded_;
  std::vector<ChessCallbackWithMove> callbacksMoveMade_;
  std::vector<ChessCallbackWithPosition> callbacksHighlightSquare_;
  std::vector<ChessCallbackWithPosition> callbacksUnhighlightSquare_;
};

#endif  // CHESS_EVENTS_H
