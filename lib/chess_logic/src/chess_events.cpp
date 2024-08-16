#include "chess_events.h"

#include <algorithm>
#include <functional>
#include <vector>

ChessEvents::ChessEvents() = default;

ChessEvents::~ChessEvents() = default;

void ChessEvents::addListener(ChessEventType event,
                              ChessCallbackEmpty callback) {
  if (event == ChessEventType::GameStarted) {
    this->callbacksGameStarted_.push_back(callback);
  }

  if (event == ChessEventType::GameEnded) {
    this->callbacksGameEnded_.push_back(callback);
  }
}

void ChessEvents::addListener(ChessEventType event,
                              ChessCallbackWithMove callback) {
  if (event == ChessEventType::MoveMade) {
    this->callbacksMoveMade_.push_back(callback);
  }
}

void ChessEvents::addListener(ChessEventType event,
                              ChessCallbackWithPosition callback) {
  if (event == ChessEventType::HighlightSquare) {
    this->callbacksHighlightSquare_.push_back(callback);
  }

  if (event == ChessEventType::UnhighlightSquare) {
    this->callbacksUnhighlightSquare_.push_back(callback);
  }
}

void ChessEvents::removeListener(ChessEventType event,
                                 ChessCallbackEmpty callback) {
  if (event == ChessEventType::GameStarted) {
    auto it = std::find_if(
        this->callbacksGameStarted_.begin(), this->callbacksGameStarted_.end(),
        [&](const ChessCallbackEmpty& cb) {
          return cb.target<void()>() == callback.target<void>();
        });
    if (it != this->callbacksGameStarted_.end()) {
      this->callbacksGameStarted_.erase(it);
    }
  }

  if (event == ChessEventType::GameEnded) {
    auto it = std::find_if(
        this->callbacksGameEnded_.begin(), this->callbacksGameEnded_.end(),
        [&](const ChessCallbackEmpty& cb) {
          return cb.target<void()>() == callback.target<void>();
        });
    if (it != this->callbacksGameEnded_.end()) {
      this->callbacksGameEnded_.erase(it);
    }
  }
}

void ChessEvents::removeListener(ChessEventType event,
                                 ChessCallbackWithMove callback) {
  if (event == ChessEventType::MoveMade) {
    auto it = std::find_if(this->callbacksMoveMade_.begin(),
                           this->callbacksMoveMade_.end(),
                           [&](const ChessCallbackWithMove& cb) {
                             return cb.target<void(chess_move_t)>() ==
                                    callback.target<void(chess_move_t)>();
                           });
    if (it != this->callbacksMoveMade_.end()) {
      this->callbacksMoveMade_.erase(it);
    }
  }
}

void ChessEvents::removeListener(ChessEventType event,
                                 ChessCallbackWithPosition callback) {
  if (event == ChessEventType::HighlightSquare) {
    auto it = std::find_if(this->callbacksHighlightSquare_.begin(),
                           this->callbacksHighlightSquare_.end(),
                           [&](const ChessCallbackWithPosition& cb) {
                             return cb.target<void(ChessPosition)>() ==
                                    callback.target<void(ChessPosition)>();
                           });
    if (it != this->callbacksHighlightSquare_.end()) {
      this->callbacksHighlightSquare_.erase(it);
    }
  }

  if (event == ChessEventType::UnhighlightSquare) {
    auto it = std::find_if(this->callbacksUnhighlightSquare_.begin(),
                           this->callbacksUnhighlightSquare_.end(),
                           [&](const ChessCallbackWithPosition& cb) {
                             return cb.target<void(ChessPosition)>() ==
                                    callback.target<void(ChessPosition)>();
                           });
    if (it != this->callbacksUnhighlightSquare_.end()) {
      this->callbacksUnhighlightSquare_.erase(it);
    }
  }
}
