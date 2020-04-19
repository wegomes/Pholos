#pragma once

#include <array>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

#include "movies.hpp"
#include "tv-show.hpp"

namespace Pholos {

class Controller {
  enum class Command {
    Help   = 0,
    Exit   = 1,
    Add    = 2,
    Edit   = 3,
    Delete = 4,
    Search = 5,
    Query  = 6,
    About  = 7,
    List   = 8
  };

 public:
  Controller() = default;

  Controller(const Controller &obj) = delete;
  Controller &operator=(const Controller &obj) = delete;
  Controller(Controller &&obj)                 = delete;
  Controller &operator=(Controller &&obj) = delete;

  ~Controller() = default;

  void press_any_key();  // This needs a better name
  void draw_menu();
  void help();
  void exit();
  void add_menu();
  void delete_element();
  int get_command(std::string_view command);
  void list_all();

 private:
  void add_movie();
  void add_tvshow();
  void delete_movie();
  void delete_tvshow();

 private:
  Command commands_{};
  static constexpr std::array commands_list = {"HELP",   "EXIT",  "ADD",   "EDIT", "DELETE",
                                               "SEARCH", "QUERY", "ABOUT", "LIST"};
  std::vector<Movies> movies_list_;
  std::vector<TvShow> tv_show_list_;
};
}  // namespace Pholos
