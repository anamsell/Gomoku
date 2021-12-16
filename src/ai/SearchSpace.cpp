#include "SearchSpace.hpp"

using namespace std;

list<Position>      good_moves(Game game)
{
    list<Position>  possibles_good_moves;
    list<Area>      areas;
    Position        position(-1, -1);
    vector2d        goban;

    goban = game.get_goban();
    areas = all_areas(goban);

    while (++position.x != GOBAN_SIZE) {
        position.y = -1;
        while (++position.y != GOBAN_SIZE)
            if (position.is_empty_on(goban) && is_in_one_area(position, areas) && pos_is_possible(game, position))
                possibles_good_moves.push_back(position);
    }
    return possibles_good_moves;
}

bool            pos_is_possible(Game game, Position position)
{
    game.new_move(position);
    return game.new_move_is_valid();
}

bool            is_in_one_area(Position position, list<Area> areas)
{
    for (auto &area : areas)
        if (position.x >= area.up && position.x <= area.down && position.y >= area.left && position.y <= area.right)
            return true;
    return false;
}

list<Area>      all_areas(vector2d goban)
{
    Position        position(-1, -1);
    list<Area>      areas;

    while (++position.x != GOBAN_SIZE) {
        position.y = -1;
        while (++position.y != GOBAN_SIZE)
            if (!position.is_empty_on(goban))
                areas.push_back(new_area(position, goban));
    }
    return areas;
}

Area    new_area(Position position, vector2d &goban)
{
    Area    area;

    area.up = position.x;
    area.down = position.x;
    area.left = position.y;
    area.right = position.y;
    searching_dimension_of_area(position, goban, area, 5);
    removing_stone_of_area(goban, area);
    increase_size(area);
    return(area);
}

void    searching_dimension_of_area(Position position, vector2d& goban, Area& area, int depth)
{
    goban[position.x][position.y] = EMPTY_INTERSECTION;
    area.down = max(area.down, position.x);
    area.left = min(area.left, position.y);
    area.right = max(area.right, position.y);
    for (int i = -1; i < 2; i++)
        for (int j = -1; j < 2; j++)
            if (i || j)
                for (int multi = 0; multi != depth; multi++)
                    if (stone_in_area(multi*i, multi*j, position, goban, area, depth - multi))
                        break;

}

bool    stone_in_area(int dx, int dy, Position position, vector2d& goban, Area& area, int depth)
{
    position.move(dx, dy);
    if (!position.is_in_the_map())
        return false;
    if (position.is_empty_on(goban))
        return false;
    searching_dimension_of_area(position, goban, area, depth);
    return true;
}

void    increase_size(Area& area)
{
    if (area.up > 0)
        area.up--;
    if (area.down < GOBAN_SIZE - 1)
        area.down++;
    if (area.left > 0)
        area.left--;
    if (area.right < GOBAN_SIZE - 1)
        area.right++;
}

void    removing_stone_of_area(vector2d& goban, Area area)
{
    Position pos(area.up - 1 , area.left - 1);

    while(++pos.x <= area.down) {
        pos.y = area.left - 1;
        while(++pos.y <= area.right)
            goban[pos.x][pos.y] = EMPTY_INTERSECTION;
    }
}
