#pragma once

#include <string>

#include "content-base.hpp"

namespace Pholos {

class TvShow : public ContentBase {
 public:
  TvShow() = default;

  TvShow(
    std::string name, int stat, double rating, int episode, int last_episode);

  TvShow(const TvShow &other) = default;
  TvShow &operator=(const TvShow &other) = default;

  TvShow(TvShow &&obj) noexcept = default;
  TvShow &operator=(TvShow &&obj) noexcept = default;

  ~TvShow() override = default;

  [[nodiscard]] std::string stat_as_string() const override;
  [[nodiscard]] std::string name() const override;
  [[nodiscard]] double rating() const override;
  [[nodiscard]] int stat() const override;
  [[nodiscard]] int episode() const;
  [[nodiscard]] int last_episode() const;

  void change_episose(int episode);
  void change_last_episode(int last_episode);

 private:
  int episode_{};
  int last_episode_{};
};
}  // namespace Pholos
