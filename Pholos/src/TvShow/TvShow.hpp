#pragma once

#include "Stats.hpp"

#include <map>
#include <string>
#include <utility>

namespace Pholos {

class TvShow {
   public:
    TvShow() = default;
    explicit TvShow(std::string name);
    TvShow(std::string name, int year, double rating);

    TvShow(const TvShow &other);
    TvShow &operator=(const TvShow &other);

    TvShow(const TvShow &&obj);
    TvShow &operator=(const TvShow &&obj);

    ~TvShow() = default;

    std::string getName() const;
    int getYear() const;
    double getRating() const;
    Stats getStats() const;
    std::map<int, int> getSeasons() const;

    void setName(const std::string &name);
    void setYear(int year);
    void setRating(double rating);
    void setStats(int response);
    void addSeason(int season, int episode);

   private:
    std::string name_{};
    std::map<int, int> season_{};
    int year_{};
    double rating_{};
    Stats stats_ = Stats::PlanToWatch;
};
}  // namespace Pholos
