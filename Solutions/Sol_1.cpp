#include <array>
#include <cassert>
#include <cstddef>
#include <utility>


namespace project_euler
{

[[nodiscard]] [[gnu::pure]]
std::size_t sum_of_multiples(std::size_t begin, std::size_t end, const std::array<std::size_t, 2>& multipliers) noexcept
{
	if(end < begin)
		std::swap(begin, end);

	end = end - 1;

	constexpr auto sum_of_range = [](const size_t r) noexcept -> size_t
	{
		return r * (r + 1) / 2;
	};


	size_t sum = 0;

	for(const auto& multiplier : multipliers)
	{
		assert(multiplier);
		sum += (sum_of_range(end / multiplier) - sum_of_range(begin / multiplier)) * multiplier;
	}

	const size_t common_multiplier = multipliers[0] * multipliers[1];

	sum -= (sum_of_range(end / common_multiplier) - sum_of_range(begin / common_multiplier)) * common_multiplier;

	return sum;
}

} // end of namespace project euler