#include <cstddef>
#include <cstdint>
#include <cmath>

namespace project_euler
{

[[nodiscard]] [[gnu::pure]]
std::size_t sum_square_difference(const std::size_t number) noexcept
{
	std::int64_t square_of_sum = number * (number + 1) / 2;
	square_of_sum = square_of_sum * square_of_sum;

	const std::int64_t sum_of_squares = number * (number + 1) * (2 * number + 1) / 6;

	return std::abs(sum_of_squares - square_of_sum);
}

} // end of namespace project_euler