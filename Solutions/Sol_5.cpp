#include <cstddef>
#include <algorithm>


namespace project_euler
{

[[nodiscard]] [[gnu::pure]]
std::size_t highly_composite_number() noexcept
{
	constexpr std::size_t factor = 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19;

	constexpr std::size_t divisors[] = {4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20};

	std::size_t num = 0;
	for (int i = 1; i < 100000; ++i)
	{
		num += factor;

		const bool found = std::ranges::all_of(divisors, [=](const std::size_t e) -> bool {return num % e == 0;});

		if (found) [[unlikely]]
			return num;
	}

	return -1;
}

} // end of namespace project_euler