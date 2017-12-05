#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <utility>

namespace nQueens
{
	bool check_chessboard_position(const std::pair<size_t, size_t>& current_coord, 
								   const std::vector<std::pair<size_t, size_t>>& queen_positions) {

   		for (size_t i{}; i != queen_positions.size(); i++) {

			if ((queen_positions[i].first == current_coord.first) || (queen_positions[i].second == current_coord.second)) {

				return false;

			}

			// allowed range of valid 2D coordinates: {0 <= x (row) < n}, {0 <= y (column) < n}

			if ((queen_positions[i].first < current_coord.first) && (queen_positions[i].second < current_coord.second)) {

				if ((current_coord.first - queen_positions[i].first) == (current_coord.second - queen_positions[i].second)) {
					return false;
				}

				
			}

			else if ((queen_positions[i].first < current_coord.first) && (queen_positions[i].second > current_coord.second)) {

				if ((current_coord.first - queen_positions[i].first) == (queen_positions[i].second - current_coord.second)) {
					return false;
				}

				
			}

			else if ((queen_positions[i].first > current_coord.first) && (queen_positions[i].second < current_coord.second)) {

				if ((queen_positions[i].first - current_coord.first) == (current_coord.second - queen_positions[i].second)) {
					return false;
				}

				 		
			}

			else if ((queen_positions[i].first > current_coord.first) && (queen_positions[i].second > current_coord.second)) {

				if ((queen_positions[i].first - current_coord.first) == (queen_positions[i].second - current_coord.second)) {
					return false;
				}

			}

		}

		return true;
	}
	
	std::string solveNQueens(const size_t n, const std::pair<size_t, size_t>& mandatoryQueenCoordinates)
	{

		std::vector<std::vector<char>> chessboard(n, std::vector<char>{});

		std::vector<std::pair<size_t, size_t>> queen_positions{};

		std::set<size_t> reserved_rows{};
		std::set<size_t> reserved_columns{};

		for (size_t i{}; i != n; i++) {

			chessboard[i].resize(n + 1);

			fill(begin(chessboard[i]), end(chessboard[i]), '.');

			chessboard[i][n] = '\n';

		}

		if ((mandatoryQueenCoordinates.first >= n) || (mandatoryQueenCoordinates.second >= n)) return std::string{};

		chessboard[mandatoryQueenCoordinates.first][mandatoryQueenCoordinates.second] = 'Q';

		queen_positions.emplace_back(std::make_pair(mandatoryQueenCoordinates.first, mandatoryQueenCoordinates.second));

		reserved_rows.insert(mandatoryQueenCoordinates.first);
		reserved_columns.insert(mandatoryQueenCoordinates.second);

		size_t number_of_queens{1};

		while (number_of_queens != n) {

			bool success{false};

			size_t i{};

			for (; i != n; i++) {

				if (reserved_rows.count(i)) continue;

				for (size_t j{}; j != n; j++) {

					if (reserved_columns.count(j)) continue;

					const std::pair<size_t, size_t> current_coord = std::make_pair(i, j);

					if (check_chessboard_position(current_coord, queen_positions)) {

						queen_positions.emplace_back(current_coord);

						chessboard[current_coord.first][current_coord.second] = 'Q';

						reserved_rows.insert(current_coord.first);

						reserved_columns.insert(current_coord.second);

						success = true;

						break;

					}

				}

				if (success) break;
			
			}

			if (!success && (i != n)) return std::string{};

			number_of_queens++;
		}

		auto chessboard_transposed { chessboard };

		std::string chessboard_table_str{};
		
		for (size_t i{}; i != n; i++) {

			for (size_t j{}; j != n; j++) {

				chessboard_transposed[i][j] = chessboard[j][i];

			}

		}		
		
		for (const auto& row : chessboard_transposed) {

			for (const char ch : row) {

				chessboard_table_str += ch;
			
			}

		}		
		
		return chessboard_table_str;
	}

}

using namespace std;

int main() {

	size_t n{4u}, x{2u}, y{0u};

	printf("1. chessboard's size: %lu, first queen's position: (%lu, %lu)\n\n", n, x, y);

	string output { nQueens::solveNQueens(n, std::make_pair(x, y)) };

	printf("%s\n\n", output.c_str());

	n = 8u;
	x = 3u;
	y = 0u;

	printf("2. chessboard's size: %lu, first queen's position: (%lu, %lu)\n\n", n, x, y);

	output = nQueens::solveNQueens(n, std::make_pair(x, y));

	printf("%s\n", output.c_str());

	return 0;
}
